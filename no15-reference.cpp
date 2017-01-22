//39ms beats93.24%
//À„∑®¿¥‘¥£∫http://www.aichengxu.com/view/45729
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class ThreeSum
{
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > ret;
		int len = num.size();
		int tar = 0;

		if (len <= 2)
			return ret;

		sort(num.begin(), num.end());

		for (int i = 0; i <= len - 3; i++) {
			// first number : num[i]
			int j = i + 1;	// second number
			int k = len - 1;	// third number
			while (j < k) {
				if (num[i] + num[j] + num[k] < tar) {
					++j;
				}
				else if (num[i] + num[j] + num[k] > tar) {
					--k;
				}
				else {
					ret.push_back({ num[i], num[j], num[k] });
					++j;
					--k;
					// folowing 3 while can avoid the duplications
					while (j < k && num[j] == num[j - 1])
						++j;
					while (j < k && num[k] == num[k + 1])
						--k;
				}
			}
			while (i <= len - 3 && num[i] == num[i + 1])
				++i;
		}

		// sort and unique will cost a lot of time and course TLE
		// sort(ret.begin(), ret.end());
		// ret.erase(unique(ret.begin(), ret.end()), ret.end());
		return ret;
	}
};
int main()
{
	vector<int> nums = { -1, 0, 1, 2, -1, -4 };
	ThreeSum three;

	vector<vector<int>> triplets = three.threeSum(nums);
	for (int i = 0; i < triplets.size(); i++)
	{
		for (auto x : triplets[i])
			cout << x << " ";
		cout << endl;
	}
}