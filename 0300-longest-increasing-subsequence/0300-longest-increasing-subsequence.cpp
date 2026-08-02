class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    res[i]=max(res[i],res[j]+1);
                }
            }
        }
        int ans=1;
        
        for(int k:res){
            ans=max(ans,k);
        }
        return ans;
    }
};