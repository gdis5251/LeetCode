package main

import (
	"fmt"
	"io"
	"sort"
)

func main() {
	n := 0
	for {
		_, err := fmt.Scan(&n)
		if err == io.EOF {
			break
		}

		list := make([]int, 1)
		sum := 0
		max := 0
		for i := 0; i < n; i++ {
			var op int
			var l int
			fmt.Scanf("%d %d", &op, &l)

			if op == 1 {
				list = append(list, l)
				sum += l
			} else if op == 2 {
				rIndex := 0
				for index, value := range list {
					if value == l {
						rIndex = index
						break
					}
				}
				list = append(list[:rIndex], list[rIndex+1:]...)

				sum -= l
			}

			if len(list) < 2 {
				fmt.Println("No")
				continue
			}

			sort.Ints(list)
			max = list[len(list)-1]

			if max >= sum-max {
				fmt.Println("No")
			} else {
				fmt.Println("Yes")
			}
		}
	}
}
