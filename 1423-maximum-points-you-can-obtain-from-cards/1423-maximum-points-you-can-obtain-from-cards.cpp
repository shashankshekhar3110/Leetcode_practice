class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int res=0;
        int curr =0;
        for(int i=0;i<k;i++){
            curr = curr+cardPoints[i];
        }
         res=curr;
        for(int i=1;i<=k;i++){
            curr -=  cardPoints[k-i];
            curr += cardPoints[n-i];

            res = max(res,curr);
            
        }
        return res;
    }
};