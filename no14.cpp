//12ms beats 2.69%
/*
�������������ַ�������������ǰ׺��
�������⣺�󼯺ϵ���󹫹��Ӽ�	�� ���ַ������������������С�
ʵ���߼������÷����㷨˼�룬�õݹ麯������⡣
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class LongestCommonPrefix {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		if (strs.size() == 1)
			return strs[0];
		if (strs.size() == 2)
		{
			string s1 = strs[0], s2 = strs[1];
			string lcp = commonPrefixOfTwo(s1, s2);
			return lcp;
		}
		//���ʱ�ĵط���
		vector<string> subStrs1, subStrs2;
		for (unsigned pos = 0; pos < strs.size() / 2; pos++)
		{
			subStrs1.push_back(strs[pos]);
		}
		for (unsigned pos = strs.size()/2; pos < strs.size(); pos++)
		{
			subStrs2.push_back(strs[pos]);
		}
		string s1 = longestCommonPrefix(subStrs1);
		string s2 = longestCommonPrefix(subStrs2);
		string lcp = commonPrefixOfTwo(s1, s2);
		return lcp;
	}
private:
	string commonPrefixOfTwo(string s1, string s2)
	{
		string lcp;
		unsigned pos = 0;
		for (; pos < s1.size() && pos < s2.size(); pos++)
		{
			if (s1[pos] != s2[pos])
				break;
			lcp += s1[pos];
		}
		return lcp;
	}
};
int main()
{
	vector<string> strs = { "hello", "hellowe","hell29ei", "hellswe" };
	LongestCommonPrefix LCP;
	string result = LCP.longestCommonPrefix(strs);
	cout << result;
}