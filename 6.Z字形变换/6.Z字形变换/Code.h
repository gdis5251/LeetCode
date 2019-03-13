class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;

		string ans;
		int n = s.size();
		int circleLen = 2 * numRows - 2;

		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; i + j < n; j += circleLen)
			{
				ans += s[i + j];

				if (i != 0 && i != numRows - 1 && j + circleLen - i < n)
					ans += s[j + circleLen - i];
			}
		}

		return ans;
	}
};


//2*n-2很好推，然后这个题的思路就是不管是哪一行，先把2*n-2这一列加上，在加完之后判断，是不是中间行
//如果是中间行，在把中间那个加上
//j+circleLen-i 这一列加上
/*
怎么说呢，其实就是每隔多少个加一个。第一行和最后一行，都是每隔circleLen加一个
但是中间行有两种情况加法，第一种情况就是跟第一行和最后一行的情况一样，每隔circleLen加一个
第二种情况就是中间斜杠的部分，其实也是每隔circleLen加一个，但是我们要先找到第一个点
就是在斜杠部分的第一个点，就是j + circle - i当j == 0，那就是第一个点，然后每隔circleLen 加一个
*/