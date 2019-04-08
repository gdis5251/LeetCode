#include <iostream>

class Solution {
public:
	class Sum
	{
	public:
		Sum()
		{
			sum += num;
			++num;
		}
	};
	int Sum_Solution(int n) {
		sum = 0;//因为在创建对象的时候会调用默认构造函数，所以这里要再一次的赋值
		num = 1;//让他们两个变量的值恢复初始状态
		Sum arr[n];//因为牛客网的编译器是clang,所以支持可变数组
		return sum;
	}
private:
	static int sum;
	static int num;
};

int Solution::sum = 0;
int Solution::num = 1;

