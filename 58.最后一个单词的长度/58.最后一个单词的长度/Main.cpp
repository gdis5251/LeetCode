class Solution {
public:
	int lengthOfLastWord(string s) {

		while ((s.rfind(' ') == s.size() - 1) && !s.empty())
		{
			s.pop_back();
		}
		size_t pos = s.rfind(' ');

		return s.size() - pos - 1;
	}
};