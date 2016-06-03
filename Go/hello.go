package main

import "fmt"

func main() {
    var str string
    str = "Hello 世界"
    fmt.Printf("The lenght of \"%s\" is %d \n", str, len(str))
    n := len(str)
    for i := 0; i < n; i++ {
        ch := str[i]
        fmt.Println(i, ch)
    }

    for i, ch := range str {
        fmt.Println(i, ch)
    }
}
