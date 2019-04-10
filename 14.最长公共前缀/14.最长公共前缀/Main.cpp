#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	static string longestCommonPrefix(vector<string>& strs) {
		string ans;
		if (strs.empty())
			return ans;
		if (strs.size() == 1)
			return strs[0];
		if (strs.size() == 2)
			return twoCommonPrefix(strs[0], strs[1]);

		size_t mid = strs.size() / 2;

		vector<string> s1;
		for (size_t i = 0; i < mid; i++)
		{
			s1.push_back(strs[i]);
		}

		vector<string> s2;
		for (size_t i = mid; i < strs.size(); i++)
		{
			s2.push_back(strs[i]);
		}

		return twoCommonPrefix(longestCommonPrefix(s1), longestCommonPrefix(s2));
	}

	static string twoCommonPrefix(const string& s1, const string& s2)
	{
		string ans;
		string::const_iterator s1it = s1.begin();
		string::const_iterator s2it = s2.begin();

		while (s1it != s1.end() && s2it != s2.end())
		{
			if (*s1it == *s2it)
				ans += *s1it;
			else
				break;

			s1it++;
			s2it++;
		}

		return ans;
	}
};


int main(void)
{
	//["flower","flow","flight"]
	string s1("flower");
	string s2("flow");
	string s3("flight");

	vector<string> v;
	v.push_back(s1);
	v.push_back(s2);
	v.push_back(s3);

	Solution::longestCommonPrefix(v);

	return 0;
}