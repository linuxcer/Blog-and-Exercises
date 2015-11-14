## 1. 条件表达式

	
+ Scala表达式中**if/else有值**。
		
		if (x > 0) 1 else -1
		
		等同于C++中：x>0 ? 1 : -1

+ else 部分缺失，引入`Unit类`，写成()，不带else的语句等同于：
		
		if (x > 0) 1 else ()

	这里Unit相当于C++中void。
			
+ Scala没有switch语句。

+ 在REPL（Read-Eval-Print Loop）中输入代码块，可以键入`:paste`，然后按`Ctrl+D`结束。

----------


## 2. 语句终止

+ Scala语言中**行尾不需要分号**，只要上下文能明确判断出终止即可。

+ 要想在单行中写多个语句，就需要分号隔开。（不推荐使用）
   
		if(n > 0) {r += 1; n += 1}

+ 较长语句以不能用做语句结尾的符号结尾。
   
		s = 4 + 3 * s0 - 8 +        //这里的+号就告诉编译器，这不是行结尾
		     0.5 * 4.3 -2.3


----------


## 3. 块表达式和赋值

+ `{}`块包含一系列表达式，**块的值**就是最后一个表达式的值。

+ 赋值语句块的值返回的是`Unit类型`，写做`()`。
   
		x = y = 2   //不要这么做，y=2返回的是一个Unit类型


----------


## 4. 输入和输出

+ `print`和`println`不同之处是，`println`多输出一个**换行符**。还有一个带有C风格格式化的`printf`。

+ `readLine`从控制台读入一行（**唯一**可以**带一个参数**作为提示符字符串），readInt、readDouble、readBoolean、readChar、readLong、readByte等都是用于输入。


----------


## 5. 循环

+ while和do循环与C++相同。

+ for循环结构如下。
``` SCALA
	//1 to n返回数字1到n的一个区间
	//让变量遍历<-右边的表达式所有值
	for(i <- 1 to n)
		r = r * i
```

+ 遍历字符串或数组时，用`until方法`，util方法返回一个并不包含上届的区间。

``` SCALA   
	val s = "Hello"
	var sum = 0
	for(i <- 0 until s.length)//i的最后一个值为s.length-1
	    sum += s(i)
	    
	//上面等价于下面
	for(ch <- "Hello") sum += ch
```

+ Scala没有提供break或continue

+ 如果要用break可以使用下面三种方法：
![break方法](http://img.blog.csdn.net/20151103200541008)
   


----------


## 6. 高级for循环和for推导式

+ for可以提供多个生成器，用分号隔开。

``` SCALA
    for(i <- 1 to 3; j <- 1 to 3)
        print(((i * 10) + j) + " ")
```

+ 每个生成器可以带一个**守卫**，以if开头的Boolean表达式。（**if前没有分号**）

``` SCALA
    for(i <- 1 to 3; j <- 1 to 3 if i != j)
        print(((i * 10) + j) + " ")
```

+ for循环中可以使用变量。

+ for推导式：for循环体以`yeild`开始，会构造一个集合，每次迭代生成集合中的一个值。

``` SCALA
    for(i <- 1 to 3)
        i % 3//最后生成Vector(1,2,0,1,2,0,1,2,0,1)
```

+ for推导式生成的集合与第一个生成式的类型兼容。


----------


## 7. 函数

+ 基本函数定义如下。

``` SCALA
    def fac(n : Int) = {//等号右边表达式的类型推出函数返回类型
        var r = 1
        for (i <- 1 to n) r = r * i
        r//可以用return，但不常见
    }
```

+ **函数不是递归的，就不需要指定返回值**。对于递归函数，必须指明返回类型。

``` SCALA
    def fac(n : Int) : Int= {//等号右边表达式的类型推出函数返回类型
        if (n <= 0)
            1
        else
            n * fac(n - 1)
    }
```


----------


## 8. 默认参数和带名参数

+ 定义如下：

``` SCALA
    def f(str: String, left: String = "[", right: String = "]") = {
        left + str + right
    }
```

+ 调用

		f("Hello", right = "}") // 这里混合使用了未带名参数和带名参数


----------


## 9. 变长参数

+ 定义如下：

``` SCALA
	def sum(args: Int*) = {
	    var result = 0
	    for (arg <- args)
	        result += arg
	    result
```

+ 调用

``` SCALA
	val s = sum(1, 3, 8, 9)
	val s = sum(1 to 5: _*)//要使用一个值得序列，把1 to 5当成一个序列必须追加：_*
```


----------


## 10. 过程

+ 定义：有的函数不返回值，只需要去掉花括号前面的=号，它的返回类型是**Unit**。
	
``` SCALA
	def box(s: String) {
		println("hello world" + s "\n")
	}
	等价于：
	def box(s: String): Unit = {
		println("hello world" + s "\n")
	}
```


----------


## 11. 懒值

+ 当val被声明为`lazy`时，它的**初始化将被推迟**，直到我们首次取值。

		lazy val words = "hello scala"


----------


## 12. 异常

+ Scala异常工作机制跟Java和C++一样，抛出异常时，比如（throw表示式的类型为Nothing）。


		throw new IllegalArgumentException("x should not be negative")


+ 在if/else中，如果一个分支是Nothing类型，则if/else表达式的类型就是另一个分支的类型。

+ 异常捕获用`try/catch`或`try/finally`或`try/catch/finally`。


----------


【待续】









