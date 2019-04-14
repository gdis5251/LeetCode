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
		sum = 0;//这里进行多次赋值的原因是，因为两个变量都是静态变量，所以他们的生命周期是整个程序的生命周期
		num = 1;//若这个函数只调用一次没事，如果调用多次，不进行赋值，他们的值不会改变，会导致结果错误
		Sum arr[5];//因为牛客网的编译器是clang,所以支持可变数组
		return sum;
	}
private:
	static int sum;
	static int num;
};

int Solution::sum = 0;
int Solution::num = 1;

int main(void)
{
	Solution a;
	a.Sum_Solution(5);
	return 0;
}