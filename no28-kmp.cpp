/*
6ms,beats 13.5%
Problem Description:Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack
Solution:Regard this problem as match between two strings, the needle is the pattern.
	So the next is KMP algorithm solution.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
void getPrefixFun(string needle, vector<int> &pi)
{
	pi.push_back(0);
	int k = 0;//stand for the current position should be compared, or the size of matched prefix.
	for (int i = 1; i < needle.size(); i++)
	{
		//search for right prefix;
		while (k > 0 && needle[k] != needle[i])
			k = pi[k-1];//error occurs when expression is	k=pi[k-1]
		if (needle[k] == needle[i])
			k++;
		pi.push_back(k);
	}
}
int strStr(string haystack, string needle)
{
	vector<int> pi;
	getPrefixFun(needle, pi);
	int k = 0;
	for (int i = 0; i < haystack.size(); i++)
	{
		while (k > 0 && needle[k] != haystack[i])
			k = pi[k-1];//error occurs when expression is	k=pi[k-1]
		if (needle[k] == haystack[i])
			k++;
		if (k == needle.size())
		{ 
			return i - k + 1;
		}
	}
	return -1;
}
int main()
{
	string s = "mississippi";
	string ss = "issip";
	int res = strStr(s, ss);
	cout << res << endl;
}