 // leetcode link: https://leetcode.com/problems/rotate-image/description
 // My Approach : 1. First swap elements of i,j and j,i
 //               2. Then reverse every row
 class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        map<pair<int,int>,int>map;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map.find(make_pair(i,j)) == map.end())
                {
                    swap(matrix[i][j],matrix[j][i]);
                    map[{i,j}] = matrix[i][j];
                    map[{j,i}] = matrix[j][i];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};