class Solution {
public:
    // int editDistance(string word1,string word2,int m,int n){
    //     if(m==0) return n;
    //     if(n==0) return m;
    //     if(word1[m-1]==word2[n-1]){
    //         return editDistance(word1,word2,m-1,n-1);
    //     }
    //     else{
    //         return 1 + min(editDistance(word1,word2,m,n-1),
    //         min(editDistance(word1,word2,m-1,n),
    //         editDistance(word1,word2,m-1,n-1)));
    //     }
    // }
        int editMem(string word1,string word2,int m,int n,vector<vector<int>>&dp){
            if(m==0) return n;
            if(n==0) return m;
            if(dp[m][n]!=-1){
                return dp[m][n];
            }
            if(word1[m-1]==word2[n-1]){
                return dp[m][n]= editMem(word1,word2,m-1,n-1,dp);
        }
        else{
            return dp[m][n]=1 + min(editMem(word1,word2,m,n-1,dp),
            min(editMem(word1,word2,m-1,n,dp),
            editMem(word1,word2,m-1,n-1,dp)));
        }
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        //return editDistance(word1,word2,m,n);
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return editMem(word1,word2,m,n,dp);
    }
};