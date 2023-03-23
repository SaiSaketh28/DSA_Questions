// Leetcode link: https://leetcode.com/problems/majority-element/description
// O(2*N + logN)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>map;
        for(int i=0;i<nums.size();i++)
        {
            if(map.find(nums[i]) != map.end())
            {
                map[nums[i]] = map[nums[i]] +1;
            }
            else
            {
                map[nums[i]] =1;
            }
        }
        auto it = map.begin();
        while(it != map.end())
        {
            if(it->second > (nums.size()/2))
            {  
                break;
            }
            it++;
        }
        return it->first;
    }
};