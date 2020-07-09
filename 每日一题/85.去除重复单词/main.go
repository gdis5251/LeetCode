package main

import (
	"fmt"
	"io"
	"strings"
)

func main() {
	input := ""
	for {
		_, err := fmt.Scan(&input)
		if err == io.EOF {
			break
		}

		output, err := dereplication(input)
		fmt.Println(output)
	}
}

func dereplication(str string) (string, error) {
	tmp := ""
	for i := 0; i < len(str); i++ {
		tmp += string(str[i])
		if strings.Compare(strings.ReplaceAll(str, tmp, ""), "") == 0 {
			return tmp, nil
		}
	}

	return str, nil
}

