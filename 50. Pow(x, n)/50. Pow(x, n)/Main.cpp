#include <iostream>

class Solution {
public:
	static double myPow(double x, int n) {
		/*�Ѵη���ɶ�������
		��������ֲ��������ӵĸ�ʽ
		��Ĭ��resΪx��0�η�Ϊ1
		Ŀ����Ϊ�˽�res�Ĵη���ɲ������Ĵη�
		��������x�������ν
		���� 2 �� 10    ���η���ɶ�����1010 
		�������2 �� 2�Ķ��η� �� 2�İ˴η�   ������˴η����
		*/
		double res = 1.0;
		for (int i = n; i != 0; i /= 2) {//����������൱�ڰѶ��������ƵĲ���
			if (i % 2 != 0) {
				res *= x;
			}
			x *= x;

			if (res == 0)
				break;
		}
		return  n < 0 ? 1 / res : res;

	}
};


int main(void)
{
	double rev = Solution::myPow(3.0, 11);

	return 0;
}