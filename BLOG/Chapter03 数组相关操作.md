
## 1. 定长数组

+ Scala定义用到**Array**，定义如下。
```
	val nums = new Array[Int](10)   // 10个整数数组，初始化为0，String初始化为null
	val s = Array("hello", "world") // 已经提供初始值就不需要new
	s(0)                            // 调用时用的是()而不是[]
```


----------


## 2. 变长数组：数组缓冲

+ 变长数组用到**ArrayBuffer**。

```
	import scala.collection.mutable.ArrayBuffer// 头文件
	val b = ArrayBuffer[Int]()                 // 一个空数组缓冲
	b += 1                                     // 在尾端添加元素
	b += (1, 2, 3, 4)                          // 在尾端添加多个元素
	b ++= Array(7, 9, 8)                       // ++=可以追加任何一个集合
	b.trimEnd(3)                               // 移除最后3个元素
	b.insert(2, 5)                             // 下标2之前插入5
	b.insert(2, 4, 5, 8)                       // 下标2之前插入多个数
	b.remove(2)                                // 将2号下标移除
	b.remove(2, 3)                             // 从2号下标开始移除3个元素
	b.toArray                                  // 把b从ArrayBuffer转成Array
	b.toBuffer                                 // 把b从Array转成ArrayBuffer
```


----------


## 3. 遍历数组和数组缓冲

+ 用for循环，until返回所有小于（不包括）上限的数字。
```
	for (i <- 0 until b.length)
	{
	    println(i + ": " + b(i)) // i是从0到b.length-1
	}
```

+ 也可以不用下标，直接访问数组。
```
	for (i <- b)
	{
		println(i) // i就是数组中存的每个量
	}
```        

+ 每两个数字一跳，i的遍历如下。
```
	0 until (b.lenght, 2)
```

+ 从数组尾部开始，i的遍历如下。
```
	(0 until b.lenght).reverse
```


----------


## 4. 数组转换

+ 转换不改变元数组，产生一个新数组。用for(...)yield来进行数组转换。
```
	val result = for (elem <- b if elem % 2 == 0) yield 2 * elem // 去掉奇数元素，对偶数元素翻倍
	
	// 另外一种做法如下：
	b.filter(_ % 2 == 0).map(2 * _)
	
	// 或者
	b.filter { _ % 2 == 0} map { 2 * _ }
```


----------


## 5. 常用算法

+ 常用算法如下：
```
	Array(1, 4, 8).sum      // 直接求和，对ArrayBuffer也一样，还有max，min
	val a = b.sorted        // b没有改变，将排序好的结果赋值给a
	val c = b.sortWith(_>_) // 通过sortWith函数将b降序排列
```

+ 可直接对Array排序，但不能对ArrayBuffer排序。
``` 
	val a = Array(9, 3, 1)
	scala.util.Sorting.quickSort(a) // a现在是Array(1, 3, 9)
```

+ 显示Array或ArrayBuffer内容，可以用**mkString**，可以指定分隔符，及前后缀。
```
	a.mkString(" and ")
	//"1 and 3 and 9"
	a.mkString("<", ",", ">")
	//"<1,3,9>
```


----------


## 6. 多维数组

+ 用**ofDim**方法构造二维数组。
```
	val m = Array.ofDim[Double](3, 4) // 三行，四列
	m(row)(colum) = 2                 // 元素访问
```


----------
【待续】

