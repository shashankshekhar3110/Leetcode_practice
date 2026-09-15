class Solution {
public:
    int solveRec(vector<int>& coins,int n,int sum) {
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        if(n==0) return 0;

        int exclude = solveRec(coins,n-1,sum);
        int include = solveRec(coins,n,sum -coins[n-1]);

        return exclude + include;
    }
    int solvemem(vector<int>& coins,int n, int sum, vector<vector<int>>&dp)
    {
        if(sum == 0) return 1;
        if(sum < 0) return 0;
        if(n==0) return 0;
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }

        int exclude = solvemem(coins,n-1,sum,dp);
        int include = solvemem(coins,n,sum -coins[n-1],dp);

        dp[n][sum]= exclude + include;
        return dp[n][sum];
    }
    int change(int amount,vector<int>& coins){
        //return solveRec(coins,coins.size(),amount);
        int n=coins.size();
        //solveRec(coins,n,amount);
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solvemem(coins,n,amount,dp);

    }
};