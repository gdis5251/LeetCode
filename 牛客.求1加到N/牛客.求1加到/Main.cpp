#include <iostream>

class Solution {
public:
	class Sum
	{
	public:
		Sum()
		{
			sum += num;
			++num;
		}
	};
	int Sum_Solution(int n) {
		sum = 0;//������ж�θ�ֵ��ԭ���ǣ���Ϊ�����������Ǿ�̬�������������ǵ����������������������������
		num = 1;//���������ֻ����һ��û�£�������ö�Σ������и�ֵ�����ǵ�ֵ����ı䣬�ᵼ�½������
		Sum arr[5];//��Ϊţ�����ı�������clang,����֧�ֿɱ�����
		return sum;
	}
private:
	static int sum;
	static int num;
};

int Solution::sum = 0;
int Solution::num = 1;

int main(void)
{
	Solution a;
	a.Sum_Solution(5);
	return 0;
}