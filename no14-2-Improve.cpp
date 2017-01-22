//6ms,beats18.07
/*
�������������ַ�������������ǰ׺��
�������⣺�󼯺ϵ���󹫹��Ӽ�	�� ���ַ������������������С�
ʵ���߼������صı�������㷨�������汾���������߼���Ϊ�ݹ���⡣
�ɻ����ֵݹ���õ����𡣣���һ�������¶��ϣ�һ�������϶��£���
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
		vector<string> lcps;
		auto piter = strs.begin();
		auto niter = piter;
		while (piter!=strs.end())
		{
			if ((piter + 1) == strs.end())
			{
				lcps.push_back(*piter);
				break;
			}
			niter++;
			string lcp = commonPrefixOfTwo(*piter,*niter);
			lcps.push_back(lcp);
			piter += 2;
			niter = piter;
		}
		string lcp = longestCommonPrefix(lcps);
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