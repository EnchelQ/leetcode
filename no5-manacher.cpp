#include<iostream>
#include<string>
#include<vector>
using namespace std;
//对每一个extends元素求出其对应的assist数组的值，并返回最大的assist值。
int getPalinLen(vector<int> &assist, string extends)
{
	int mx=0;//mx用来指示已访问的字符中，拥有最右回文字符串的字符编号编号。
	int longest = 0;//longest用来指示已访问字符中，拥有最大回文字符串长度的字符编号。
	assist.push_back(1);//第一个元素回文字符串大小永远为一。
	for (int i = 1; i < extends.size(); i++)
	{
		//step1:判断i是否在以求得的回文字符串的边界内，用最右边界来比较。
		//step2:判断i关于拥有最右边界的元素mx对称的元素的回文字符串有没有越界。
		int ppos, npos;
		if (assist[i - 1] > assist[longest])//还用在循环外写对最后一个元素的访问情况吗？不用。
			longest =i-1;
		int mxn = mx + assist[mx] - 1;//mxn用来指示最右边界。
		if (i < mxn)
		{
			int j = 2 * mx - i;//j为与i关于mx中心对称的元素标号。
			int in = assist[j] + i - 1;//in为假设i与j拥有相同的回文字符串的情况下，i的右边界情况。
			//其实in与右边界的比较值，就相当于j与左边界的比较值。
			//若j在边界内，则i的回文字符串一定等于j
			//若j越过边界，则i的回文字符串大小为从i到右边界的字符个数。
			//若j与边界重合，则i的回文字符串大小要通过继续访问边界外元素来获得。
			if (in<mxn)
			{
				assist.push_back(assist[j]);
				continue;
			}				
			else if (in>mxn)
			{
				assist.push_back(mxn - i + 1);
				continue;
			}
			else
			{
				 ppos = i - assist[j];
				 npos = mxn + 1;
				
			}
		}
		else
		{
			 ppos = i - 1;
			 npos = i + 1;
		}

		while (ppos >= 0 && npos<extends.size() && extends[ppos] == extends[npos])
		{
			ppos--;
			npos++;
		}
		mx = i;
		assist.push_back( npos - i);
	}
	return longest;
}

string longestPalindrome(string s)
{
	//对原字符串预处理，在其中插入字符‘#’，问题变成只需要求extends字符串以每个字符为对称中心的回文字符串大小。
	string extends;
	int k = 0;
	for (int i = 0; i < s.size(); i++)
	{
		extends += '#';
		extends += s[i];
	}
	extends += '#';
	//assist值的大小为从中心元素开始，到以他为中心的回文字符串的右边边界位置，字符的个数。
	//assist-1的正好是对原字符串s对应的回文字符串大小。
	vector<int> assist;
	int longest = getPalinLen(assist, extends);
	//由extends中longest的位置来确定原字符串对应的回文字符串位置。
	int len = assist[longest];
	int ppos = (longest - len + 1)/2;
	int npos = (longest + len - 3)/2;
	string result;
	for (int i = ppos; i <= npos;i++)
		result += s[i];
	return result;
}
int main()
{
	string s = "skjehiuihehiuihej";
	cout << longestPalindrome(s);
}