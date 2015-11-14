## 1. 扩展类
+ 扩展的方法是使用`extends`关键字
```
	class Person {
	  var name = ""
	}
	
	class Employee extends Person {
	  var salary = 0.0
	  def description = "An employee with name " + name + " and salary " + salary
	}
	
	object Main extends App {
	  val fred = new Employee
	  fred.name = "Fred"
	  fred.salary = 50000
	  println(fred.description)
	}
```

+ 在类、方法或字段前加`final`关键字，这样类或方法就不会被扩展或重写。


----------
## 2. 重写方法
+ Scala重写一个**非抽象方法**，必须用`override`修饰符。
```
	class Person {
	  var name = ""
	  override def toString = getClass.getName + "[name=" + name + "]"
	}
	
	class Employee extends Person {
	  var salary = 0.0
	  override def toString = super.toString + "[salary=" + salary + "]"
	}
	
	object Main extends App {
	  val fred = new Employee
	  fred.name = "Fred"
	  fred.salary = 50000
	  println(fred)
	}
```

+ 调用超类（父类），使用`super`关键字。


----------
## 3. 类型检查和转换
+ `isInstanceOf`方法，测试某个对象是否属于某个给定类。

+ `asinstancdOf`方法，将引用转换为子类的引用。

+   `classOf`测试p是Employee对象但又不是子类。
```
	class Person {
	  var name = ""
	  override def toString = getClass.getName + "[name=" + name + "]"
	}
	
	class Employee extends Person {
	  var salary = 0.0
	  override def toString = super.toString + "[salary=" + salary + "]"
	}
	
	class Manager extends Employee
	
	object Main extends App {
	  val r = scala.math.random
	  val p = if (r < 0.33) new Person 
	    else if (r < 0.67) new Employee 
	    else new Manager  
	  if (p.isInstanceOf[Employee]) {     
	    val s = p.asInstanceOf[Employee] // s has type Employee
	    println("It's an employee.")
	    s.salary = 50000
	    if (p.getClass == classOf[Manager]) {
	      println("Actually, it's a manager")
	      s.salary *= 2
	    }
	  }
	  println(p)
	}
```


----------
## 4. 受保护字段和方法
+ 将**字段或方法**声明为`protected`，这样的成员可以被任意子类访问，但不能从其他位置看到。

+ protected的成员对类所属的包是不可见的。

+ `protected[this]`将访问权限限定在当前对象。


----------
## 5. 超类的构造
+ 只有**主构造器**可以调用**超类的构造器**。
```
	class Person(val name: String, val age: Int) {
	  override def toString = getClass.getName + "[name=" + name +
	    ",age=" + age + "]"
	}
	
	class Employee(name: String, age: Int, val salary : Double) extends
	  Person(name, age) {
	  override def toString = super.toString + "[salary=" + salary + "]"
	}
	
	new Employee("Fred", 42, 50000)
```


----------
## 6. 重写字段
+ **重写有如下限制：**

1. def只重写另一个def。
2. val只能重写另一个val或不带参数的def。
3. var只能重写另一个抽象的var。

	![重写val/def/var](http://img.blog.csdn.net/20151107080827794)

```
	class Person(val name: String) {
	  override def toString = getClass.getName + "[name=" + name + "]"
	}
	
	class SecretAgent(codename: String) extends Person(codename) {
	  override val name = "secret" // 不暴露真名
	  override val toString = "secret" // ...或类名
	}
	
	val fred = new Person("Fred")
	fred.name
	val james = new SecretAgent("007")
	james.name
	
	// 用val重写抽象类的def
	abstract class Person {  
	  def id: Int    
	}
	
	class Student(override val id: Int) extends Person
	
	class SecretAgent extends Person {
	  override val id = scala.util.Random.nextInt
	}
	
	val fred = new Student(1729)
	fred.id
	val james = new SecretAgent
	james.id
```


----------
## 7. 匿名子类
+ 通过包含`带有定义或重写的`**代码块**的方法创建一个匿名的子类。

+ 匿名类作为参数的定义类型为：`Person{def greeting:String}`。

```
	class Person(val name: String) {
	  override def toString = getClass.getName + "[name=" + name + "]"
	}
	
	val alien = new Person("Fred") {
	  def greeting = "Greetings, Earthling! My name is Fred."
	}
	
	def meet(p: Person{def greeting: String}) {
	  println(p.name + " says: " + p.greeting)
	}
	
	meet(alien)
```


----------
## 8. 抽象类
+ `abstract`关键字标记不能被**实例化**的类，因为它的某个或几个方法没有被定义，这种没有方法体的方法是**抽象方法**。

+ 某个类存在抽象方法，则必须申明为`abstract`。有抽象方法以及下面将提到的抽象字段的存在才导致了抽象类的出现。

+ 子类中重写超类的抽象方法时，不需要使用`override`关键字。

```
	abstract class Person(val name: String) {
	  def id: Int // 没有方法体的方法是 抽象方法 
	}
	
	class Employee(name: String) extends Person(name) {
	  def id = name.hashCode // override 不需要
	}
	
	val fred = new Employee("Fred")
	fred.id
```


----------
## 9. 抽象字段
+ **抽象字段：**没有初始值的字段。

```
	abstract class Person {
	  val id: Int      // 没有初始化，带有抽象getter方法的抽象字段
	  var name: String // 带有抽象getter和setter方法
	  override def toString = getClass.getName + "[id=" + id + ",name=" + name + "]"
	}
	
	class Employee(val id: Int) extends Person { // 子类具体的id
	  var name = "" 
	}
	
	val james = new Employee(7)
	
	val fred = new Person {
	  val id = 1729
	  var name = "Fred"
	}
```


----------
## 10. 构造顺序和提前定义
+ 问题来源：子类将父类方法重写后，父类构造时对应的方法失效，由子类来构造。如下例，实际构造完成后rannge的值为2。
```
	class Creature {
	  val range: Int = 10
	  val env: Array[Int] = new Array[Int](range)
	}
	
	class Ant extends Creature {
	  override val range = 2
	}
```

+ 有三种方法解决上述问题
1. 将val申明为final，安全但不灵活。

2. 将val申明为lazy，安全但不高效。

3. 子类中使用**提前定义**。

+ **提前定义：**在超类构造之前初始化子类val字段，将val字段放在extends关键字之后的一个块中，块中不能包含类中其他字段。并且超类前用`with`关键字。

```
	class Creature {
	  val range: Int = 10
	  val env: Array[Int] = new Array[Int](range)
	}
	
	class Ant extends Creature {
	  override val range = 2
	}
	
	class Bug extends {
	  override val range = 3
	} with Creature
```


----------
## 11. scala继承层级
+ 所有的Scala类都实现`ScalaObject`这个接口。

+ `Any`类是整个继承层级的根节点。

+ `Null`唯一实例是`null`值，**可赋值给任何引用，但不能赋值给值类型变量**。

+ `Unit`类型它的值是`()`，**可赋值给任何值变量**。

+ `Nothing`类型没有实例。

	![ scala继承层级](http://img.blog.csdn.net/20151107091435304)


----------
【待续】

