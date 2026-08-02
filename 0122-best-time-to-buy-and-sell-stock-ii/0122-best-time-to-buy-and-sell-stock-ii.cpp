class Solution {
public:
    int fun(int i,int k,int n,vector<int>&a,vector<vector<int>> &dp){
        if(k==0 || i==n){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        if(k==2){
            //buy or leave
            int c1=fun(i+1,k-1,n,a,dp)-a[i];
            int c2=fun(i+1,k,n,a,dp);
            return dp[i][k]=max(c1,c2);
        }
        if(k==1){
            int c1=fun(i+1,k+1,n,a,dp)+a[i];
            int c2=fun(i+1,k,n,a,dp);
            return dp[i][k]=max(c1,c2);
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        int k=2;
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        return fun(0,k,n,prices,dp);
    }
};