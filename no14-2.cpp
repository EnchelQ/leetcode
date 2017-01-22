//6ms,beats18.07%
/*
问题描述：求字符串数组的最长公共前缀。
相似问题：求集合的最大公共子集	； 求字符串数组的最长公共子序列。
实现逻辑：保守的遍历求解算法
进一步提升效率的思路：将遍历逻辑改为反复两两求解。
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
		auto piter = strs.begin();
		string lcp = commonPrefixOfTwo(*piter, *(piter+1));
		for (piter+2; piter != strs.end(); piter++)
		{
			lcp = commonPrefixOfTwo(*piter, lcp);
		}
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
	vector<string> strs = { "hello", "hellowe", "hell29ei", "hellswe" };
	LongestCommonPrefix LCP;
	string result = LCP.longestCommonPrefix(strs);
	cout << result;

}