class Solution {
public:
    int fun(int i,int n,vector<int> &arr,vector<int> &dp){
        if(i==n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int sum=0;
        int ans=INT_MIN;
        for(int j=0;j<3;j++){
            if(i+j<n){

            sum+=arr[i+j];
            ans=max(ans,sum-fun(i+j+1,n,arr,dp));
            }
        }
        return dp[i]=ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n+1,-1);
        int dig=fun(0,n,stoneValue,dp);
        if(dig>0){
            return "Alice";
        }
        if(dig<0){
            return "Bob";
        }
        return "Tie";
    }
};