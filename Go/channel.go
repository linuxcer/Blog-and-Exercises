package main
import "fmt"

func main() {
    ch4 := make(chan int)
//    ch5 := <-chan int(ch4) // 只读
    //ch6 := chan<- int(ch4) // 只写
    go func() {
        select {
            case <- ch4:
                fmt.Println("read from ch4")
            default:
                fmt.Println("default")
        }
    }()
    ch4 <- 4
    //ch6 <-7
/*    go func() {
        select {
            case <- ch5:
                fmt.Println("read from ch5")
            default:
                fmt.Println("default")
        }
    }()
*/
}


