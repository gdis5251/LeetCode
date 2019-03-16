#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myAtoi(char* str) {
	while ((int)*str == ' ' && str != NULL)//ееЁЩ©у╦Я
	{
		str++;
	}
	if (str == NULL)
		return 0;


	int flag = 1;
	if ((int)*str == '-')
	{
		flag = -1;
		str++;
	}
	else if ((int)*str == '+')
		str++;


	int ans = 0;
	int re = 0;
	while ((*str >= 48 && *str <= 57) && str != NULL)
	{
		re = (*str - 48) * flag;
		str++;
		if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && re > 7))
			return INT_MAX;
		if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && re < -8))
			return INT_MIN;

		ans = ans * 10 + re;
	}

	return ans;
}





int main(void)
{
	char *str = "-2147483648";

	int rev = myAtoi(str);

	return 0;
}