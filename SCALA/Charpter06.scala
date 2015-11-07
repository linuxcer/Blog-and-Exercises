abstract class UnitConversion {
  def inchesToCentimeters(){}
  def gallonsToLiTers(){}
  def milesToKilometers(){}
} 

object Conversions extends UnitConversion{
  override def inchesToCentimeters(){}
  override def gallonsToLiTers(){}
  override def milesToKilometers(){}
}

class Point(x: Int, y: Int) {
  override def toString: String = "x = " + x + "y = " + y
}

object Point extends App {
  def Apply(x:Int, y:Int) {
    new Point(x, y)
  }
  val p = Point(1, 2)
  println(p)
}


