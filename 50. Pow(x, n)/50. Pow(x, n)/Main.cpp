#include <iostream>

class Solution {
public:
	static double myPow(double x, int n) {
		/*把次方变成二进制数
		把这个数字拆成整数相加的格式
		先默认res为x的0次方为1
		目的是为了将res的次方变成参数给的次方
		底数就是x这个无所谓
		例如 2 ， 10    将次方变成二进制1010 
		这里就是2 乘 2的二次方 乘 2的八次方   数字相乘次方相加
		*/
		double res = 1.0;
		for (int i = n; i != 0; i /= 2) {//这里除二就相当于把二进制右移的操作
			if (i % 2 != 0) {
				res *= x;
			}
			x *= x;

			if (res == 0)
				break;
		}
		return  n < 0 ? 1 / res : res;

	}
};


int main(void)
{
	double rev = Solution::myPow(3.0, 11);

	return 0;
}