## 1. 单例对象

+ **scala中没有静态方法或静态变量**，可以使用object达到同样的目的。

```
	object Accounts {
	  private var lastNumber = 0
	  def newUniqueNumber() = { lastNumber += 1; lastNumber }
	}
```
+ 对象的构造器在该对象**第一次**被使用时调用。

+ scala对象可以用来实现：
	
> 1. 存放工具函数或常量
2. 共享单个不可变实例
3. 需要用单个实例协调某个服务


----------
## 2. 伴生对象
+ JAVA中会**既有实例方法又有静态方法的类**，Scala中用**类和与类同名的“伴生”对象**实现。

```
	class Account {
	  val id = Account.newUniqueNumber()
	  private var balance = 0.0
	  def deposit(amount: Double) { balance += amount }
	  def description = "Account " + id + " with balance " + balance
	}
	
	object Account { // 伴生对象
	  private var lastNumber = 0
	  private def newUniqueNumber() = { lastNumber += 1; lastNumber }
	}
	
	
	val acct1 = new Account
	val acct2 = new Account
	acct1.deposit(1000)
	val d1 = acct1.description
	val d2 = acct2.description
```

+ 类和它的伴生对象可以相互访问私有特征。

**总结**：个人理解，scala中引入object就是为了解决没有静态变量或静态方法的问题。

----------
## 3. 扩展类或特质的对象
+ 一个object可以扩展类以及一个或多个特质。

```
	abstract class UndoableAction(val description: String) {
	  def undo(): Unit
	  def redo(): Unit
	}
	
	object DoNothingAction extends UndoableAction("Do nothing") {
	  override def undo() {}
	  override def redo() {}
	}
	
	val actions = Map("open" -> DoNothingAction, "save" -> DoNothingAction)
	actions("open") == actions("save")
```


----------
## 4. apply方法
+ 不使用new，而直接使用object(参数1，...，参数N)，这时候apply方法会被调用。
```
	class Account private (val id: Int, initialBalance: Double) {
	  private var balance = initialBalance
	  def deposit(amount: Double) { balance += amount }
	  def description = "Account " + id + " with balance " + balance
	}
	
	object Account { // The companion object
	  def apply(initialBalance: Double) = 
	    new Account(newUniqueNumber(), initialBalance)
	  private var lastNumber = 0
	  private def newUniqueNumber() = { lastNumber += 1; lastNumber }
	}
	
	val acct = Account(1000.0)
	val d = acct.description
```


----------
## 5. 应用程序对象
+ scala程序都是从对象main方法开始
```
	object Hello {
	  def main(args: Array[String]) {
	    println("Hello, World!")
	  }
	}
```

+ 保存为Hello.scala文件，执行：**scalac Hello.scala**编译文件，执行：**scala Hello**运行程序。


----------
## 6. 枚举
+ scala 中没有枚举类型，但有枚举类，**Enumeration**
```
	object TrafficLightColor extends Enumeration {
	  val Red, Yellow, Green = Value
	}
	
	TrafficLightColor.Red
	TrafficLightColor.Red.id
	
	object TrafficLightColor extends Enumeration {
	  val Red = Value(0, "Stop")
	  val Yellow = Value(10) // Name "Yellow"
	  val Green = Value("Go") // ID 11
	}
```

+ Value中可以不传值，可以传入ID、名称。

+ 枚举的ID可以通过**id方法**返回，名称通过**toString方法**返回。


----------

【待续】