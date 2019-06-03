#include <iostream>
#include <string>
#include <vector>

void Split(std::string& str, std::vector<std::string>& ans)
{
	// ���ݿո�ָ��ַ���
	// �����������ڵĿո�
	int start = 0;
	int end = 0;
	int i = 0; // ��¼ans���±�
	int quotation_mark_start = 0;
	int quotation_mark_end = 0;
	int flag = 0;

	// �Ȳ���һ���Ƿ���Ҫ������
	// ���仰˵���������һ�¿�����û������
	// ����У�˳������ŵĿ�ʼλ��ֱ��ȷ����
	quotation_mark_start = str.find('"', 0);
	if (quotation_mark_start != -1)
	{
		flag = 1;
	}

	do
	{
		// ��һ����������û�����ţ��������ҿո�
		end = str.find(' ', start);

		// ����ַ�������������ţ�����������߼�
		if (flag)
		{
			quotation_mark_start = str.find('"', quotation_mark_start);
			quotation_mark_end = str.find('"', quotation_mark_start + 1);

			// ���ֻʣ�����һ�������ڵ�����
			if (end == -1 && quotation_mark_start != -1 && quotation_mark_end != -1)
			{
				ans[i] = str.substr(quotation_mark_start + 1, quotation_mark_end - quotation_mark_end - 2);
				break;
			}

			if (quotation_mark_start != -1 && quotation_mark_end != -1 &&
				end > quotation_mark_start && end < quotation_mark_end)
			{
				// ��� end �����������ڣ��ǾͰ������ڵ��ַ������������
				ans[i] = str.substr(quotation_mark_start + 1, quotation_mark_end - quotation_mark_end - 2);
				start = quotation_mark_end + 2; // ֱ���������ź���Ŀո�

				quotation_mark_start = quotation_mark_end + 2;
			}
			else
			{
				if (start != -1 && end == -1)
				{
					ans[i] = str.substr(start);
					break;
				}

				ans[i] = str.substr(start, end - start);
				start = end + 1;
			}
		}
		else
		{
			ans[i] = str.substr(start, end - start);
			start = end + 1;
		}
		++i;
	} while (end != -1 && start < str.size());
	ans.resize(i);
}

void Print(std::vector<std::string> & ans)
{
	std::cout << ans.size() << std::endl;

	for (size_t i = 0; i < ans.size(); i++)
	{
		std::cout << ans[i].c_str() << std::endl;
	}
}

int main(void)
{
	std::string input;

	while (std::getline(std::cin, input))
	{
		std::vector<std::string> ans;
		ans.resize(100);

		Split(input, ans);

		Print(ans);
	}

	return 0;
}