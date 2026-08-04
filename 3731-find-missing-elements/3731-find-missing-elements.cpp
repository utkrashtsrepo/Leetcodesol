class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=nums[0];
        int n=nums.size();
        vector<int> res;
        int ans=-1;
        int range=nums[n-1]-nums[0]+1;
        vector<int> arr(range,-1);
        for(int i=0;i<n;i++){
            arr[nums[i]-start]=1;
        }
        for(int i=0;i<range;i++){
            if(arr[i]==-1){
                ans=i+start;
                res.push_back(ans);
            };
        }
        return res;
    }
};