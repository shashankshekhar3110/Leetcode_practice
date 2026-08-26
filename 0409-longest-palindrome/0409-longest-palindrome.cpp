class Solution {
public:
    int longestPalindrome(string s) {
        int count[256] = {0};

        for (char c : s) {
            count[c]++;
        }

        int length = 0;
        bool odd = false;

        for (int i = 0; i < 256; i++) {
            length += (count[i] / 2) * 2;

            if (count[i] % 2 == 1) {
                odd = true;
            }
        }

        if (odd)
            length++;

        return length;
    }
};