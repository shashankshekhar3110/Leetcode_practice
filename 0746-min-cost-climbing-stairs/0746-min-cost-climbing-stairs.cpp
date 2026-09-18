class Solution {
public:

    int solve(vector<int>& cost, int i) {

        if (i >= cost.size())
            return 0;

        int oneStep = solve(cost, i + 1);
        int twoStep = solve(cost, i + 2);

        return cost[i] + min(oneStep, twoStep);
    }
    int solveMem(vector<int>&cost,int i,vector<int>&dp){
        if (i >= cost.size())
            return 0;
        if(dp[i]!=-1){
            return dp[i];
        }

        int oneStep = solveMem(cost, i + 1,dp);
        int twoStep = solveMem(cost, i + 2,dp);

        return dp[i]= cost[i] + min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {

        //return min(solve(cost, 0), solve(cost, 1));
        vector<int>dp(cost.size(),-1);
        return min(solveMem(cost, 0, dp),
               solveMem(cost, 1, dp));
    }
};