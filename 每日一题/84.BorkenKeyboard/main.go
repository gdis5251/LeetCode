package main

import (
	"fmt"
	"io"
	"strings"
)

func main() {
	// 循环输入
	expectStr := ""
	realityStr := ""
	for {
		_, err := fmt.Scan(&expectStr, &realityStr)
		if err == io.EOF {
			break
		}
		errKey, err := findErrKey(expectStr, realityStr)
		if err != nil {
			fmt.Println("Error: %+v", err)
			panic(err)
		}

		fmt.Println(errKey)
	}
}

func findErrKey(lhs string, rhs string) (string, error) {
	// 遍历 lhs，如果当前字符未出现在 rhs 里，在判断当前字符是否出现在 map 里
	// 若没有则打印
	distinct := make(map[string]bool)
	ret := ""
	str := strings.ToUpper(rhs)

	for i := 0; i < len(lhs); i++ {
		subStr := strings.ToUpper(string(lhs[i]))
		if !strings.Contains(str, subStr) && !distinct[subStr] {
			distinct[subStr] = true
			ret += subStr
		}
	}

	return ret, nil
}
