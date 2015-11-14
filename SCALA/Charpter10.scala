// 第一题
import java.awt.geom.Ellipse2D

trait RectangleLike {
  this: Ellipse2D.Double => // 自身类型
  def translate(x: Double, y:Double) {
    this.x = x
    this.y = y
  } 
  def grow(x: Double, y: Double) {
    this.x += x
    this.y += y
  }
}

object test10_1 extends App {
  val egg = new java.awt.geom.Ellipse2D.Double(5, 10, 20, 30) with RectangleLike
  println("x = " + egg.getX + " y = " + egg.getY)

  egg.translate(10, -10)
  println("x = " + egg.getX + " y = " + egg.getY)
  
  egg.grow(10, 20) 
  println("x = " + egg.getX + " y = " + egg.getY)
}

// 第二题
import java.awt.Point
class OrderedPoint extends Point with Ordered[Point] {
  def compare(that: Point): Int = if (this.x <= that.x && this.y < that.y) -1 else if(this.x == that.x && this.y == that.y) 0 else 1
}

// 第四题
trait Logger {
  def log(str: String, key: Int = 3): String // 抽象的方法
}

class CryptoLogger extends Logger {
  def log(str: String, key: Int): String = {
    for (i <- str) yield if (key >= 0) (97 + ((i - 97 + key) % 26)).toChar else (97 + ((i - 97 + 26 + key) % 26)).toChar 
  }
}

object test10_4 extends App{
  val context = "zhangchengfeihello"
  println("明文：" + context)
  println("加密：" + new CryptoLogger().log(context))  
  println("加密：" + new CryptoLogger().log(context, -3))  
}

// 第四题
import java.beans.PropertyChangeSupport

trait PropertyChange extends PropertyChangeSupport 

// 第七题
trait person {
  def getName() = { println("get Name")}
  def setName(n: String)
}

trait Student {
  var Sname:String = _ // _表示默认值
}

class Postgraduate extends person with Student {
  def setName(n: String) {
    println(n)
  } 
}

object test10_7 extends App {
  val stu = new Postgraduate()
  stu.getName
  stu.setName("zhang")
}





