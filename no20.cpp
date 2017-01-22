//6ms,beats 3.2%
//问题1：给一个包含三种括号的字符串，判定输入的括号逻辑是不是有效。
//问题2：给定一个只包含三种括号的字符串，判定输入的括号逻辑是不是有效。
//解决思路：
//1.用栈实现表达式括号的逻辑
//2.在输入的字符串中如何做左括号和右括号的检测。
//3.在判定是右括号的情况下的匹配检测。
class Solution {
public:
    bool isValid(string s) {
        string leftBra="{([";
        string rightBra="})]";
        map<char,char> m={{'(',')'},{'[',']'},{'{','}'}};//左右括号匹配表
        stack<char> temp;
        for(auto c:s)
        {
			//先检测是不是输入左括号
            if (leftBra.find(c)!=string::npos)
                temp.push(c);
			//再检测是不是属于右括号
            else if(rightBra.find(c)!=string::npos)
            {
				//再检测括号是不是匹配
                if(temp.size()!=0 && c==m[temp.top()]) temp.pop();
                else return false;
            }
            else;
        }
        return temp.empty();
    }
};

class Solution {
public:
    bool isValid(string s) {
        map<char,char> m={{')','('},{']','['},{'}','{'}};
        stack<char> temp;
        for(auto c:s)
        {
            if (c=='(' || c=='[' || c=='{')
                temp.push(c);
            else if(m.count(c)==1)
            {
                if(!temp.empty() &&m[c]==temp.top())
                    temp.pop();
                else
                    return false;
            }
            else;
        }
        return temp.empty();
    }
};


//他人算法参考：
class Solution {  
public:  
    bool isValid(string s) {  
        if(s.length() == 0)  
        {  
            return true;  
        }  
  
        stack<char> st;  
        st.push(s[0]);  
  
        for(int i = 1; i < s.length(); ++i)  
        {  
            if(!st.empty() && isMatch(st.top(), s[i]))  
            {  
                st.pop();  
            }  
            else  
            {  
                st.push(s[i]); //这点不一样，它包括了不匹配入栈。 
            }  
        }  
  
        if(st.empty())  
        {  
            return true;  
        }  
        else  
        {  
            return false;  
        }  
    }  
  
    bool isMatch(char s, char p)  
    {  
        if((s == '(' && p == ')')  
        || (s == '{' && p == '}')  
        || (s == '[' && p == ']'))  
        {  
            return true;  
        }  
        else  
        {  
            return false;  
        }  
    }  
}; 

