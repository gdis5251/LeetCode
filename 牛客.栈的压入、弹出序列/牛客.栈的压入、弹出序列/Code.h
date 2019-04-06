class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		size_t psz = pushV.size();
		size_t popsz = popV.size();

		stack<int> s;
		size_t push_index = 0;
		size_t pop_index = 0;

		while (push_index < psz)
		{
			s.push(pushV[push_index++]);
			while (pop_index < popV.size()
				&& s.top() == popV[pop_index])
			{
				s.pop();
				pop_index++;
			}
		}

		return s.empty();
	}
};