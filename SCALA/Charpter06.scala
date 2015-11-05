import scala.collection.JavaConversions.mapAsScalaMap
import java.util.TreeMap
object Hash {
  // 第1题
  def buy() = {
    val map = Map("book" -> 10, "ipad" -> 10000, "bike" -> 200)
    for ((k, v) <- map) yield (k, v * 0.9)
  }

  // 第2题
  def read_word() = {
    val in = new java.util.Scanner(new java.io.File("test.txt"))
    val words = new scala.collection.mutable.HashMap[String, Int]
    while (in.hasNext()) {
      val w = in.next()
      words(w) = words.getOrElse(w, 0) + 1
    }
    println(words.mkString(","))
  }

  // 第3题，每次添加一个新元素都要返回新的映射
  def read_word_immutable() = {
    val in = new java.util.Scanner(new java.io.File("test.txt"))
    var words = Map[String, Int]()
    while (in.hasNext()) {
      val w = in.next()
      words = words + (w -> (words.getOrElse(w, 0) + 1))
    }
    println(words.mkString(","))
  }

  // 第4题
  def read_word_sorted() = {
    val in = new java.util.Scanner(new java.io.File("test.txt"))
    var words = scala.collection.SortedMap[String, Int]()
    while (in.hasNext()) {
      val w = in.next()
      words = words + (w -> (words.getOrElse(w, 0) + 1))
    }
    println(words.mkString(","))
  }

  // 第5题 
  /*
  def tree_map() = {
    val in = new java.util.Scanner(new java.io.File("test.txt"))
    var words:Map[String, Int] = new TreeMap[String, Int]
    while (in.hasNext()) {
      val w = in.next()
      words = words + (w -> (words.getOrElse(w, 0) + 1))
    }
    println(words.mkString(","))
  }

  def main(args: Array[String]) {
    // read_word() 
    // read_word_immutable()
    //read_word_sorted()
    tree_map()
  }
}
