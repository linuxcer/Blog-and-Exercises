##1. 泛型类
> **个人理解：**泛型实质就是类或方法在定义时没有给定具体参数类型，需要在编译或运行时自动推断出类型的一种方法。

+ 用**方括号**来定义类型参数，放在类名后面。下面就定义了一个带有两个类型参数T和S的类。
```
	class Pair[T, S](val first: T, val second: S) {
	  override def toString = "(" + first + "," + second + ")"
	}
```

+ **在类的定义中**，可以用类型参数类定义变量、方法参数，以及返回值类型。

+ 带有一个或多个**类型参数**的类是**泛型的**，Scala会从**构造参数**推断出实际类型，也可以自己指定类型。

```
	val p = new Pair(42, "String")
	
	val p2 = new Pair[Any, Any](42, "String")
```


----------
## 2. 泛型函数
+ 函数和方法也可以带类型参数，类型参数放在函数名或方法名后面。
```
	def getMiddle[T](a: Array[T]) = a(a.length / 2)
```


----------
## 3. 类型变量界定
> **个人理解：**使用类型参数定义了某个参数或变量之后，要使用某种类型的的方法，比如使用String类型的compareTo方法，但我们可能传进去的是一个Int类型，Int类型没有该方法，这时程序就会出错，下面就介绍如何解决这类问题。

+ 有时需要对类型变量进行限制，比如有个Pair类，该类中使用了compareTo方法，但我们并不知道first有这个方法。

```
	class Pair[T](val first: T, val second: T) {
	  def smaller = if (first.compareTo(second) < 0) first else second // Error
	}
```

+ 解决方法，添加一个**上界**`T <: Comparable[T]`。
```
	// 这里要求T必须是Comparable[T]的子类型。
	class Pair[T <: Comparable[T]](val first: T, val second: T) {
	  def smaller = if (first.compareTo(second) < 0) first else second
	}
```


+ 如果我们现在想要定义一个方法，用一个值替换上面定义Pair中的第一个值，如果Pair是不可变的，我们就需要返回新的Pair。这时候我们要引入**下界**来解决这个问题，下界用`[R >: T]`来表示。

```
	// 替换进来的类型必须是原类型的超类型
	// 比如现在有Pair[Student]，要用Person来替换第一个值，结果是Pair[Person]。
	class Pair[T](val first: T, val second: T) {
	  def replaceFirst[R >: T](newFirst: R) = new Pair(newFirst, second)
	}
```


----------
## 4. 视图界定
> **个人理解：**即使上面使用上界约束了传入的类型，我们在调用`Pair(1,4)`时，编译器还是会报Int不是Comparable[Int]子类的错误，其实我们有一个RichInt中实现了该方法，Int到RichInt可以通过隐式转换来完成。下面就是讲解如何用视图界定的方法解决该问题。

+ **视图界定**中使用`<%`关系表示T可以被隐式转换成Comparable[T]。
```
	class Pair[T <% Comparable[T]](val first: T, val second: T) {
	  def smaller = if (first.compareTo(second) < 0) first else second
	}
	
	// Ordered提供关系操作符
	class Pair[T <% Ordered[T]](val first: T, val second: T) {
	  def smaller = if (first < second) first else second
	}
```

+ 隐式转换将在后面一个Chapter中讲解，这里只要知道有这个概念就行。


----------
## 5. 上下文界定
> **个人理解：**其实上面视图界定还有一个问题，当你使用视图界定前必须知道有从T到V的隐式转换存在，要是没有呢，我们该怎么办？下面就介绍该小结内容”上下文界定“，它是如何解决次问题的。

+ 上下文界定的形式是：`T:M`，M是另一个泛型类，它要求必须存在一个类型为M[T]的**隐式值**，这里只要知道隐式值是用`implicit`定义就可以了，下节会详细讲解。
```
	class Pair[T : Ordering](val first: T, val second: T) {
	  def smaller(implicit ord: Ordering[T]) =
	    if (ord.compare(first, second) < 0) first else second
	}
```


----------
## 6. Manifest上下文界定
> **个人理解：**构造一个泛型数组，在Scala中需要我们将上下文界定的M指定为Manifest，这节其实是上下文界定的一个实际应用场景。

+ 要**实例化一个泛型的Array[T]**或者说是**构造一个泛型数组**，我们需要一个`Manifest[T]`对象。Manifest就是一个隐式参数，这里可以用上下文界定。
```
	def makePair[T : Manifest](first: T, second: T) = {
	  val r = new Array[T](2); r(0) = first; r(1) = second; r
	}
```

## 7. 多重界定
+ 类型变量可以同时有上界和下界：`T >: Lower <: Upper`

+ 不能同时有多个上界或多个下界，一个类型可以实现多个特质。
```
	T <: Comparable[T] with Serializable with Cloneable
```

