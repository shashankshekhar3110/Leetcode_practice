class Solution {
public:
    int digitSum(int n) {
        int sum = 0;

        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({digitSum(nums[i]), nums[i]});
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> position;

        for (int i = 0; i < n; i++) {
            position[arr[i].second] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || position[nums[i]] == i) {
                continue;
            }

            int j = i;
            int cycleSize = 0;

            while (!visited[j]) {
                visited[j] = true;
                cycleSize++;

                j = position[nums[j]];
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
};
