// leetcode link:https://leetcode.com/problems/max-consecutive-ones/description
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
     {
        int maxe =0;
        int currnt_max = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                currnt_max++;
                maxe = max(currnt_max,maxe);
            }
            else
            {
                currnt_max =0;
            }
        }
        return maxe;
    }
};