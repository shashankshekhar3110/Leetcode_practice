class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lp=0;
        int rp=n-1;
        int ans=0;
        while(lp<rp){
            int width=rp-lp;
            int ht=min(height[lp],height[rp]);
            int area=width*ht;
            ans=max(ans,area);

            if(height[lp]<height[rp]){
                lp++;
            }
            else{
                rp--;
            }
        }
        return ans;
    }
};