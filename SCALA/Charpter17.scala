// 习题1
class Pair[T, S](val first: T, val second: S) {
  def swap[V >: T, W >: S]() = new Pair(second, first)
}

object test17_1 extends App {
  val p1 = new Pair(34, "hello")
  println("first:" + p1.first + " second:" + p1.second)
  val p2 = p1.swap()
  println("first:" + p2.first + " second:" + p2.second)
}

// 习题2
class Pair2[T](var first: T, var second: T) {
  def swap() = {
    val tmp: T = first
    first = second
    second = tmp
  }
}

object test17_2 extends App {
  val p1 = new Pair2("name", "Aaron")
  println("first:" + p1.first + " second:" + p1.second)
  p1.swap()
  println("first:" + p1.first + " second:" + p1.second)
}

// 习题3
class Pair3[T, S](val first: T, val second: S) {
  def swap[V >: T, W >: S](f: V, s: W) = new Pair3(s, f)
}

object test17_3 extends App {
  val p1 = new Pair3(34, "hello")
  println("first:" + p1.first + " second:" + p1.second)
  val p2 = p1.swap("hello", "world")
  println("first:" + p2.first + " second:" + p2.second)
}

// 习题4 

