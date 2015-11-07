//import scala.reflect.BeanProperty
object cla {
  // 第1题
  class Counter {
    private var value = 0
    def increment() = {
      if (value < Int.MaxValue) value += 1 else value
    }
    def current() = value
  }

  // 第2题
  class BankAccount(val balance: Double) {
    def deposit() {}
    def withdraw() {}
  }

  // 第3题(方法1)
  class Time(val hours:Int, val minutes:Int) {
    def before(other: Time): Boolean = { // 该方法可以访问一个对象的私有变量
      if (hours > other.hours) 
        false
      else if ((hours == other.hours) && minutes > other.minutes)
        false
      else 
        true
    }
  }

  // 第3题（方法2）
  class Time2(val hours:Int, val minutes:Int) {
    def before(other: Time2): Boolean = {
      hours < other.hours || (hours == other.hours && minutes < other.minutes)
    }
    override def toString(): String = {
      hours + ":" + minutes
    }
  }

  // 第4题
  class Time3(val hours:Int, val minutes:Int) {
    def before(other: Time3): Boolean = {
      hours < other.hours || (hours == other.hours && minutes < other.minutes) 
    }
    override def toString(): String = {
      (hours * 60 + minutes).toString
    }
  }

  // 第5题
 /* class Student {
    @BeanProperty var name: String = _
    @BeanProperty var id: Long = _
  }*/

  // 第6题
  class Person(var age: Int) { // 主构造器会执行类中所有的语句
    age = if (age < 0) 0 else age
  }

  // 第7题
  /*class Person2(val name: String) {
    val firstName: String = name
  }*/

  // 第8题
  class Car()
  def main(args:Array[String]) {
    println("test1:")
    val c = new Counter
    c.increment()
    println(c.current)
    println("test3:")
    val t1 = new Time(12, 20)
    val t2 = new Time(13, 30)
    println(t1.before(t2))

    val t3 = new Time2(12, 20)
    val t4 = new Time2(13, 30)
    println(t3.before(t4))
    
    println("test4:")
    val t5 = new Time3(12, 20)
    val t6 = new Time3(13, 30)
    println(t5.toString)
    
  }
}
