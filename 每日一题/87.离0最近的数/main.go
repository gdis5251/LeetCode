package main

import (
	"fmt"
	"io"
)

func main() {
	n := 0
	for {
		_, err := fmt.Scan(&n)
		if err == io.EOF {
			break
		}

		if n == 0 {
			fmt.Println(0)
			continue
		}

		min := 99999
		res := 999
		for i := 0; i < n; i++ {
			num := 0
			fmt.Scan(&num)

			if num >= 0 {
				if num - 0 <= min {
					min = num - 0
					res = num
				}
			} else {
				if 0 - num < min {
					min = 0 - num
					res = num
				}
			}
		}
		fmt.Println(res)
	}
}
