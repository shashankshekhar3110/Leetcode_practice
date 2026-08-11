class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         int n = nums.size();

        for (int first = 0; first < n; first++) {
            for (int second = first + 1; second < n; second++) {
                if (nums[first] + nums[second] == target) {
                    return {first, second};
                }
            }
        }

        return {};
    }
};