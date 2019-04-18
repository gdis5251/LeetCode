#include <iostream>

class Solution {
public:
	class Div
	{
	public:
		Div()
		{
			if (_dividend == INT_MIN && _divisor == -1)
				_dividend += 1;
			_ans = _dividend / _divisor;
		}
	};

	int divide(int dividend, int divisor) {
		_dividend = dividend;
		_divisor = divisor;
		_ans = 1;

		Div a;

		return _ans;

	}

	static int _dividend;
	static int _divisor;
	static int _ans;
};

int Solution::_ans = 0;
int Solution::_dividend = 0;
int Solution::_divisor = 0;


int main(void)
{
	Solution a;
	long ans = a.divide(-2147483647 - 1, -1);
	return 0;
}