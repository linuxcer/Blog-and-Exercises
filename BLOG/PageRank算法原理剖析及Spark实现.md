## 1. 什么是PageRank

PageRank对**网页排名的算法**，曾是Google发家致富的法宝。PageRank算法计算每一个网页的PageRank值，然后根据这个值的大小对网页的重要性进行排序。


----------

## 2. 简单PageRank算法

首先，将Web做如下抽象：

+ 将每个网页抽象成一个**节点**；
+ 如果一个页面$A$有链接直接链向$B$，则存在一条有向边从$A$到$B$（多个相同链接不重复计算边）。

因此，整个Web被抽象为一张**有向图**。现在假设世界上只有四张网页：$A、B、C、D$，其抽象结构如下图：
<center>![简单PageRank计算](http://img.blog.csdn.net/20151210153703373)</center>

显然这个图是**强连通的**（从任一节点出发都可以到达另外任何一个节点）。然后需要用一种合适的数据结构表示页面间的连接关系。

**PageRank算法基本思想描述**：被用户访问越多的网页更可能质量越高，而用户在浏览网页时主要通过超链接进行页面跳转，因此需要通过分析超链接组成的拓扑结构来推算每个网页被访问频率的高低。最简单的，我们可以假设当一个用户停留在某页面时，跳转到页面上每个被链页面的**概率相同**。

例如，上图中$A$页面链向$B、C、D$，所以一个用户从$A$跳转到$B、C、D$的概率各为$1/3$。设一共有N个网页，则可以组织这样一个**N维矩阵**，其中**第$i$行$j$列的值表示用户从页面$j$转到页面$i$的概率**。这样一个矩阵叫做**转移矩阵（Transition Matrix）**。下面是上图的转移矩阵$M$：
$$
 M = 
 \left[
 \begin{matrix}
   0 & 1/2 & 0 & 1/2\\
   1/3 & 0 & 0 & 1/2\\
   1/3 & 1/2 & 0 & 0\\
   1/3 & 0 & 1 & 0
  \end{matrix}
  \right] \tag{1}
$$


设初始时每个页面的$rank$值为$1/N$，这里就是$1/4$。按$A-D$顺序得到向量$v$：
$$
v = 
\left[
\begin{matrix}
1/4 \\ 1/4 \\ 1/4 \\ 1/4 
\end{matrix}
\right]\tag{2}
$$


> **注意：**$M$第一行分别是$A、B、C$和$D$转移到页面$A$的概率，而$v$的第一列分别是$A、B、C$和$D$当前的$rank$，因此用$M$的第一行乘以$v$的第一列，所得结果就是页面A最新$rank$的合理估计，同理，$Mv$的结果就分别代表$A、B、C、D$新$rank$值。

$$
Mv = 
\left[
\begin{matrix}
1/4 \\ 5/24 \\ 5/25 \\ 1/4 
\end{matrix}
\right]\tag{3}
$$

然后用$M$再乘以这个新的$rank$向量，又会产生一个$rank$向量。**迭代**这个过程，可以证明$v$最终会**收敛**，即$v \approx Mv$，此时计算停止。最终的$v$就是各个页面的$pagerank$值。上面的向量经过几步迭代后，大约收敛在$（1/4, 1/4, 1/5, 1/4）$，这就是$A、B、C、D$最后的$pagerank$。


----------
## 3. 终止点问题
上面过程要满足收敛性，需要具备一个条件：**图是强连通的**，即从任意网页可以到达其他任意网页。

互联网中存在网页不满足强连通的特性，因为有一些网页不指向任何网页，按照上面公式迭代计算下去，导致前面累计得到的转移概率被清零，最终得到的概率分布向量**所有元素几乎都为0**。

假设把上面图中$C$到$D$的链接丢掉，$C$变成了一个终止点，得到下面这个图：
<center>![终止点问题](http://img.blog.csdn.net/20151210165135046)</center>

转移矩阵$M$为：
$$
 M = 
 \left[
 \begin{matrix}
   0 & 1/2 & 0 & 1/2\\
   1/3 & 0 & 0 & 1/2\\
   1/3 & 1/2 & 0 & 0\\
   1/3 & 0 & 0 & 0
  \end{matrix}
  \right] \tag{4}
$$

不断迭代，最终得到所有元素都为0。
$$
v = 
 \left[
 \begin{matrix}
   1/4 \\
   1/4 \\
   1/4 \\
   1/4
  \end{matrix}
  \right]  \rightarrow
 \left[
 \begin{matrix}
   1/4 \\
   5/24 \\
   5/24 \\
   1/12
  \end{matrix}
  \right] \rightarrow 
 \left[
 \begin{matrix}
   7/48 \\
   1/8 \\
   9/48 \\
   1/12
  \end{matrix}
  \right] \rightarrow 
   \left[
 \begin{matrix}
   5/48 \\
   13/144 \\
   1/9 \\
   7/144
  \end{matrix}
  \right] \rightarrow 
   \left[
 \begin{matrix}
   5/72 \\
   13/288 \\
   1/9 \\
   7/144
  \end{matrix}
  \right] ...
     \left[
 \begin{matrix}
   0 \\
   0 \\
   0 \\
   0
  \end{matrix}
  \right] 
\tag{5}
$$


----------
## 4. 陷阱问题
**陷阱问题**：是指有些网页不存在指向其他网页的链接，但存在指向自己的链接。比如下面这个图：
<center>![陷阱问题](http://img.blog.csdn.net/20151210172207356)</center>

这种情况下，PageRank算法不断迭代会导致概率分布值全部转移到$c$网页上，这使得其他网页的概率分布值为0，从而整个网页排名就失去了意义。如果按照上面图则对应的转移矩阵$M$为：　
$$
 M = 
 \left[
 \begin{matrix}
   0 & 1/2 & 0 & 1/2\\
   1/3 & 0 & 0 & 1/2\\
   1/3 & 1/2 & 1 & 0\\
   1/3 & 0 & 0 & 0
  \end{matrix}
  \right] \tag{6}
$$

不断迭代，最终得到如下结果：
$$
v = 
 \left[
 \begin{matrix}
   1/4 \\
   1/4 \\
   1/4 \\
   1/4
  \end{matrix}
  \right]  \rightarrow
 \left[
 \begin{matrix}
   1/4 \\
   5/24 \\
   11/24 \\
   1/12
  \end{matrix}
  \right] \rightarrow 
 \left[
 \begin{matrix}
   0 \\
   0 \\
   1 \\
   0
  \end{matrix}
  \right]
\tag{7}
$$


----------
## 5. 完整PageRank算法

**为了解决终止点问题和陷阱问题**，下面需要对算法进行改进。假设选取下一个跳转页面时，既不选**当前页面**，也不选**当前网页上的其他链接**，而是以一定概率跳转到其他不相关网页，那么上面两个问题就能得到很好的解决，这就是**完整PageRank算法思想**。



假设跳转到**当前页面**（包括当前页面上的链接）的概率为$a$，那么跳转到**其他页面**概率为$(1-a)$，进一步假设每个页面被访问的概率相同都是$1/n$，于是原来的迭代公式转化为：
$$
v' = \alpha Mv  + (1-\alpha)e   \tag{8}
$$

假设$\alpha$的值为0.15，现在计算有陷阱的网页的概率分布：
$$
\begin{eqnarray*}
 v' & = & \alpha Mv  + (1-\alpha)e \\
 & = & 0.15
 \left[
 \begin{matrix}
   0 & 1/2 & 0 & 1/2\\
   1/3 & 0 & 0 & 1/2\\
   1/3 & 1/2 & 1 & 0\\
   1/3 & 0 & 0 & 0
  \end{matrix}
  \right] 
 \left[
 \begin{matrix}
	1/4\\
	1/4\\
	1/4\\
	1/4
  \end{matrix}
  \right] 
  + 0.85
   \left[
 \begin{matrix}
	1/4\\
	1/4\\
	1/4\\
	1/4
  \end{matrix}
  \right] \\
  & = & \left[
 \begin{matrix}
	1/4\\
	39/160\\
	9/32\\
	9/40
  \end{matrix}
  \right] 
  \end{eqnarray*}
   \tag{9}
$$
 利用上面公式继续迭代下去，直到收敛，得到最终$rank$值。


----------

## 6. Spark实现RageRank
 这里简化初始值为1.0，$\alpha / N$设置为0.15，迭代次数参考《数学之美》中提到：“一般来讲，只要10次左右的迭代基本上就收敛了”，这里设置为10次。 
 
```
	// 生成网页边的关系
	val links = sc.parallelize(Array(('A',Array('D')),('B',Array('A')),
	   ('C',Array('A','B')),('D',Array('A','C'))),2).map(x => (x._1, x._2)).cache()
	
	// 初始化rank值，2表示分两个partition
	var ranks = sc.parallelize(Array(('A',1.0),('B',1.0),('C',1.0),('D',1.0)), 2)
	
	// 迭代10次
	for ( i <- 1 to 10){
	   val contribs = links.join(ranks, 2)
	   val flatMapRDD = contribs.flatMap {
		   case (url,(links,rank)) => links.map(dest => (dest, rank/links.size))
		}
	   val reduceByKeyRDD = flatMapRDD.reduceByKey(_ + _, 2)
	   ranks = reduceByKeyRDD.mapValues(0.15 + 0.85 * _)
	
	}

```
 
## 7. 参考
+ [维基百科](https://zh.wikipedia.org/wiki/PageRank)
+ [在线PageRank算法演示](https://bebffd479efdabe8c274b02b19ae9140ad412589.googledrive.com/host/0B2GQktu-wcTiaWw5OFVqT1k3bDA/)，[作者博客](http://www.nowherenearithaca.com/2013/04/explorating-googles-pagerank.html)，可能需要梯子，我用的[梯子](http://www.socksvpn.space)。


----------
【完】