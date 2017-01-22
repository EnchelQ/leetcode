/*
运行3ms,beats15.61%
问题：给n个括号对，要求自动生成所有的形成括号的形式
算法思路：
	针对1-2n的每个位置，选择能否填充‘(’,')'的依据是，判断是否左括号的个数大于右括号的个数。
解决方案：
	类似一个电话号码的字母组合问题，此问题可以组织成一个二叉树，二叉树的每一层代表1-2n中的一个位置，每个节点代表在该位置上的选择。要求的结果是从根节点到叶节点的所有遍历路径。
	所以，采用递归的方法，并且在递归函数中收集结果。
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string subStr;
        subGen(result,1,subStr+'(',n);
        return result;
    }
private:
    void subGen(vector<string> &result,int leftCount,string subStr,int n)
    {
        int len=subStr.size();
        if(leftCount==n)
        {
            for(int i=len;i<2*n;i++)
                subStr+=')';
            result.push_back(subStr);
            return;
        }
        subGen(result,leftCount+1,subStr+'(',n);
        if(leftCount>(len-leftCount))
            subGen(result,leftCount,subStr+')',n);
        return;
    }
};