#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0")
			return "0";

		int size1 = num1.size();
		int size2 = num2.size();
		string str(size1 + size2, '0');

		for (int i = size2 - 1; i >= 0; i--)
		{
			int mulStep = 0;
			int addStep = 0;

			for (int j = size1 - 1; j >= 0; j--)
			{
				int tmp1 = (num1[j] - '0') * (num2[i] - '0') + mulStep;
				mulStep = tmp1 / 10;
				tmp1 %= 10;

				int tmp2 = (str[j + i + 1] - '0') + tmp1 + addStep;
				str[j + i + 1] = tmp2 % 10 + '0';
				addStep = tmp2 / 10;
			}
			str[i] += mulStep + addStep;
		}

		if (str[0] == '0')
			str = str.substr(1);

		return str;
	}
};