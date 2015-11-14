

## 1. 构造映射

+ 映射是键值对偶的集合，映射只做查询。

+ 构造一个不可变的Map[String, Int]。
```
	val scores = Map("Alice" -> 10, "Aaron" -> 20, "Bob" -> 13) // 这两种方法等价
	val scores = Map(("Alice", 10), ("Aaron", 20), ("Bob", 13))     
```

+ 构造一个可变的映射。
```
	val scores = scala.collection.mutable.Map("Alice" -> 10, "Aaron" -> 20, "Bob" -> 13)
```

+ 构造一个空的映射。
```
	// chapter01 中提到如果没有初始化是要用new函数的
	val scores = new scala.collection.mutable.HashMap[String, Int]
```


----------


## 2. 获取映射中的值

+ 若映射不包含请求中使用的键，要检查有某个键要用**contains**方法，组合语句是**getOrElse**。
```
	val Bobscore = scores("Bob")    // 获取“Bob"对应的值
	val bobsocre = if (scores.contains("BoB")) scores("Bob") else 0
	val bobsocre = scores.getOrElse("Bob", 0) // 与上面的第二条语句等价
```


----------


## 3. 更新键中的值

+ 映射可变
```
	socres("Bob") = 10   // 更新键“Bob”值
	scores("Fred") = 7   // 添加新键值对
	scores += ("Bob" -> 10, "Fred" -> 7) // +=可以添加多个
	socres -= "Alice"    // 移除某个键值对
```

+ 若映射是不可变的，可以用同样的方法获取一个包含所需要的更新的新映射。
```
	val newScores = scores + ("Bob" -> , "Fred" -> 7)
```

+ 还可以将scores定义为var直接更新var变量。
```
	var scores = Map("Alice" -> 10, "Aaron" -> 20, "Bob" -> 13)
	scores = scores + ("Bob" -> 13, "Fred" -> 7)
	scores = scores - "Alice"   // 移除某个键值对
```        


----------


## 4. 迭代映射

+ 用`for ((k, v) <- 映射)`就可以遍历所有键值对。若只需访问键或值，用`values`和`keySet`方法。
```
	for ((k, v) <- scores) println(k + v)
	for (k <- scores.keySet) println(k)
	for (v <- scores.values) println(v)
```


----------

## 5. 已排序映射
+ 要的的一个不可变的树形映射而不是默认的哈希映射的话，可以用：
```
	val scores = scala.collection.immutable.SortedMap("Alice" -> 10, "Aaron" -> 20, "Bob" -> 13)
```

+ scala中可变的树形映射还没有

## 6. 元组

+ 元组(tuple `['tjup(ə)l]`)是**不同类型的值的聚集**，映射是键值**对偶**的集合，**对偶是元组的最简单形态**。

+ 访问元组的组元，用`_1、_2、_3`方法，元组下表是从**1**开始。
```
	val t = (1, 2.2323, "Bob")
	val second = t._2
	val second = t _2//点也可以用空格来表示
```

+ 用模式匹配来获取元组的组元，不需要的组元用`_`表示。
```
	val (first, second, third) = t
	val (first, second, _) = t
```

+ 元组可用于**函数返回多个值**得情况。


----------


## 7. 拉链操作

+ 元组就是把多个值绑定在一起，可以用`zip`操作，`toMap`方法将对偶转成映射。
```
	val name = Array("Bob", "Fred")
	val scores = Array(2, 4)
	val pairs = name.zip(counts) // 得到元组
	val score = pairs.toMap      // 转成映射（哈希表）
```


----------
【待续】

