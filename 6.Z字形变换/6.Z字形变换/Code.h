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


//2*n-2�ܺ��ƣ�Ȼ��������˼·���ǲ�������һ�У��Ȱ�2*n-2��һ�м��ϣ��ڼ���֮���жϣ��ǲ����м���
//������м��У��ڰ��м��Ǹ�����
//j+circleLen-i ��һ�м���
/*
��ô˵�أ���ʵ����ÿ�����ٸ���һ������һ�к����һ�У�����ÿ��circleLen��һ��
�����м�������������ӷ�����һ��������Ǹ���һ�к����һ�е����һ����ÿ��circleLen��һ��
�ڶ�����������м�б�ܵĲ��֣���ʵҲ��ÿ��circleLen��һ������������Ҫ���ҵ���һ����
������б�ܲ��ֵĵ�һ���㣬����j + circle - i��j == 0���Ǿ��ǵ�һ���㣬Ȼ��ÿ��circleLen ��һ��
*/