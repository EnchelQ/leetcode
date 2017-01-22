/*
�������������������ַ�����
�������������
	step1:ѭ�����������ַ����е�ÿ���ַ���
	step2:���Ե�ǰ�ַ�Ϊ�Գ����ĵ����������ַ������Ե�ǰ�ַ�Ϊ�Գ�������ַ���ż���ַ�����ȡ����Ǹ��ַ�����
	step3:����ǰ�ַ�����Ӧ������ַ�����ȫ������ַ����Ƚϣ������Ĵ���ȫ������ַ�����
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
	int pos = 0;
	string longestPal;
	//step1:ѭ�����������ַ����е�ÿ���ַ���
	while (pos < len)
	{
		//step2:���Ե�ǰ�ַ�Ϊ�Գ����ĵ����������ַ������Ե�ǰ�ַ�Ϊ�Գ�������ַ���ż���ַ�����ȡ����Ǹ��ַ�����
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
			ppos++;
			//�����ǰ�ַ����������ַ��������������ַ����������¸��������ַ���longestPal��ֵ��
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