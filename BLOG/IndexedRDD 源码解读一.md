## 1. IndexedRDDPartion构建过程
+ 调用构建函数
```
	val vp = IndexedRDDPartition(Iterator((0L, 1), (1L, 1)))
```

+ 这里会调用IndexedRDDPartition 的apply 方法。

``` 
	def apply[V: ClassTag](iter: Iterator[(Id, V)]): IndexedRDDPartition[V] = {	
		// 申请PrimitiveKeyOpenHashMap的hash表	
		val map = new PrimitiveKeyOpenHashMap[Id, V]
		
		// 将iter数据写入hash表中
		iter.foreach { pair =>
			map(pair._1) = pair._2
	}
	
	// new一个新的IndexedRDDPartition对象作为返回值
	// 3个参数依次对应：index、values、mask
	new IndexedRDDPartition(
		ImmutableLongOpenHashSet.fromLongOpenHashSet(map.keySet), // index
		ImmutableVector.fromArray(map.values),                    // values
		map.keySet.getBitSet.toImmutableBitSet)                   // mask
	}
```


----------


## 2. index构建过程
+ index 构建函数调用
```
	// 这里实际是调用ImmutableLongOpenHashSet的fromLongOpenHashSet方法
	ImmutableLongOpenHashSet.fromLongOpenHashSet(map.keySet) // index
```

+ fromLongOpenHashSet 方法

``` JAVA
	def fromLongOpenHashSet(set: OpenHashSet[Long]): ImmutableLongOpenHashSet =
		new ImmutableLongOpenHashSet(
			ImmutableVector.fromArray(set.data), //调用fromArray方法将对应节点的值传进去
			set.getBitSet.toImmutableBitSet, 
			-1, 
			set.loadFactor)        // loadFactor默认值为0.7
```

## 3. fromArray方法
+ fromArray 方法定义

``` JAVA
	def fromArray[A: ClassTag](array: Array[A]): ImmutableVector[A] = {
		// 再掉3个参数的fromArray方法，0表示起点下标
		fromArray(array, 0, array.length)
	}
	
	def fromArray[A: ClassTag](array: Array[A], start: Int, end: Int): ImmutableVector[A] = {
		// new一个ImmuableVector对象
		// 该对象第一个参数是树的大小
		// 第二个参数是树的根节点
		new ImmutableVector(end - start, nodeFromArray(array, start, end))
	}
```

+ nodeFromArray 方法构建这棵树

``` JAVA
	private def nodeFromArray[A: ClassTag](array: Array[A], start: Int, end: Int): VectorNode[A] = {
		val length = end - start
		if (length == 0) {
			emptyNode
		} else {
			val depth = depthOf(length) // length个节点需要存储的树的高度，高度从0开始
			if (depth == 0) {           // 一层就可以存的下，一层大小为32，说明节点个数小于等于32，调用LeafNode构建这个存储
				new LeafNode(array.slice(start, end))
			} else {
				val shift = 5 * depth  // 左移的位数，从根节点出发
				val numChildren = ((length - 1) >> shift) + 1        // 获取根节点下子节点数目
				val children = new Array[VectorNode[A]](numChildren) // new一个类型为VectorNode[A]，长度为numChildren的数组
				
				var i = 0
				while (i < numChildren) {                        // 遍历子节点
					val childStart = start + (i << shift)        // 子节点起始点位置
					var childEnd = start + ((i + 1) << shift)    // 子节点终止点位置
					if (end < childEnd) {                        // 修正最后一个节点的终止点位置
						childEnd = end
					}
					children(i) = nodeFromArray(array, childStart, childEnd) // 递归调用 
					i += 1
				}
			
				// 程序返回值就是下面这个InternalNode
				// InternalNode是VectorNode的子类
				// 这里把子类递归返回给了父类，若直接返回children，children是一个Array类型的，不满足返回值的类型
				new InternalNode(children, depth)
			}
		}
	}  
```

+ leafNode 构建叶节点
```
	// 下面是一个主类构造器，构造器中有一个参数为Array[A]
	// 所以节点的最后一层存储的就是一个数组
	// 节点对外提供3个方法
	private class LeafNode[@specialized(Long, Int) A: ClassTag](
		children: Array[A])
		extends VectorNode[A] {
		
		require(children.length <= 32,
		s"nodes cannot have more than 32 children (got ${children.length})")
		
		override def apply(index: Int): A = children(index)
		
		override def updated(index: Int, elem: A) = {
			val newChildren = new Array[A](children.length)
			System.arraycopy(children, 0, newChildren, 0, children.length)
			newChildren(index) = elem
			new LeafNode(newChildren)
		}
		
		override def numChildren = children.length
	}
```

index 树的构建过程已经结束，下面介绍bitset 的构建。


----------


## 3. toImmutableBitSet方法
+ toImmutableBitSet方法定义

``` JAVA
	// numBits表示需要多少个二进制位来存储这些节点
	// numBits大小就是节点数目
	// words是二进制位转成long型的数组时的数值
	// words存储也是用树结构来完成的
	private[spark] def toImmutableBitSet: ImmutableBitSet = {
		new ImmutableBitSet(numBits, ImmutableVector.fromArray(words))
	}
```
  `ImmutableVector.fromArray(map.values)`  构建values 的树形结构时可参考fromArray的构建index的过程。

至此，indexedRDD中三棵树的存储结构已经构建起来。关于IndexedRDDPartition的操作源码分析，后面会继续更新。



----------
【待续】