class Solution {
public:
    int lcs(string &text1,string & text2, int m,int n){
        if(m==0 || n==0)
            return 0;

        if(text1[m-1]==text2[n-1]){
            return 1 + lcs(text1,text2,m-1,n-1);
        }
        else{
            return  max (lcs(text1 ,text2,m-1,n),
                        lcs(text1,text2,m,n-1));                   
        }
    }
    int lcsMem( string &text1, string& text2,int m,int n,vector<vector<int>>&dp){
        if(m==0 || n==0)
            return 0;
            if(dp[m][n]!=-1){
                return dp[m][n];
            }

        if(text1[m-1]==text2[n-1]){
            return dp[m][n]= 1 + lcsMem(text1,text2,m-1,n-1,dp);
        }
        else{
            return dp[m][n]= max (lcsMem(text1 ,text2,m,n-1,dp),
                        lcsMem(text1,text2,m-1,n,dp));                   
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        //return lcs(text1,text2,m,n);
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return lcsMem(text1,text2,m,n,dp);
    }
};