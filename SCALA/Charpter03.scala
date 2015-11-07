import math.random
import scala.collection.mutable.ArrayBuffer
object test{
    // 第1题
    def randomArray(n: Int) =  {
        for (i <- 0 until n) yield (random * n).toInt
    }

    // 第2题
    def changeOrder(n: Array[Int]) = {
        val t = n.toBuffer
        for (i <- 1 until (t.length, 2); tmp = t(i); j <- i - 1 until i) { // i是从第二个数开始跑，j是从第一个数开始
            t(i) = t(j)
            t(j) = tmp
        }
        t.toArray
    }

    // 第3题
    def changeOrder02(n: Array[Int]) = {
        (for (i <- 0 until (n.length,2)) yield if (i + 1 < n.length) Array(n(i + 1),n(i))  else Array(n(i))).flatten.toArray
    }

    // 第4题(方法1)
    def reOrder(arr: Array[Int]) = {
        val activ = ArrayBuffer[Int]()
        val negativ = ArrayBuffer[Int]()
        for (i <- 0 until arr.length) {
            if (arr(i) >0) {
                activ += arr(i)
            } else {
                negativ += arr(i)
            }
        }
        activ ++= negativ
        activ.toArray
    }

    // 第4题(方法2)
    def reOrder2(arr: Array[Int]) = {
        val activ = ArrayBuffer[Int]()
        val negativ = ArrayBuffer[Int]()
        arr.foreach(arg => if (arg > 0) activ += arg else negativ += arg)
        activ ++= negativ
        activ.toArray
    }
        
    // 第5题(方法1)
    def calSum(arr: Array[Int]) = {
        var sum: Double = 0
        arr.foreach(arg => sum += arg)
        sum = sum / arr.length
        sum
    }


    // 第5题(方法2)
    def calSum2(arr: Array[Double]) = {
        arr.sum / arr.length 
    }

    // 第6题(方法1)
    def reverseOrder(arr: Array[Int]) = {
        for (i <- (0 until arr.length).reverse) yield arr(i)
    }

    // 第6题(方法2)
    def reverseOrder2(arr: Array[Int]) = {
        arr.reverse 
    }

    // 第7题
    def distinctArr(arr: Array[Int]) = {
        arr.distinct
    }

    // 第8题
    def removeArr(arr: Array[Int]) = {
        val t = arr.toBuffer
        val index = for (i <- 0 until arr.length if arr(i) < 0) yield i
        val right = index.reverse.dropRight(1)
        right.foreach(t.remove(_))
        t 
    }

    def main(args: Array[String]) {
        println(randomArray(10).mkString(","))    
        println(changeOrder(Array(1,2,3,4,5)).mkString(","))
        println(changeOrder02(Array(1,2,3,4,5)).mkString(","))
        println(reOrder(Array(3,0,-3,2,-9,5)).mkString(","))
        println(reOrder2(Array(3,0,-3,2,-9,5)).mkString(","))
        println(calSum(Array(-3,7,0,3,3)).toString)
        println(calSum2(Array(-3,7,0,3,3)).toString)
        println(reverseOrder(Array(-3,7,0,3,3)).mkString(","))
        println(reverseOrder2(Array(-3,7,0,3,3)).mkString(","))
        println(distinctArr(Array(3,3,3,2,1,-9,8,8)).mkString(","))
        println(removeArr(Array(2,3,-1,-5,-8,0,-3,48)).mkString(","))
    }
}

  
