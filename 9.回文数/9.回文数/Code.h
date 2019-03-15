#include <limits.h>


class Solution {
public:

	//将整数反转过来然后对比之前的数看看是否相等
	bool isPalindrome(int x) {
		if (x < 0)
			return false;

		if (x == 0)
			return true;

		int before = x;
		int after = 0;
		int pop = 0;
		while (x != 0) {
			int pop = x % 10;
			x /= 10;
			if (after > INT_MAX / 10 || (after == INT_MAX / 10 && pop > 7)) return 0;
			if (after < INT_MIN / 10 || (after == INT_MIN / 10 && pop < -8)) return 0;
			after = after * 10 + pop;
		}

		if (before == after)
			return true;

		return false;

	}
};