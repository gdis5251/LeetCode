class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		vector<int>::const_iterator it = bits.cbegin();
		int flag = 0;

		while (it < bits.cend())
		{
			if (*it == 1)
			{
				it += 2;
				flag = 0;
			}
			else
			{
				it += 1;
				flag = 1;
			}
		}

		if (flag)
			return true;

		return false;
	}
};