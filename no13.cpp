//65ms beats34.64%
/*
问题描述：
leetcode第13题
将一串罗马字符转换成数字
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
		//实现逻辑：对字符串中的当前字符与下一个字符进行比较，如果下一个字符对应的值大于当前字符对应的值，则减去当前字符（IV）,否则，加上当前字符（VI）；
		//改进算法，提升效率的设想：1.map换成switch语句。2.另外一种逻辑实现思路。
		map<char, int> trans = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
		unsigned pos = 0, nextPos = 1;
		for (; nextPos != s.size(); pos++, nextPos++)
		{
			char currentC = toCapital(s[pos]);
			char nextC = toCapital(s[nextPos]);
			//判定输入字符是否有效。
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
	//将输入统一转换为大写字母
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