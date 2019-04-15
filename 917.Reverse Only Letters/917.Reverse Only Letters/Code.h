class Solution {
public:
	string reverseOnlyLetters(string S) {
		std::string::iterator ibegin = S.begin();
		std::string::iterator iend = S.end();

		while (ibegin < iend)
		{
			while (*ibegin < 'A' || (*ibegin > 'Z' && *ibegin < 'a') || *ibegin > 'z' && ibegin < iend)
				ibegin++;
			while (*iend < 'A' || (*iend > 'Z' && *iend < 'a') || *iend > 'z' && ibegin < iend)
				iend--;

			if (ibegin < iend)
			{
				swap(*ibegin, *iend);
			}

			ibegin++;
			iend--;
		}

		return S;
	}
};