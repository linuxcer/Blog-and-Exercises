## 1. 为什么没有多重继承

+ 准备这个Chapter讲文件和正则表达式，但该内容按照其他语言安排一般都是在最后几章节，所以暂时先忽略该章节，后面会补上。

+ 转入正题，如果有两个类Student和Employee，它们都有name这个属性，如果要同时扩展这两个基类该如何做，主要问题是name属性如何处理？如果保留两个，那么访问时到底访问的是哪个呢？如果只保留一个，那么保留哪一个？该问题就是**菱形问题**。画一个形象的图形如下：
	
	![这里写图片描述](http://img.blog.csdn.net/20151110214933058)

+ Scala通过提供**特质**解决这个问题，特质可以同时拥有抽象方法和具体方法，而类可以实现多个特质。


----------


## 2. 当做接口使用的特质
+ 特质**完全**可以像Java接口那样工作。

+ 特质中未被实现的方法默认是**抽象方法**，**不需要**用`abstract`申明。

+ 重写特质抽象方法时**不需要**给出`override`关键字。

+ **特质不止一个**，可以使用`with`关键字来添加额外的特质。

+ Scala类**只能有一个超类**，可以**有任意数量的特质**。


----------
## 3. 带有具体实现的特质
+ 特质中可以有具体的方法。

```
	trait ConsoleLogger {
	  def log(msg: String) { println(msg) } // 具体方法
	}
	
	class Account {
	  protected var balance = 0.0
	}
	
	class SavingsAccount extends Account with ConsoleLogger {
	  def withdraw(amount: Double) {
	    if (amount > balance) log("Insufficient funds")
	    else balance -= amount
	  }
	}
```


----------
## 4. 带有特质的对象
+ 构造单个对象时，可以为它添加特质，用`with`关键字。
```
	trait Logged {
	  def log(msg: String) { }
	}
	
	trait ConsoleLogger extends Logged { 
	  override def log(msg: String) { println(msg) }
	} 
	
	class Account {
	  protected var balance = 0.0
	}
	
	class SavingsAccount extends Account with Logged {
	  def withdraw(amount: Double) {
	    if (amount > balance) log("Insufficient funds")
	    else balance -= amount
	  }
	}
	
	object Main extends App {
	  val acct1 = new SavingsAccount
	  acct1.withdraw(100) // 没有任何信息会打印出来
	
	  println("Overdrawing acct2");
	  val acct2 = new SavingsAccount with ConsoleLogger // 添加特质进来
	  acct2.withdraw(100) // 会打印信息
	}
```


----------
## 5. 添加多个特质
> **个人理解：**添加多个特质要研究的问题实际是，添加的这几个特质哪个先执行？即执行的顺序，执行完的结果是要传给另一个特质进行下一步处理，这里有点像linux中pipe的概念。

+ 类或对象可以添加多个特质，特质从最后一个开始执行，非常适合分阶段处理的场景。

```
	trait Logged {
	  def log(msg: String) { }
	}
	
	trait ConsoleLogger extends Logged {
	  override def log(msg: String) { println(msg) }
	}
	
	trait TimestampLogger extends Logged { // 给消息添加时间戳
	  override def log(msg: String) {
	    super.log(new java.util.Date() + " " + msg)
	  }
	}
	
	trait ShortLogger extends Logged { // 截断过长的信息
	  val maxLength = 15 
	  override def log(msg: String) {
	    super.log(
	      if (msg.length <= maxLength) msg else msg.substring(0, maxLength - 3) + "...")
	  }
	}
	
	class Account {
	  protected var balance = 0.0
	}
	
	class SavingsAccount extends Account with Logged {
	  def withdraw(amount: Double) {
	    if (amount > balance) log("Insufficient funds") // 调用特质中的log方法
	    else balance -= amount
	  }
	}
	
	object Main extends App {
	  val acct1 = new SavingsAccount with ConsoleLogger with
	    TimestampLogger with ShortLogger
	  val acct2 = new SavingsAccount with ConsoleLogger with
	    ShortLogger with TimestampLogger
	  acct1.withdraw(100) 
	  acct2.withdraw(100)
	}
```
+ 由于特质添加的顺序，上面的执行结果为：
	![运行结果](http://img.blog.csdn.net/20151111055218636)


----------
## 6. 在特质中重写抽象方法
> **个人理解：** 这节就是想区分用类来扩展特质是不需要加override，而特质扩展特质就要加override。

+ 特质中重写抽象方法需要加`abstract`和`override`关键字。
```
	trait Logger {
	  def log(msg: String) // 抽象的方法
	}
	
	trait TimestampLogger extends Logger {
	  abstract override def log(msg: String) {
	    super.log(new java.util.Date() + " " + msg)
	  }
	}
	
	trait ConsoleLogger extends Logger {
	  override def log(msg: String) { println(msg) } // 这里说明abstract是可以省略的
	}
```


----------
## 7. 当做富接口使用的特质
> ***个人理解：**这节无非是上面的基本应用，train中可以根据不同的应用场景来定义多个同一功能的方法。

+ 比如下面这段代码，每个日志消息都会区分消息的类型。
```
	trait Logger {
	  def log(msg: String)
	  def info(msg: String) { log("INFO: " + msg) }
	  def warn(msg: String) { log("WARN: " + msg) }
	  def severe(msg: String) { log("SEVERE: " + msg) }
	}
```


----------
## 8. 特质中的具体字段
> **个人理解：**这节主要目的是知道特质中可以有具体的字段，具体的意思就是经过初始化的字段。并且**类**在扩展特质后，具体字段不是被继承的，而是**直接被加入到子类中**。说白了就是在类中又拷贝了该字段的一个副本，类中可以直接使用。


----------
## 9. 特质中的抽象字段
> **个人理解：**具体字段可以直接使用，那么如果是抽象字段该怎么办？这节给出特质中如果有抽象字段，**类**中使用就必须要重新定义该字段，并且不需要使用override关键字，这在第二小节已经明确。

```
	trait Logger {
	  val maxLength: Int // 抽象的字段
	}
	
	class TimestampLogger extends Logger {
	  val maxLength: Int = 20 // 不需要写override
	}
```


----------
## 10. 特质中的构造顺序
> **个人理解：**和类一样，特质也有构造器，同样特质中也存在构造执行顺序的问题。记住特质的构造顺序对写程序是很有帮助的。

+ 特质的构造器执行顺序：

1. 首先调用超类构造器；
2.  特质构造器在超类构造器之后、类构造器之前执行；
3.  特质由左到右构造；
4.  每个特质中，父特质先被构造；
5.  如果过个特质共有一个父特质，而父特质已被构造，则不会再次被构造；
6.  所有特质构造完毕，子类被构造。


----------
## 11. 初始化特质中的字段
> **个人理解：**首先知道**特质是不能有构造参数**，对某种定制的特质来说这就是一个问题，那么该如何解决？这小结给给出了两种解决方案：**提前定义**和**懒值**。

+ 特质不能有构造参数，但都有一个无参的构造器，缺少构造器参数这是特质和类之间**唯一**的技术差别，特质可以具备类的所有特性。

+ 提前定义的方法如下：
```
	trait Logger {
	  def log(msg: String)
	}
	
	// 使用提前定义定义变量filename
	trait FileLogger extends Logger {
	  val filename: String
	  val out = new PrintWriter(filename) 
	  def log(msg: String) { out.println(msg); out.flush() }
	}
	
	class Account {
	  protected var balance = 0.0
	}
	
	abstract class SavingsAccount extends Account with Logger {
	  def withdraw(amount: Double) {
	    if (amount > balance) log("Insufficient funds")
	    else balance -= amount
	  }
	}
	
	object Main extends App {
	  val acct = new {  // new之后就是提前定义块，在构造器执行前就定义好
	    val filename = "myapp.log"
	  } with SavingsAccount with FileLogger
	  acct.withdraw(100) 

	}
```
+ 懒值方法，懒值字段会在第一次使用时才会被初始化。
```
	trait Logger {
	  def log(msg: String)
	}
	
	// 使用懒值
	trait FileLogger2 extends Logger {
	  val filename: String
	  lazy val out = new PrintWriter(filename) 
	  def log(msg: String) { out.println(msg); out.flush() }
	}
	
	class Account {
	  protected var balance = 0.0
	}
	
	abstract class SavingsAccount extends Account with Logger {
	  def withdraw(amount: Double) {
	    if (amount > balance) log("Insufficient funds")
	    else balance -= amount
	  }
	}
	
	object Main extends App {
	  val acct2 = new SavingsAccount with FileLogger2 {
	    val filename = "myapp2.log"
	  } 
	  acct2.withdraw(100)   
	}
```


----------
## 12. 扩展类的特质
> **个人理解：**标题有点绕，其实意思就是**某个特质扩展了类**，这种情况scala会有哪些特殊的地方需要注意。

+ 特质是可以扩展特质的，其实特质也是可以扩展类，扩展后这个类自动成为该特质的超类。
```
	trait Logged {
	  def log(msg: String) { }
	}
	
	trait LoggedException extends Exception with Logged {
	  def log() { log(getMessage()) }
	}
```
这里LoggedException扩展了Exception类，并调用了从Exception超类继承下来的getMessage()方法。


----------
## 13. 自身类型
> **个人理解：**除上面可以扩展某个类的方法之外，scala还提供另外一种方式，不用扩展某个类，直接把某个类作为自身的一个类型，从而达到同样的目的。

+ 定义语法：`this: 类型 =>`，特质定义自身类型后，只能**被**混入指定类型的子类。比如：

```
	trait Logged {
	  def log(msg: String) { }
	}
	
	trait LoggedException extends Logged {
	  this: Exception => // 特质不是扩展Exception类，而是有一个自身类型Exception
	    def log() { log(getMessage()) }
	}
```

+ 自身类型还可以用来处理**结构类型**，比如只指定一个方法，而不是类名。
```
	trait Logged {
	  def log(msg: String) { }
	}
	
	trait LoggedException extends Logged {
	  this: { def getMessage() : String } =>
	    def log() { log(getMessage()) }
	}
```


----------
【待续】