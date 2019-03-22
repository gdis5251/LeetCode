#include <string>


//class Solution {
//public:
//	static bool isPalindrome(std::string s) {
//		if (s.empty())
//			return true;
//
//		std::string cpy;
//		for (auto c : s)
//		{
//			if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
//				cpy.push_back(c);
//		}
//
//		std::string reverse_cpy(cpy);
//		int begin = 0;
//		int end = reverse_cpy.size() - 1;
//
//		while (begin < end)
//		{
//			std::swap(reverse_cpy[begin], reverse_cpy[end]);
//			++begin;
//			--end;
//		}
//
//		std::string::iterator cit = cpy.begin();
//		std::string::iterator rit = reverse_cpy.begin();
//
//		while (cit < cpy.end())
//		{
//			if (*cit >= '0' && *cit <= '9')
//			{
//				if (*cit == *rit)
//				{
//					cit++;
//					rit++;
//				}
//				else
//				{
//					return false;
//				}
//			}
//			else
//			{
//				if (*cit >= *rit)
//				{
//					if (*cit == *rit || *cit - 32 == *rit)
//					{
//						cit++;
//						rit++;
//					}
//					else
//						return false;
//				}
//				else
//				{
//					if (*rit - 32 == *cit)
//					{
//						cit++;
//						rit++;
//					}
//					else
//						return false;
//				}
//			}
//		}
//
//		return true;
//	}
//};


class Solution {
public:
	bool isNumberOrLetter(char c)
	{
		return (c >= '0' && c <= '9')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z');
	}
	bool isPalindrome(string s) {
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			//从前向后找到第一个字母或数字
			while (begin < end)
			{
				if (isNumberOrLetter(s[begin]))
					break;
				begin++;
			}

			//从后向前找到第一个字母或数组
			while (begin < end)
			{
				if (isNumberOrLetter(s[end]))
					break;
				end--;
			}

			//比较begin和end位置的字符
			//大小写字母相差32
			if ((s[begin] + 32 - 'a') % 32 != (s[end] + 32 - 'a') % 32)
				return false;

			begin++;
			end--;


		}

		return true;
	}
};


int main(void)
{
	std::string s("0P");
	bool i = Solution::isPalindrome(s);

	return 0;
}