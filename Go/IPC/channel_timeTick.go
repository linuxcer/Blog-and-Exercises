package main
import "fmt"
import "time"

func main() {
    ch4 := time.Tick(time.Duration(500) * time.Millisecond)
    ch5 := make(chan bool)
    go func() {
        ch5 <- true
    }()
    for {
        select {
        case <- ch4:
            fmt.Println("tick")
        case <- ch5:
            fmt.Println("check")
        }

    }
}


