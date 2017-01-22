/*
问题描述：求解最长回文字符串。
解决方案描述：
	step1:循环遍历输入字符串中的每个字符。
	step2:求以当前字符为对称中心的奇数回文字符串和以当前字符为对称轴左侧字符的偶数字符串，取最长的那个字符串。
	step3:将当前字符串对应的最大字符串与全局最大字符串比较，将最大的存入全局最大字符串。
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
	int pos = 0;
	string longestPal;
	//step1:循环遍历输入字符串中的每个字符。
	while (pos < len)
	{
		//step2:求以当前字符为对称中心的奇数回文字符串和以当前字符为对称轴左侧字符的偶数字符串，取最长的那个字符串。
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
			ppos++;
			//如果当前字符的最大回文字符串大于最大回文字符串，则重新给最大回文字符串longestPal赋值。
			if ((npos - ppos)>longestPal.size())
			{
				int k = 0;
				int j = ppos;
				for(; j <ppos+longestPal.size();j++)
				{
					longestPal[k] = s[j];
					k++;
				}
				for (; j < npos; j++)
				{
					longestPal += s[j];
					k++;
				}
			}
		}
		pos++;
	}
	return longestPal;
}

int main()
{
	string s = "ccc";
	cout << longestPalindrome(s);
}