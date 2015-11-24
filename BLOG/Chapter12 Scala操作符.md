## 1. 标识符
+ 变量名、函数名、类名等统称为**标识符**，scala可以使用任何字符来作标识符，比如  `（）！#%&×+-/:<>=?@\^|~`  等。

+ **反引号**中可以使用任何字符序列。
```
	val √ = scala.math.sqrt _
	√(2)
	val `val` = 42
	println(`val`)
```


----------
## 2. 中置操作符
+ 操作符要接两个参数，分别位于操作符两边。

+ `a 标识符 b`  等价于  `a.标识符(b)`  。
```
	1 to 10
	等价于 1.to(10)
	
	1 -> 10
	等价于 1 .->(10) 
```


----------
## 3. 一元操作符
+ 只有一个参数的操作符成为**一元操作符**，操作符的位置可能位于参数的前或后，所有有下面两种情况。

+ `a 标识符`  等价于  `a.标识符()`  ，`标识符 a`  等价于  `a.unary_标识符`  。
```
	1 toString
	等价于 1.toString()
	
	val a = 42
	-a
	等价于 a.unary_-
```


----------
## 4. 赋值操作符
+ 赋值操作符的形式为  `操作符=`，表达式是  `a 操作符= b`  ，等价于  `a = a 操作符 b`  。
```
	a += 1
	等价于 a = a + 1
```

+ `<=、>=、!=、==、===、=/=`  等不是赋值操作符，


----------
## 5. 优先级
+ 后置操作符优先级**低于**中置操作符，`a 中置操作符 b 后置操作符`  等价于  `(a 中置操作符 b) 后置操作符`  。

+ 符号优先级如下表所示：

	|操作符|优先级|
	|:--:|:--:|
	|除下面字符以外的操作符|1(最高)|
	|\*  /  %|2|
	|\+  -|3|
	|:  |4|
	|<  >|5|
	|!=|6|
	|&|7|
	|^|8|
	|\\||9|
	|赋值操作符|10(最低)|

----------
## 6. 结合性
+ Scala除**冒号操作符**和**赋值操作符**是**右结合**，所有其他操作符都是**左结合**。
```
	// 构造列表List
	1 :: 2 :: Nil   // :: 右结合
	1 :: (2 :: Nil)
	(1 :: 2) :: Nil // 错误
```

+ 右结合的的第二个参数就是方法，比如  `2::Nil`  等价于  `Nil.::(2)`。


----------
## 7. apply和update方法
+ 函数或方法位于**赋值语句的等号左侧**，调用的是**update方法**，否则调用的**apply方法**。
```
	val scores = new scala.collection.mutable.HashMap[String, Int]
	scores("Bob") = 100 
	等价于调用：scores.update("Bob", 100) 
	
	val bobsScore = scores("Bob")
	等价于调用：scores.apply("Bob")
```


----------
## 8. 提取器unapply
+ **提取器：**是一个带有unapply方法的*对象*，可以当做是伴生对象apply的方法的反操作。

+ unapply接受一个**对象**，从中提取值。
```
	class Fraction(n: Int, d: Int) {
	  private val num: Int = if (d == 0) 1 else n;
	  private val den: Int = if (d == 0) 0 else d;
	  def *(other: Fraction) = new Fraction(num * other.num, den * other.den)
	}
	
	// unapply返回的就是构造该对象的两个值
	object Fraction {
	  def apply(n: Int, d: Int) = new Fraction(n, d)
	  def unapply(input: Fraction) =
	    if (input.den == 0) None else Some((input.num, input.den))
	}
	
	object Main extends App {  
	  var Fraction(a, b) = Fraction(3, 4) * Fraction(2, 5)
	  println(a)
	  println(b)
	}
```

+ 每个样例类都会自动具备apply方法和unapply方法，样例类后面章节会讲解，这里只要了解就可以。

+ 提取器可以**只测试输入**而不真正将其值提取出来，只返回一个Boolean。

----------
## 9. unapplySeq方法
+ 使用unapplySeq方法可以提取**任意长度的值序列**，它返回一个**Option[Seq[A]]**，A是**被提取的类型**。


----------
【待续】

