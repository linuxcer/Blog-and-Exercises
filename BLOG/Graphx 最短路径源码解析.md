## 1. 最短路径测试代码
下面主要是对Spark图计算框架GraphX中的单源点最短路径的源码进行解析。

```
	test("shortPaths") {
		// 测试的真实结果，后面用于对比
		val shortestPaths = Set(
		(1, Map(1 -> 0, 4 -> 2)), (2, Map(1 -> 1, 4 -> 2)), (3, Map(1 -> 2, 4 -> 1)),
		(4, Map(1 -> 2, 4 -> 0)), (5, Map(1 -> 1, 4 -> 1)), (6, Map(1 -> 3, 4 -> 1)))

		// 构造有向图的边序列
		val edgeSeq = Seq((1, 2), (1, 5), (2, 3), (2, 5), (3, 4), (4, 5), (4, 6)).flatMap {
			case e => Seq(e, e.swap)
		}

		// 构造有向图
		val edges = sc.parallelize(edgeSeq).map { case (v1, v2) => (v1.toLong, v2.toLong) }
		val graph = Graph.fromEdgeTuples(edges, 1)

		// 要求最短路径的点集合
		val landmarks = Seq(1, 4).map(_.toLong)

		// 计算最短路径
		val results = ShortestPaths.run(graph, landmarks).vertices.collect.map {
		case (v, spMap) => (v, spMap.mapValues(i => i))
		}
		
		// 与真实结果对比
		assert(results.toSet === shortestPaths)
	}
```


----------


## 2. Graphx底层实现代码
``` scala
	package org.apache.spark.graphx.lib
	
	import org.apache.spark.graphx._
	import scala.reflect.ClassTag
	
	object ShortestPaths {
		// 定义一个Map[VertexId,Int]类型的Map函数，别名为SPMap，函数的属性Key为VertexId类型，
		// 其实也就是scala中的Long类型，它在图中的别名是VertexId，还有Int类型的路径的长度。
		type SPMap = Map[VertexId, Int]
		
		// 初始化图的属性信息
		private def makeMap(x: (VertexId, Int)*) = Map(x: _*)
		
		// 主要用于将自身的属性值（即源顶点属性值）中路径的长度加1（这里说明该最短路径模型只能应用与非带权图，即权值都相等的图），然后和目标定点的属性值比较
		private def incrementMap(spmap: SPMap): SPMap = spmap.map { case (v, d) => v -> (d + 1) }
		
		// 比较源顶点属性和发送信息过来顶点的属性取最小值。
		private def addMaps(spmap1: SPMap, spmap2: SPMap): SPMap =
		// 先将两个集合spmap1和spma2的顶点整合要一起，这里用了一个++来处理
		// 再形成一个新的k->v的map
		// 其中v是两个消息中值最小的一个
		(spmap1.keySet ++ spmap2.keySet).map {
			k => k -> math.min(spmap1.getOrElse(k, Int.MaxValue), spmap2.getOrElse(k, Int.MaxValue))
		}.toMap
		
		// 计算给定了起始和终点序列的最短路径
		// ED是边的属性值，计算过程中不会被使用
		// graph是要计算最短路径的图
		// landmarks是要求最短路径顶点id的集合，最短路径会计算每一个landmark
		// 返回的是一个图，每个顶点的属性就是landmark点间的最短路径
		def run[VD, ED: ClassTag](graph: Graph[VD, ED], landmarks: Seq[VertexId]): Graph[SPMap, ED] = {
		val spGraph = graph.mapVertices { (vid, attr) =>
		// 如果landmark只有一个点1
		// 将landmarks中的顶点初始化为Map(1-> 0),即自身到自身的距离为0，其余的顶点属性初始化为Map()。
		if (landmarks.contains(vid)) makeMap(vid -> 0) else makeMap()
		}
		
		// 定义一个initMessage它的值为Map()
		// 作用是在Pregel第一次运行的时候，所有图中的顶点都会接收到initMessage。
		val initialMessage = makeMap()
		
		// 用户定义的顶点程序运行在每一个顶点中，负责接收进来的信息，和计算新的顶点值。
		// 在第一次迭代的时候，所有的顶点程序将会被默认的defaultMessage调用，在次轮迭代中，顶点程序只有接收到message才会被调用。
		def vertexProgram(id: VertexId, attr: SPMap, msg: SPMap): SPMap = {
			addMaps(attr, msg)
		}
		

		// 该函数应用于邻居顶点在当前迭代中接收message
		// 一旦收到通知，相对于发送该消息的点，就是目的节点，相对于收到消息的点就是源节点
		// 这个地方从源节点考虑
		def sendMessage(edge: EdgeTriplet[SPMap, _]): Iterator[(VertexId, SPMap)] = {
		// 对所有目的节点值加1
		
		val newAttr = incrementMap(edge.dstAttr)
		// 求得最短路径，将源节点的值发送给所有所有的源节点，其实这里源节点就是相邻点的意思，换成目的节点应该也是可以的
		if (edge.srcAttr != addMaps(newAttr, edge.srcAttr)) Iterator((edge.srcId, newAttr))
		else Iterator.empty
		}
		
		// 调用pregel函数
		// 第一个参数列表包含配置参数初始消息、最大迭代数、发送消息的边的方向（默认是沿边方向出）
		// 第二个参数列表包含用户 自定义的函数用来接收消息（vprog）、计算消息（sendMsg）、合并消息（mergeMsg）
		Pregel(spGraph, initialMessage)(vertexProgram, sendMessage, addMaps)
		}
	}

```
GraphX最短路径求解中使用了Pregel模型，这是一个非常高效的图计算模型。但目前最短路径有如下限制：


1. 只能用于非带权图（权值相等）；
2. 利用的算法是迪杰斯特拉求解最短路径。


----------



相关讨论：[\[1\]][1]、[\[2\]][2]、[\[3\]][3]、[\[4\]][4]


----------


【完】
[1]: http://www.zhihu.com/question/20010259
[2]: http://zdglf.com/?p=1313
[3]: http://blog.csdn.net/shangwen_/article/details/38479835
[4]: http://www.jeepshoe.org/44261921.htm