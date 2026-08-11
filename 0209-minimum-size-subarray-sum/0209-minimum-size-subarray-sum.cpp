class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len=INT_MAX;
        int r=0;int l=0;
        int sum=0;
        int n=nums.size();
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                len=min(len,r-l+1);
                 sum-=nums[l];
                l++;
            }
            
                r++;
            
        }
        if(len==INT_MAX){
            return 0;
            
        }
        return len;
    }
};