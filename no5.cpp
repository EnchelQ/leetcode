/*
�������������������ַ�����
�������������
	step1:ѭ�����������ַ����е�ÿ���ַ���
	step2:���Ե�ǰ�ַ�Ϊ�Գ����ĵ����������ַ������Ե�ǰ�ַ�Ϊ�Գ�������ַ���ż���ַ�������¼��Ļ����ַ������ȼ�����λ�á�
	step3:������Ļ����ַ������ȼ�����λ��ȷ��������ַ���
�������ʱ�临�Ӷ�O(n^2).
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
	int longest = 0, maxLong = 0;//longest����ָʾӵ���������ַ����������ַ�λ�ã�maxLong����ָʾ�������ַ������ȡ�
	//step1:ѭ�����������ַ����е�ÿ���ַ���
	while (pos < len)
	{
//	step2:���Ե�ǰ�ַ�Ϊ�Գ����ĵ����������ַ������Ե�ǰ�ַ�Ϊ�Գ�������ַ���ż���ַ�������¼��Ļ����ַ������ȼ�����λ�á�
		for (int i = -1; i < 1; i++)
		{
			int ppos = pos + i;//��i=-1��i=0��ʱ���Ӧ�������
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