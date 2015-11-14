> Chapter10这节还是挺重要的，在看Spark源码的过程中，发现其源码使用到很多注解的知识，所以这节一定要好好学习。


----------

## 1. 什么是注解

+ **注解：**是那些你插入到代码中以方便工具可以对它们进行处理的**标签**。

+ **注解作用：**是描述哪些被注解的表达式、变量、字段、方法或类型。

+ Java中注解不会影响编译器生成字节码，而Scala中会影响。

+ 下面是注解的一个简单实例：
```
	import scala.reflect.BeanProperty
	import javax.persistence.Entity
	import javax.persistence.Id
	import org.junit._
	import org.junit.Assert._
	
	@Entity class Credentials {
	  @Id @BeanProperty var username : String = _
	  @BeanProperty var password : String = _
	}
	
	class MyTest {
	  @Test(timeout = 100) def testSomeFeature() {
	    assertTrue(6 * 7 == 42)
	  }
	}
```

`@Entity`注解标识该类是一个实体，`@id`是设置主键，`@BeanProperty`在Chapter05中讲过，它会生成getter和setter两种方法，`@Test`表示测试方法，在这里可以测试期望异常和超时时间。具体含义可以上google查询**Junit和JPA注解**。


----------
## 2. 什么可以被注解

+ **类、方法、字段、局部变量和参数**都可添加注解。

+ 可以**添加多个注解**，没有先后顺序。

		 @BeanProperty @Id  var lastName = ""
		 
+ 给**主构造函数**添加注解时，注解**放置在构造器之前**，并加上一对**圆括号**。

		class Credentials @Inject() (var username: String, var password: String) { 
		}

+ 给**表达式**添加注解，需要在表达式后添加**冒号**，然后是注解。
		
		(n: @unchecked) match { ... }


----------
## 3. 注解参数
+ 注解可以带参数。
		
		@Test(timeout = 100, expected = classOf[IOException]) 
		def testNonexistentFile() {     
		    new FileReader("/fred.txt")
		  }

+ 注解**不带参数**，**圆括号可以省略**。注解有默认值，比如Test的Timeout的默认值为0，表示没有超时，expected默认是不预期任何异常。


----------
## 4. 针对Java特性的注解
+ `@volatile`将字段标记为**易失的**，易失的字段可以被多个线程同时更新。

+ `@transient`将字段标记为**瞬态的**，瞬态的字段**不会被序列化**，只会作为临时的缓存数据。（**序列化**：将对象状态信息转换为可以存储或传输的形式的过程）

+ `@strictfp`使用IEEE的double进行浮点计算，而不是使用80位扩展精度，计算慢但移植性高。

+ `@native`标记在C或C++代码中的实现方法。


----------
## 5. 标记接口
+ `@cloneable`和`@remote`标记接口可被**克隆或远程**的对象。

+ `@SerialVersionUID`指定序列化版本，标记可序列化的类。
```
	@cloneable @remote @SerialVersionUID(6157032470129070425L)
	class Employee(var name: String, var salary: Double) extends Serializable {
	  var hireDay = new Date
	}
```


----------
## 6. 受检异常和变长参数
+ `@throws`标记可能抛出异常的对象。

+ `@varargs`可以让你从Java调用Scala的带有变长参数的方法。

```
	class Processor {
	  @varargs def process(args: String*) {
	    println(args.mkString("<", "|", ">"))
	  }
	}
```


----------
## 7. 跳转表生成与内联
+ C++和Java中switch通常被编译为跳转表，更高效，`@switch`检查Scala是不是将match编译成跳转表。
```
	(n: @switch) match {
	  case 0 => "Zero"
	  case 1 => "One"
	  case _ => "?"
	}
```
+ `@inline`将方法标记为内联方法，`@noinline`告诉编译器不要内联。


----------
## 8. 可省略方法
+ `@elidable`给生产代码中需要移除的方法打上标记。它后面会接一个参数，

		 @elidable(800) def dump(props: Map[String, String]) {}

+ 编译时需要使用下面命令：
		
		scalac -Xelide-below 800 prog.scala
		
+ 具体参数表如下，默认值低于1000的方法都会被省略。
![这里写图片描述](http://img.blog.csdn.net/20151113210243343)


----------
## 9. 基本类型的特殊化


	
