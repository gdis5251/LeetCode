#include<iostream>
#include<string>
using namespace std;
int main()
{
	string line;
	// ��Ҫʹ��cin>>line,��Ϊ���������ո�ͽ�����
	// while(cin>>line)
	while (getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}
	return 0;
}