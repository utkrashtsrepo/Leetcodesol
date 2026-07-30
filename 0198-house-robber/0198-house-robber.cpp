class Solution {
public:
int fun(int i,int n,int free,vector<int> &nums,vector<vector<int>> &dp){
    if(i==n){
        return 0;
    }
    if(dp[i][free]!=-1){
        return dp[i][free];
    }
    if(free==0){
        return dp[i][free]=fun(i+1,n,1,nums,dp);
    }
    
        int c1=nums[i]+fun(i+1,n,0,nums,dp);
        int c2=fun(i+1,n,1,nums,dp);
    
    return dp[i][free]=max(c1,c2);

}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return fun(0,n,1,nums,dp);
    }
};