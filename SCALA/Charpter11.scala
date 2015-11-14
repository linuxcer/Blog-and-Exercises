// 习题1
//import org.junit.Test
//class test11_1 {
//  @Test 
//  def test1() {
//    println("test1")
//  }
//
//  @Test(timeout = 1) 
//  def test2() {
//    println("test2")
//  }
//}

// 习题2
@deprecated
class test11_2 {
  @deprecated
  var num: Int = _ // 默认值

  @deprecated(message = "unuse")
  def hello() {
    println("hello")
  }
}

@deprecated
object test11_2 extends App {
  val t = new test11_2()
  t.hello()
} 

// 习题4
import annotation.varargs
class test11_4 {
  @varargs
  def sum(n: Int*) {
    n.sum
  }
}
object test11_4 extends App {
  val t = new test11_4()
  println(t.sum(1, 2, 3))
}

// 习题5
import io.Source
class test11_5 {
  def read() = {
    Source.fromFile("test.txt").mkString
  }
}

// 习题6
class Obj {
  //@volatile
  var flag: Boolean = false
}

import scala.actors.Actor
class test11_6_1(obj: Obj) extends Actor {
  def act() {
    println("thread1 is waiting")
    Thread.sleep(3000)
    obj.flag = true 
    println("thread1 set flag  =  true")
  }
}

class test11_6_2(obj: Obj) extends Actor {
  def act() {
    var f = true 
    while (f) {
      if (obj.flag) {
        println("thread2 is end")
        f = false
      } else {
        println("thread2 is waiting")
        Thread.sleep(1000)
      }
    }
  }
}


object test11_6 {
  def main(args: Array[String]) {
    val obj = new Obj()
    val t1 = new test11_6_1(obj)
    val t2 = new test11_6_2(obj)
    t1.start()
    t2.start()
  }
}

// 第8题
object test11_8 {
  def allDifferent[@specialized(Long, Int) T](x: T, y: T, z: T) = x != y && x != z && y != z
}

// 第10题
object test11_10 {
  def factorial(n: Int) = {
    assert(n > 0)
    n
  }
  def main(args: Array[String]) {
    factorial(-1)
  }
}

