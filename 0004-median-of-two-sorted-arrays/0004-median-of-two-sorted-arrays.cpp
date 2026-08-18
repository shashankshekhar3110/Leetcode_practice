class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int> nums;

        int left = 0;
        int right = 0;

        while (left < nums1.size() && right < nums2.size()) {

            if (nums1[left] <= nums2[right]) {
                nums.push_back(nums1[left]);
                left++;
            }
            else {
                nums.push_back(nums2[right]);
                right++;
            }
        }

        while (left < nums1.size()) {
            nums.push_back(nums1[left]);
            left++;
        }

        while (right < nums2.size()) {
            nums.push_back(nums2[right]);
            right++;
        }

        int n = nums.size();

        if (n % 2 == 0) {
            return ((double)nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        }
        else {
            return (double)nums[n / 2];
        }
    }
};