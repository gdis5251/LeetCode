#include <iostream>
#include <string>
#include <vector>

void Split(std::string& str, std::vector<std::string>& ans)
{
	// 根据空格分隔字符串
	// 不包括引号内的空格
	int start = 0;
	int end = 0;
	int i = 0; // 记录ans的下标
	int quotation_mark_start = 0;
	int quotation_mark_end = 0;
	int flag = 0;

	// 先测试一下是否需要找引号
	// 换句话说，先随便找一下看看有没有引号
	// 如果有，顺便把引号的开始位置直接确定了
	quotation_mark_start = str.find('"', 0);
	if (quotation_mark_start != -1)
	{
		flag = 1;
	}

	do
	{
		// 第一个参数绝对没有引号，所以先找空格
		end = str.find(' ', start);

		// 如果字符串里面存在引号，就增加这个逻辑
		if (flag)
		{
			quotation_mark_start = str.find('"', quotation_mark_start);
			quotation_mark_end = str.find('"', quotation_mark_start + 1);

			// 如果只剩下最后一个引号内的内容
			if (end == -1 && quotation_mark_start != -1 && quotation_mark_end != -1)
			{
				ans[i] = str.substr(quotation_mark_start + 1, quotation_mark_end - quotation_mark_end - 2);
				break;
			}

			if (quotation_mark_start != -1 && quotation_mark_end != -1 &&
				end > quotation_mark_start && end < quotation_mark_end)
			{
				// 如果 end 包含在引号内，那就把引号内的字符串插进数组中
				ans[i] = str.substr(quotation_mark_start + 1, quotation_mark_end - quotation_mark_end - 2);
				start = quotation_mark_end + 2; // 直接跳过引号后面的空格

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