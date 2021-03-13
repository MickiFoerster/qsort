package main

import (
	"fmt"
	"log"
	"os"
)

func main() {
	testdata, err := os.Create("testdata")
	if err != nil {
		log.Fatalf("error: could not create file: %v", err)
	}
	defer testdata.Close()

	randomfile, err := os.Open("/dev/urandom")
	if err != nil {
		log.Fatalf("error: could not open file: %v", err)
	}
	defer randomfile.Close()

	buf := make([]byte, 1024*1024)
	testdata_size := 0
	for {
		n, err := randomfile.Read(buf)
		if err != nil {
			log.Fatalf("error while reading from file: %v\n", err)
		}
		log.Println("read ", n, " random bytes")
		written, err := testdata.Write(buf[:n])
		if err != nil {
			log.Fatalf("error while writing testdata: %v\n", err)
		}
		testdata_size += written
		if testdata_size >= 1024*1024*32 {
			break
		}
		log.Printf("testdata is %v bytes big", testdata_size)
	}
	fmt.Printf("%v Kbytes written to testdata written\n", testdata_size/1024)
}
