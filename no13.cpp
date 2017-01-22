//65ms beats34.64%
/*
����������
leetcode��13��
��һ�������ַ�ת��������
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
class RomanIntoInt
{
public:
	int romanIntoInt(string s)
	{
		int result=0;
		//ʵ���߼������ַ����еĵ�ǰ�ַ�����һ���ַ����бȽϣ������һ���ַ���Ӧ��ֵ���ڵ�ǰ�ַ���Ӧ��ֵ�����ȥ��ǰ�ַ���IV��,���򣬼��ϵ�ǰ�ַ���VI����
		//�Ľ��㷨������Ч�ʵ����룺1.map����switch��䡣2.����һ���߼�ʵ��˼·��
		map<char, int> trans = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
		unsigned pos = 0, nextPos = 1;
		for (; nextPos != s.size(); pos++, nextPos++)
		{
			char currentC = toCapital(s[pos]);
			char nextC = toCapital(s[nextPos]);
			//�ж������ַ��Ƿ���Ч��
			if (trans.find(currentC) == trans.end() || trans.find(nextC) == trans.end())
			{
				cout << "invalid string";
				return 0;
			}

			if (trans[currentC] < trans[nextC])
				result -= trans[currentC];
			else
				result += trans[currentC];
		}
		result += trans[toCapital(s[pos])];
		return result;
	}
private:
	//������ͳһת��Ϊ��д��ĸ
	char toCapital(char c)
	{
		if (c >= 97)
			c -= 32;
		return c;
	}
};
int main()
{
	string s = "daxxi";
	RomanIntoInt transF;
	int result = transF.romanIntoInt(s);
	cout << result;
}