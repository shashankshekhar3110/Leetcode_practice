class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        
        int sumA = 0, sumB = 0;

  
        for(int x : aliceSizes)
            sumA += x;

        for(int x : bobSizes)
            sumB += x;

      
        unordered_set<int> bob;

        for(int x : bobSizes)
            bob.insert(x);

        
        int diff = (sumA - sumB) / 2;

       
        for(int a : aliceSizes) {
            int b = a - diff;

            if(bob.count(b)) {
                return {a, b};
            }
        }

        return {};
    }
};