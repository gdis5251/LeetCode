class Solution {
	char *nums2str[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
	void _letterCombinations(const string& digits, size_t i, const string& combinstr,
		vector<string>& combinstrVec) {

		if (i == digits.size())
		{
			combinstrVec.push_back(combinstr);
			return;
		}

		string strs = nums2str[digits[i] - '0'];
		for (size_t j = 0; j < strs.size(); ++j)
		{
			_letterCombinations(digits, i + 1, combinstr + strs[j], combinstrVec);
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return vector<string>();

		size_t i = 0;
		string combinstr;
		vector<string> combinstrVec;

		_letterCombinations(digits, i, combinstr, combinstrVec);

		return combinstrVec;

	}
};