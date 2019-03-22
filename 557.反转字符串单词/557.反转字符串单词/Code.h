class Solution {
public:
	string reverseWords(string s) {

		if (s == "")
			return s;

		size_t pos = 0;
		size_t begin = 0;
		size_t end = 0;
		int flag = 1;

		while (flag) {
			if (pos == 0)
				begin = pos;
			else
				begin = pos + 1;

			pos = s.find(' ', pos + 1);
			if (pos == -1)
			{
				end = s.size() - 1;
				flag = 0;
			}
			else
				end = pos - 1;

			while (begin < end)
			{
				swap(s[begin], s[end]);
				++begin;
				--end;
			}
		}

		return s;
	}
};