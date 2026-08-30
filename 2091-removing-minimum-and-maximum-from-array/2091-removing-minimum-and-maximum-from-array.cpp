class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int k=0;
        int j=0;
        int minn=INT_MAX;
        int maxx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minn){
                minn=nums[i];
                j=i;
            }
            if(nums[i]>maxx){
                maxx=nums[i];
                k=i;
            }
        }
        int n=nums.size();
        int a=min(k,j);
        int b=max(k,j);
        int left=b+1;
        int right=n-a;
        int both=(a+1)+(n-b);
        return min(left,min(both,right));
    }
};