package main

import "net/http"

func main() {
	h := http.FileServer(http.Dir("."))
	for {
		http.ListenAndServeTLS(":8000", "rui.crt", "rui.key", h)
	}
}
