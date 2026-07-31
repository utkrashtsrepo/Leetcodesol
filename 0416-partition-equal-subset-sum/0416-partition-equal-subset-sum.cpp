class Solution {
public:
    bool fun(int i,int n,int sum,vector<int> &nums,vector<vector<int>> &dp){
        if(i==n){
            if(sum==0){
                return true;
            }
            return false;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        if(nums[i]>sum){
            return dp[i][sum]=fun(i+1,n,sum,nums,dp);
        }
        return dp[i][sum]=fun(i+1,n,sum-nums[i],nums,dp) || fun(i+1,n,sum,nums,dp);

    }
    bool canPartition(vector<int>& nums) {
       int n=nums.size();
        
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        sum=sum/2;
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return fun(0,n,sum,nums,dp);
    }
};