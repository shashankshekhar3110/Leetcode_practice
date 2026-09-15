class Solution {
public:

    int solve(vector<int>& nums, int size, int index)
    {
        if(index >= size){
            return 0;
        }

        int option1 = nums[index] + solve(nums, size, index + 2);

        int option2 = solve(nums, size, index + 1);

        return max(option1, option2);
    }

    int SolveMem(vector<int>& nums, int index, vector<int>& dp)
    {
        int size = nums.size();

        if(index >= size){
            return 0;
        }

        if(dp[index] != -1){
            return dp[index];
        }

        int option1 = nums[index] + SolveMem(nums, index + 2, dp);

        int option2 = SolveMem(nums, index + 1, dp);

        dp[index] = max(option1, option2);

        return dp[index];
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;

        vector<int> dp(size + 1, -1);

        return SolveMem(nums, index, dp);
    }
};