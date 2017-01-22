class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int iPos=0,cur=0;
        while(cur<nums.size())
        {
            int temp= nums[cur];
            nums[iPos]=temp;
            iPos++;
            int i=cur+1;
            while(i<nums.size() && nums[i]==temp)
            {
                i++;
            }
            cur=i;
        }
        return iPos;
    }
};