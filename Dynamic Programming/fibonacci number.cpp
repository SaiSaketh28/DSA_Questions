// gfg link:https://practice.geeksforgeeks.org/problems/introduction-to-dp/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=introduction-to-dp
int mod = 1e9 +7;
long long int dp[100001];
class Solution {
    private:
    long long int topDownHelper(int n, vector<long long int> &dp){
        if(n <= 1) return n;
        
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = (topDownHelper(n-1, dp) + topDownHelper(n-2, dp)) % mod;
    }
  public:
    long long int topDown(int n) {
        vector<long long int> dpt(n+1, -1);
        return topDownHelper(n, dpt);
    }
    long long int bottomUp(int n) {
        vector<long long int>arr(n+1,0);
        arr[0] = 0;
        arr[1] = 1;
        for(int i=2;i<=n;i++)
        {
            arr[i] = (arr[i-1] + arr[i-2])%mod;
        }
        return arr[n];
    }
};