## 1. 包 package
+ 源文件目录和包之间并没有强制的关联关系。比如下面Manager.scala不一定要在`./com/horstmann/impatient`目录中。
```
	// Manager.scala
	package com {
	  package horstmann {
	    package impatient {
	      class Manager(name: String) {
	        def description = "A manager with name " + name
	      }      
	    }
	  }
	}
```
 
 + 同一个文件中可以给多个包贡献内容，比如Employee.scala文件可以包含：
 
```
	package com {
	  package horstmann {
	    package impatient {
	      class Employee(id: Int) {
	        def description = "An employee with id " + id
	      }      
	    }
	  }
	}
	
	package org {
	  package bigjava {
	    class Counter {
	      private var value = 0 
	      def increment() { value += 1 } 
	      def description = "A counter with value " + value
	    }
	  }
	}
```
 


----------


## 2. 作用域规则
+ Scala的包作用域支持嵌套，包路径都是相对的。

+ `java.lang`、`scala`和`Predef`总是被引入，这种引入被称为**隐式引入**。

----------
## 3. 串联式包语句
+ 包语句可以包含一个“串”或者说是“路径区段”

``` JAVA
	package com.horstmann.impatient {
	  package people {
	    class Person(val name: String) {
	      val friends = new collection.mutable.ArrayBuffer[Person]
	      // com和com.hosrstmann的成员这里不可见
	      def description = name + " with friends " + 
	        friends.map(_.name).mkString(", ")
	    }
	  }
	}
```


----------
## 4. 文件顶部标记法

+ 可以在文件顶部使用`package`语句，不带花括号。
```
	package com.horstmann.impatient
	
	class Car
```


----------


## 5. 包对象
+ 每个包都可以有一个包对象，要在父包中定义它，且名称与子包一样。

```
	package com.horstmann.impatient
	
	package object people {
	  val defaultName = "John Q. Public"
	}
	
	package people {
	  class Person {
	    var name = defaultName // A constant from the package
	    def description = "A person with name " + name
	  }
	}
	
	// Run as scala com.horstmann.impatient.Main
	
	object Main extends App {
	  val john = new com.horstmann.impatient.people.Person
	  println(john.description)
	}
```


----------
## 6. 包可见性
+ 没有被public、private或protected声明的类成员，在包含该类的包中可见，可以使用`private[包名]`达到同样效果。

```
	package com.horstmann.impatient
	
	package object people {
	  val defaultName = "John Q. Public"
	}
	
	package people {
	  class Person {
	    var name = defaultName // A constant from the package
	    private[impatient] def description = "A person with name " + name
	  }
	}
```


----------

## 7. 引入import
+ 引入让你可以使用更短的名称

		import java.awt.Color
+ 引入包的全部成员，也可以引入类或对象的全部成员。
		
		import java.awt._

+ 任何地方都可以出现import引入，作用到该块的结尾。


----------
## 8. 重命名和隐藏方法
+ 只项引入几个成员，使用**选择器**。

		import java.awt.{Color, Font}

+ 重命名选到的成员。

		import java.util.{HashMap => JavaHashMap}

+ `HashMap => _` 是用来隐藏某个成员。


----------
【待续】

