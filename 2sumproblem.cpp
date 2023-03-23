// leetcode link:https://leetcode.com/problems/two-sum/description
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>map;
        for(int i=0;i<nums.size();i++)
        {
            map.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++)
        {   int rem;
         rem = target - (nums[i]);
            auto ip = map.find(rem);
            if(ip != map.end() && ip->second != i)
               {
                   return {ip->second,i};
               }
        }
     return {-1,-1};
    }
};