#include<iostream>
#include<string>
using namespace std;
int main()
{
	string line;
	
	while (getline(cin, line))	//��Ҫ����ѭ�����ж��ź���ctrl+c
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}
	return 0;
}