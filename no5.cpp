/*
问题描述：求解最长回文字符串。
解决方案描述：
	step1:循环遍历输入字符串中的每个字符。
	step2:求以当前字符为对称中心的奇数回文字符串和以当前字符为对称轴左侧字符的偶数字符串，记录最长的回文字符串长度及中心位置。
	step3:利用最长的回文字符串长度及中心位置确定最长回文字符串
解决方案时间复杂度O(n^2).
*/
#include<iostream>
#include<string>
using namespace std;
string longestPalindrome(string s)
{
	int len = s.size();
	if (len == 1)
		return s;
		//return s;
	int pos = 0;
	int longest = 0, maxLong = 0;//longest用来指示拥有最大回文字符串的中心字符位置，maxLong用来指示最大回文字符串长度。
	//step1:循环遍历输入字符串中的每个字符。
	while (pos < len)
	{
//	step2:求以当前字符为对称中心的奇数回文字符串和以当前字符为对称轴左侧字符的偶数字符串，记录最长的回文字符串长度及中心位置。
		for (int i = -1; i < 1; i++)
		{
			int ppos = pos + i;//当i=-1和i=0的时候对应两种情况
			int npos = pos + 1;
			while (ppos >= 0 && npos < len)
			{
				if (s[ppos] == s[npos])
				{
					ppos--;
					npos++;
				}
				else
					break;
			}
			if ((npos - ppos-1)>maxLong)
			{
				longest = pos;
				maxLong = npos - ppos-1;
			}
		}
		pos++;
	}
	if (maxLong % 2)
		return s.substr(longest - maxLong / 2, maxLong);
	else
		return s.substr(longest - maxLong / 2 + 1, maxLong);
}

int main()
{
	string s = "skjehiuihehiuihej";
	cout << longestPalindrome(s);
}