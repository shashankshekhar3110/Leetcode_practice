class Solution {
public:
    int solverec(vector<int>& nums,int curr,int prev){
        if(curr >= nums.size()){
            return 0;
        }
        int include=0 ;
        if(prev ==-1 || nums[curr]>nums[prev]){
            include = 1+ solverec(nums,curr+1,curr);
        }
            int exclude=0;
            exclude=0+solverec(nums,curr+1,prev);

        int finalans =max(include,exclude);
        return finalans;

    }
    int solvemem(vector<int>&nums,int curr,int prev,vector<vector<int>>&dp){
        if(curr >= nums.size()){
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int include=0 ;
        if(prev ==-1 || nums[curr]>nums[prev]){
            include = 1+ solvemem(nums,curr+1,curr,dp);
        }
            int exclude=0;
            exclude=0+solvemem(nums,curr+1,prev,dp);

        dp[curr][prev+1] =max(include,exclude);
        return dp[curr][prev+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        //return solverec(nums,0,-1);
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solvemem(nums,0,-1,dp);
    }
};