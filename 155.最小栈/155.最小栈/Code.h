class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		data.push(x);

		if (minStack.empty() || x <= minStack.top())
		{
			minStack.push(x);
		}
	}

	void pop() {
		int tmp = data.top();
		data.pop();

		if (tmp == minStack.top())
			minStack.pop();

	}

	int top() {
		return data.top();
	}

	int getMin() {
		return minStack.top();
	}

private:
	stack<int> data;
	stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */