#include<iostream>
#include<string>
#include<vector>
using namespace std;
//��ÿһ��extendsԪ��������Ӧ��assist�����ֵ������������assistֵ��
int getPalinLen(vector<int> &assist, string extends)
{
	int mx=0;//mx����ָʾ�ѷ��ʵ��ַ��У�ӵ�����һ����ַ������ַ���ű�š�
	int longest = 0;//longest����ָʾ�ѷ����ַ��У�ӵ���������ַ������ȵ��ַ���š�
	assist.push_back(1);//��һ��Ԫ�ػ����ַ�����С��ԶΪһ��
	for (int i = 1; i < extends.size(); i++)
	{
		//step1:�ж�i�Ƿ�������õĻ����ַ����ı߽��ڣ������ұ߽����Ƚϡ�
		//step2:�ж�i����ӵ�����ұ߽��Ԫ��mx�ԳƵ�Ԫ�صĻ����ַ�����û��Խ�硣
		int ppos, npos;
		if (assist[i - 1] > assist[longest])//������ѭ����д�����һ��Ԫ�صķ�������𣿲��á�
			longest =i-1;
		int mxn = mx + assist[mx] - 1;//mxn����ָʾ���ұ߽硣
		if (i < mxn)
		{
			int j = 2 * mx - i;//jΪ��i����mx���ĶԳƵ�Ԫ�ر�š�
			int in = assist[j] + i - 1;//inΪ����i��jӵ����ͬ�Ļ����ַ���������£�i���ұ߽������
			//��ʵin���ұ߽�ıȽ�ֵ�����൱��j����߽�ıȽ�ֵ��
			//��j�ڱ߽��ڣ���i�Ļ����ַ���һ������j
			//��jԽ���߽磬��i�Ļ����ַ�����СΪ��i���ұ߽���ַ�������
			//��j��߽��غϣ���i�Ļ����ַ�����СҪͨ���������ʱ߽���Ԫ������á�
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
	//��ԭ�ַ���Ԥ���������в����ַ���#����������ֻ��Ҫ��extends�ַ�����ÿ���ַ�Ϊ�Գ����ĵĻ����ַ�����С��
	string extends;
	int k = 0;
	for (int i = 0; i < s.size(); i++)
	{
		extends += '#';
		extends += s[i];
	}
	extends += '#';
	//assistֵ�Ĵ�СΪ������Ԫ�ؿ�ʼ��������Ϊ���ĵĻ����ַ������ұ߽߱�λ�ã��ַ��ĸ�����
	//assist-1�������Ƕ�ԭ�ַ���s��Ӧ�Ļ����ַ�����С��
	vector<int> assist;
	int longest = getPalinLen(assist, extends);
	//��extends��longest��λ����ȷ��ԭ�ַ�����Ӧ�Ļ����ַ���λ�á�
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