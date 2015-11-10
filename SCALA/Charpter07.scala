object test extends App {
  import java.util.{HashMap => JavaHashMap}
  val map = new JavaHashMap[String, String]()
  map.put("1", "a")
  map.put("2", "b")
  import scala.collection.mutable.HashMap
  val smap = new HashMap[String, String]()
  for (key <- map.keySet().toArray) {
    smap += (key.toString -> map.get(key))
  }
  println(smap.mkString(","))
}

import java.lang.System
object test02 extends App {
  val passwd = Console.readLine()
  if (passwd == "secret")
    println("hello " + System.getProperty("user.name"))
  else
    System.err.println("passwd error")
} 
