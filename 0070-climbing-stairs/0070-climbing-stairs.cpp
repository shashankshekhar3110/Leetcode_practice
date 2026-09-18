class Solution {
public:
    int cstairsMem(int n,vector<int>&dp){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]= cstairsMem(n-1,dp) + cstairsMem(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return cstairsMem(n,dp);
    }
};