class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int prefmax=INT_MIN;
        int prefmin=INT_MAX;
        int n=nums.size();
        vector<int> ma(n,INT_MIN);
        vector<int> mi(n,INT_MAX);
        int cnt=-1;
        for(int i=0;i<n;i++){
            prefmax=max(prefmax,nums[i]);
            ma[i]=prefmax;
            
        }
        for(int i=n-1;i>=0;i--){
        prefmin=min(prefmin,nums[i]);
        mi[i]=prefmin;
        }
        for(int i=0;i<n;i++){
            if((ma[i]-mi[i])<=k){
                return i;
            }
        }
        return cnt;
    }
};