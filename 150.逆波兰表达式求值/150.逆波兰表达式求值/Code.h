class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> nums;
		size_t i = 0;
		while (i < tokens.size())
		{
			if (tokens[i] == "+" || tokens[i] == "-"
				|| tokens[i] == "*" || tokens[i] == "/")
			{
				//先取出来的是右操作数
				int right = nums.top();
				nums.pop();
				int left = nums.top();
				nums.pop();

				switch (tokens[i][0])
				{
				case '+':
					nums.push(left + right);
					break;
				case '-':
					nums.push(left - right);
					break;
				case '*':
					nums.push(left * right);
					break;
				case '/':
					nums.push(left / right);
					break;
				}
			}
			else
			{
				nums.push(atoi(tokens[i].c_str()));
			}

			i++;
		}
		return nums.top();

	}


};