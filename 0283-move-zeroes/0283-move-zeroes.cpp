class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int start = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != 0) {
                swap(nums[start], nums[i]);
                start++;
            }
        }
    }
};