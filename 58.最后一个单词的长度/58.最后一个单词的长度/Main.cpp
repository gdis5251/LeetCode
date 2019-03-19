#include <string>
#include <iostream>

class Solution {
public:
	static int lengthOfLastWord(std::string s) {
		size_t pos = s.rfind(" ");
		return s.size() - pos - 1;
	}
};
int main(void)
{
	std::cout << Solution::lengthOfLastWord("a");
	return 0;
}