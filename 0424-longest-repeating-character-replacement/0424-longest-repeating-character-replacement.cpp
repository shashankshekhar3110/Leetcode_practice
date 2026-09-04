class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxfreq=0;
        int ans=0;
        vector<int> freq(256,0);
        for(int right=0;right<s.length();right++){
            freq[s[right]]++;

            maxfreq = max(maxfreq,freq[s[right]]);
            while((right-left +1) - maxfreq > k){
                freq[s[left]]--;
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};