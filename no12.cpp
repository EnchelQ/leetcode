//55ms beats 10.08%
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class IntToRoman{
public:
	string intToRoman(int num) {
		if (num > 3999)
		{
			return "";
		}
		
		string result;

		//数字转换逻辑,还存在另外一种不转换为字符的逻辑实现，见NO12-2
		vector<char> mainC = { 'M', 'C', 'X', 'I' };
		vector<char> assisC = { ' ', 'D', 'L', 'V' };
		/*string one = "IXCM";
		string five = "VLD";*/
		string strNum = to_string(num);
		int len = strNum.size();
		for (int i = 0; i < len; i++)
		{
	
			if (strNum[i] == '9')
				//	result += mainC[4 - len+i] + mainC[3 - len+i];
			{
				result += mainC[4 - len + i];
				result += mainC[3 - len + i];
			}
			else
				result += transFunc(strNum[i], mainC[4 - len+i], assisC[4 - len+i]);
		}

		return result;
	}
private:
	//从1~8的罗马数字表示规则。
	string transFunc(char num, char mainC, char assisC)
	{
		string result;
		switch (num)
		{
		case '1':
		case '2':
		case '3':
		{
			result.append(num-48, mainC);
			break;
		}
		case '4':
		{
			result += mainC;
			result+=assisC;
			break;
		}
		case '5':
		case '6':
		case '7':
		case '8':
		{
			result += assisC;
			result.append(num - 53, mainC);
			break;
		}
		/*case '9':
			result += preMain + mainC;*/
		default:
			break;
		}
		return result;
	}
};
int main()
{
	int num = 894;
	IntToRoman f;
	string roman = f.intToRoman(num);
	cout << roman;

}