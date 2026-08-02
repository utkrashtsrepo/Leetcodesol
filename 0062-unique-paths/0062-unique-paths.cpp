class Solution {
public:
    int fun(int i,int j,int n,int m,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==m-1){
            return dp[i][j]=fun(i,j+1,n,m,dp);
        }
        if(j==n-1){
            return dp[i][j]=fun(i+1,j,n,m,dp);
        }
        return dp[i][j]=fun(i+1,j,n,m,dp)+fun(i,j+1,n,m,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return fun(0,0,n,m,dp);
    }
};