#include <string>

/*
class Solution {
public:
	int firstUniqChar(std::string s) {
		if (s.empty())
			return -1;


		int pos = 0;
		for (pos; pos < s.size(); ++pos)
		{
			if (s.find(s[pos], pos + 1) == -1)
			{
				if (s.find(s[pos]) == pos)
					return pos;
			}

		}

		return -1;
	}
};*/


/*
class Solution {
public:
	int firstUniqChar(string s) {
		int book[123] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			book[s[i]]++;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (1 == book[s[i]])
				return i;
		}

		return -1;

	}
};*/


//ÓÅ»¯¿Õ¼ä
class Solution {
public:
	int firstUniqChar(string s) {
		int book[26] = { 0 };
		for (int i = 0; i < s.size(); i++)
		{
			book[s[i] - 'a']++;
		}

		for (int i = 0; i < s.size(); i++)
		{
			if (1 == book[s[i] - 'a'])
				return i;
		}

		return -1;

	}
};