+ 可以有多个视图界定：`T <% Comparable[T] <% String`

+ 可以有多个上下文界定：`T : Ordering : Manifest`


----------
## 8. 类型约束
> **个人理解：**该小节提出类型约束，主要是要掌握它的两种用途。

+ 类型约束有如下三种方式：
```
	T =:= U // 测试T是否等于U
	T <:< U // 测试T是否是U的子类
	T <%< U // 测试T是否被隐式转换为U
```

+ 使用约束，需要添加**隐式类型证明参数**。
```
	  class Pair[T](val first: T, val second: T)(implicit ev: T <:< Comparable[T]) = // 使用约束
```

+ 上面的类型约束的使用并没有比类型界定带来更多优点，类型约束主要用在以下两种场景。

+ 类型约束让你可以在泛型类中定义**只能在特定条件下使用的方法**。
```
	// 即使File不是带先后顺序的，这里还是可以构造出Pair[File]
	// 只是当你调用smaller方法时，才会报错
	class Pair[T](val first: T, val second: T) {
	  def smaller(implicit ev: T <:< Ordered[T]) = // 使用约束
	    if (first < second) first else second
	}
```

+ 类型约束的另一个用途是**改进类型推断**。
```
	// 下面调用第二条语句会得到推断的类型参数是[Nothing, List[Int]]不符合[A, C <: Iterable[A]]
	// 因为单凭List(1, 2, 3)是无法推断出A是什么，因为它们是在同一个步骤中匹配A和C的。
	
	def firstLast[A, C <: Iterable[A]](it: C) = (it.head, it.last)
	firstLast(List(1, 2, 3)) // 出错
```

+ 解决办法是，先匹配C，在匹配A。
```
	def firstLast[A, C](it: C)(implicit ev: C <:< Iterable[A]) =
	  (it.head, it.last)
	firstLast(List(1, 2, 3)) // 成功
```


----------
## 9. 型变
> **个人理解：**如果只是看书本，这小结还是挺不容易看明白的。其实，仔细分析下，协变和逆变还是很好理解的。***如果将父类作为函数参数，想子类作为参数也可以调用，这就是协变；如果将子类作为函数参数，想父类作为参数也可以调用，这就是逆变。***这段话如果没看明白，先看下面具体例子，看完后再回来看这段话。

+ 假设有函数定义`def makeFriends(p: Pair[Person])`，并且Student是Person的子类，如果使用Pair[Student]作为参数去调用makeFriends函数，程序会报错。要想实现这种方式的调用，需要把Pair定义修改如下：

```
	class Pair[+T](val first: T, val second: T)
```

+ `+T`**（协变）**表示某个泛型类的**子类型关系**和参数T方向一致。

+ 下面讲解第二种型变方式**逆变**。
```
	trait Friend[-T] { // -T表示逆变
	  def befriend(someone: T)
	}
	
	class Person(name: String) extends Friend[Person] {
	  def befriend(someone: Person) {
	      this + " and " + someone + " are now friends."
	  }
	}
	
	// Student是Person子类
	class Student(name: String) extends Person(name)
	
	// 需要注意该函数定义的传入参数是子类类型
	def makeFriendWith(s: Student, f: Friend[Student]) { f.befriend(s) }
	
	val susan = new Student("Susan")
	val fred = new Person("Fred")
	// 可以调用
	makeFriendWith(susan, fred) 
```

+ `-T`**（逆变）**表示某个泛型类的**父类型关系**和参数T方向一致，刚好与协变相反。

----------
## 10. 协变和逆变点
+ 函数在参数上是逆变的，返回值上是协变的。**逆变**适应于表示**输入类型参数**，**协变**适应于表示**输出类型参数**。

+ Scala中数组类型是不支持型变的，因为它作为输入和输出类型要保持不变。

+ **参数的位置是逆变点，返回值类型的位置是协变点**，在函数的参数中，型变是反过来的，它的参数是协变的。
```
	foldLeft[B](z: B)(op: (B, A) => B): B
	               -       +  +     -   +
```


----------
## 11. 对象不能泛型
+ 不能将参数化类型添加到对象。
```
	abstract class List[+T] {
	  def isEmpty: Boolean
	  def head: T
	  def tail: List[T]
	}

	// 对象不能写成 object Empty[T] extends List[T] 
	// 类可以使用 class Empty[T] extends List[T] 	
	// 这里可以使用Nothing，前面说过Nothing是所有类型的子类型。
	object Empty extends List[Nothing] {
	  def isEmpty = true
	  def head = throw new UnsupportedOperationException
	  def tail = throw new UnsupportedOperationException
	}
```

----------
## 12. 类型通配符
+ Scala中类型可以使用通配符。
```
	def process(people: java.util.List[_ <: Person]
```

----------
【待续】