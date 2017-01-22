//19ms,beats 37.29%
/*问题描述：Given an array S of n integers,
find three integers in S such that the sum is closest to a given number,target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
算法实现逻辑：按照no15的算法实现逻辑，做进一步调整。
算法提升：一定还存在更高效的实现逻辑。
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//一定要采取措施避免重复的操作。
class ThreeSumClose
{
public:
	int threeSumClose(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		int closeTar=0, minDist=2147483647;//注意一定要赋初值。
		int len = nums.size();
		if (len <= 2)
			return 0;
		for (int i = 0; i < len-2; i++)
		{
			int j = i + 1;
			int k = len - 1;
			while (j < k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				if (sum > target)
				{
					if ((sum - target) < minDist)
					{
						minDist = sum - target;
						closeTar = sum;
					}
					k--;
					while (j < k && nums[k] == nums[k + 1])
						k--;
				}
				else if (sum < target)
				{
					if ((target - sum) < minDist)
					{
						minDist = target - sum;
						closeTar = sum;
					}
					j++;
					while (j < k && nums[j] == nums[j - 1])
						j++;
				}
				else
					return target;
			}
			while (i < len - 3 && nums[i] == nums[i + 1])
				i++;
		}
		return closeTar;
	}
};
int main()
{
	vector<int> nums = { 0,1,2};
	int target = 1;
	ThreeSumClose tsc;
	int closeTar;
	closeTar = tsc.threeSumClose(nums, target);
	cout << closeTar << endl;
}