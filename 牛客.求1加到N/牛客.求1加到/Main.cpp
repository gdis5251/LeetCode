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
		sum = 0;//��Ϊ�ڴ��������ʱ������Ĭ�Ϲ��캯������������Ҫ��һ�εĸ�ֵ
		num = 1;//����������������ֵ�ָ���ʼ״̬
		Sum arr[n];//��Ϊţ�����ı�������clang,����֧�ֿɱ�����
		return sum;
	}
private:
	static int sum;
	static int num;
};

int Solution::sum = 0;
int Solution::num = 1;

