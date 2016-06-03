package main

import (
    "fmt"
    "net"
    "net/http"
    "net/rpc"
)

type Watcher int

func (w *Watcher) GetInfo(arg int, result *int) error {
    *result = arg * 100 
    return nil
}

func main() {
    watcher := new(Watcher)
    rpc.Register(watcher)
    rpc.HandleHTTP()

    i, err := net.Listen("tcp", ":1234")

    if err != nil {
        fmt.Println("监听失败，端口可能被占用")
    }

    fmt.Println("正在监听1234端口")
    http.Serve(i, nil)
}
