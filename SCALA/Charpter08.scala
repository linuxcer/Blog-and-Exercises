class BankAccount(initialBalance: Double) {
  private var balance = initialBalance
  def deposit(amount: Double) = {
    balance += amount 
    balance
  }
  def withdraw(amount: Double) = {
    balance -= amount 
    balance
  }
  def currentBalance = balance
}

// 第1题
class checkingAccount(initialBalance: Double) extends BankAccount(initialBalance) {
  override def deposit(amount: Double) = {
    super.deposit(amount - 1)
  }
  override def withdraw(amount: Double) = {
    super.withdraw(amount + 1)
  }
}


object checkingAccount {
  val cha = new checkingAccount(1000)
  val dep = 100 
  val draw = 200 
  def main(args: Array[String]) {
    cha.deposit(dep)
    println("存入：" + dep + "余额:" + cha.currentBalance)
    cha.withdraw(draw) 
    println("取出：" + draw + "余额:" + cha.currentBalance)
  }
}

// 第2题
class SavingsAccount(initialBalance: Double) extends BankAccount(initialBalance) {
  private var freecount: Int = 3
  private val interest = 0.01  // 利息
  def earnMonthlyInterest() = {
    super.deposit(super.currentBalance * interest)
  }

  override def deposit(amount: Double) = {
    if (freecount > 0) {
      freecount -= 1
      super.deposit(amount)
    } else {
      super.deposit(amount - 1)
    } 
  }
  override def withdraw(amount: Double) = {
    if (freecount > 0) {
      freecount -= 1
      super.withdraw(amount)
    } else {
      super.withdraw(amount + 1)
    }
  }
}

object SavingsAccount {
  val acc = new SavingsAccount(1000)
  def main(args: Array[String]) {
    acc.deposit(100)
    acc.earnMonthlyInterest()
    println("存入:100  " + "余额：" + acc.currentBalance)
    acc.withdraw(100)
    acc.earnMonthlyInterest()
    println("取出:100 " + "余额：" + acc.currentBalance)

  }
}

// 第3题
abstract class animal {
  def speak
}

class dog extends animal {
  override def speak = { println("wang wang!") }
}

class cat extends animal {
  override def speak = { println("miao miao!") }
}

object test {
  val d = new dog 
  val c = new cat 
  def main(args: Array[String]) {
    d.speak
    c.speak
  }
}

// 第4题
abstract class Item {
  def price: Double
  def description: String
}

class SimpleItem (override val price: Double, override val description: String) extends Item {

}

class Bundle extends Item{
  val itemList = scala.collection.mutable.ArrayBuffer[Item]()
  def addItem(item: Item) {
    itemList += item
  }
  override def price = {
    var p: Double = 0
    itemList.foreach(i => p += i.price)
    p
  }

  override def description = {
    var des = ""
    itemList.foreach(i => des += i.description)
    des 
  }
}

object test01 {
  val bundel = new Bundle
  def main(args: Array[String]) {
    val priceArr = Array(2.3, 100, 4.8)
    val descArr = Array("铅笔", "水杯", "鼠标")
    for (i <- 0 until 3) {
      bundel.addItem(new SimpleItem(priceArr(i), descArr(i)))
    }

    bundel.itemList.foreach(item=>println("描述:" + item.description + "   价格：" + item.price))
    println("购物信息如下：" + bundel.description)
    println("总价格：" + bundel.price)
  }
}

// 第5题 
class Point(x: Int, y: Int) {
  override def toString = "x = " + x + " y = " + y 
}

class LabeledPoint(desc: String, x: Int, y: Int) extends Point(x, y){
  override def toString = "desc:" + desc + " x = " + x + " y = " + y
}



