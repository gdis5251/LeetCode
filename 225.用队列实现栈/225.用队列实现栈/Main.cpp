#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
	/** Initialize your data structure here. */
	MyStack() {

	}

	/** Push element x onto stack. */
	void push(int x) {
		if (q1.empty() && q2.empty())
		{
			q1.push(x);
			return;
		}
		else if (!q1.empty())
		{
			q1.push(x);
			return;
		}
		else if (!q2.empty())
		{
			q2.push(x);
			return;
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (q1.empty())
		{
			size_t sz = q2.size();
			for (size_t i = 0; i < sz - 1; i++)
			{
				q1.push(q2.front());
				q2.pop();
			}

			int a = q2.front();
			q2.pop();

			return a;
		}
		else if (q2.empty())
		{
			size_t sz = q1.size();
			for (size_t i = 0; i < sz - 1; i++)
			{
				q2.push(q1.front());
				q1.pop();
			}

			int a = q1.front();
			q1.pop();

			return a;
		}

		return -1;
	}

	/** Get the top element. */
	int top() {
		if (q1.empty())
			return q2.back();
		else if (q2.empty())
			return q1.back();

		return -1;
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return q1.empty() && q2.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};


int main(void)
{
	MyStack s;

	s.push(1);
	s.push(2);
	s.push(3);

	s.pop();
	s.pop();
	s.pop();

	s.empty();


	return 0;
}