class Solution {
public:
	int myAtoi(string str) {
		int n = str.size();
		unsigned int m = 0;
		bool sign = false;
		if (n == 0)
			return 0;
		int i = 0;
		while (i < n && str[i] == ' ')
			i++;
		if (i >= n)
			return 0;
		char c = str[i];
		if (c != '+' && c != '-' && !isdigit(c))
			return 0;
		if (c == '+')
		{
			sign = false;
			i++;
		}
		if (c == '-')
		{
			sign = true;
			i++;
		}
		while (i < n && isdigit(str[i]))
		{
			unsigned int temp = 10 * m + str[i] - 0x30;
			if ((temp - str[i] + 0x30) / 10 != m)
			{
				if (sign)
					return INT_MIN;
				else
					return INT_MAX;
			}
			m = temp;
			i++;
		}
		if (sign)
		{
			if (m >= 0x80000000)
				return INT_MIN;
			else
				return -m;
		}
		else
		{
			if (m >= 0x80000000)
				return INT_MAX;
			else
				return m;
		}
	}
};