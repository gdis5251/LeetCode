package main

import (
	"fmt"
	"math"
)

func main() {
	richMan := 10
	poorMan := 1.0
	for i := 1; i < 30; i++ {
		richMan += 10
		poorMan += math.Pow(2, float64(i))
	}

	fmt.Printf("%d %.0f\n", richMan,poorMan)
}
