#include<iostream>
#include<string>
using namespace std;
int main()
{
	string line;
	
	while (getline(cin, line))	//想要跳出循环的中断信号是ctrl+c
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}
	return 0;
}