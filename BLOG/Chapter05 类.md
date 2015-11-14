## 1. 简单的类和无参方法

+ 类的定义及调用方法。所有类都是**公有的**。
```
	class Counter {
		private var age = 0 // 必须初始化字段
		def incre() {       // 方法默认是公用的
		age += 1
	}
	def current() = age    // 可以不带()
	}
	//调用部分
	val myCounter = new Counter // 或new Counter()
	myCounter.incre()
	println(myCounter.current)  // 调用无参数方法()可以加上
```

+ **风格定义**：对于改值方法建议使用()，对于取值方法建议省略()，比如上面的current方法。


----------


## 2. 带getter和setter的属性

+ getter和setter被称为值得属性，可以在方法里定义取值和改值具体限制。

+ 在下面案例中`getter`和`setter`分别叫做`age`和`age_=`，如果下面定义的是私有变量，那么这两个方法也是私有的。公有字段的这两个方法是公有的。
```
	class Person {
		var age = 0
	}
```

+ 可以重新定义age和age_=，它们在调用时都是一样的，都是直接用age就可以了。
```
	class Counter {
	    private var Age = 0    // 必须初始化字段
	    def age_= (newAge: Int) {
	        if (newAge > Age)  // 保证值不能变小
	            Age = newAge
	        else
	            println("不能使值变小！")
	}
	val myCounter = new Counter
	myCounter.age = 10
	myCounter.age = 3
	println(myCounter.age)
```        

+ Scala对每个字段都生成getter和setter方法，这些字段要被定义为**var**，若字段是**val**，只有getter方法生产。
 
+ Scala中不能只写setter，不写getter。（会报错）


----------
## 3. 对象私有字段
```
	class Counter {
		private var value = 0
		def increament() {
			value += 1
		}
		// 可以访问另外一个对象的私有变量
		def isLess(other: Counter) = value < other.value
	}
```
+ 要想限制上面的这种访问对象私有变量，就必须将value定义成`private [this] var value = 0`，这种定义字段被成为**对象私有字段**，scala不会生成getter或setter方法。


----------
## 4. Bean 属性

+ JavaBeans规范中把属性定义为一对`getFoo/setFoo`方法。只要在scala字段标记@BeanProperty时，这样的方法会自动生成。
```
	import scala.reflect.BeanProperty
	class Person {
		@BeanProperty var name: String = _
	}
```
+ 字段生成方法：
![字段生成方法](http://img.blog.csdn.net/20151104171435724)


----------
## 5. 辅助构造器

+ scala中辅助构造器和Java中的构造函数对应。

+ 辅助构造器名称是**this**

+ 辅助构造器必须以一个先前以一个已经定义的**主构造器**或**其他辅助构造器**的调用开始。

```
	class Person {
		private var name = ""
		private var age = 0
		
		def this(name: String) {
			this() // 主构造器，没有显示定义就自动拥有一个无参主构造函数
			this.name = name
		}
	
		def this(name: String, age: Int) {
			this(name)
			this.age = age
		}
	}
```

+ 调用方法如下
```
	var p1 = new Person
	var p2 = new Person("Aaron")
	var p3 = new Person("Aaron", 23)
```

## 6. 主构造器
+ 每个类都有主构造器。

+ 主构造器的参数直接放置在类名之后，可以使用默认参数，如age。
```
	class Person(val name: String, val age: Int =0) {
		...
	}
```

+ 主构造器会执行类中的所有语句。

+ 如果类名后没有参数，则该类是一个**无名主构造器**。

+ 构造参数不带val或var，这样参数如何处理取决于它们在类中如何使用。

+ 主构造器参数生成的字段和方法：
![主构造器参数生成的字段和方法](http://img.blog.csdn.net/20151104171845844)


----------
## 7. 嵌套类
```
	import scala.collection.mutable.ArrayBuffer
	class Network {
		class Member(val name: String) {
			val contacts = new ArrayBuffer[Member]
		}
		private val members = new ArrayBuffer[Member]
	}
```


----------
【待续】