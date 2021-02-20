#include <stdio.h>
#include<string.h>
#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

string convert(string s, int numRows)
{
	string res;
	if (s.empty() || numRows <= 1)
		return res;
	int len = s.length();
	for (int i = 0; i < numRows; i++)
	{
		int row = i;
		if (i == 0 || i == numRows - 1)
		{
			while (row < len)
			{
				res += s[row];
				row += 2 * (numRows - 1);
			}
		}
		else {
			while (row < len) {
				res += s[row];
				row += (numRows - i - 1) * 2;
				if (row < len)
				{
					res += s[row];
					row += 2 * i;
				}
			}
		}
	}
	return res;
}

int main()
{
	string in, out;
	int numRow;
	cin >> in >> numRow;
	out = convert(in, numRow);
	cout << out << "\n";
	return 0;
}