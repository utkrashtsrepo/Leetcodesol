class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int l=0;int r=0;
        int len=INT_MIN;
        for(r;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                mp[nums[l]]--;
                l++;
            }
            len=max(len,r-l+1);
        }
        return len;
    }
};