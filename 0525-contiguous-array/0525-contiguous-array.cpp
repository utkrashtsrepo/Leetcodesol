class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int z=0;int o=0;
        unordered_map<int,int> mp;
        int diff=z-o;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z++;
            }
            else{
                o++;
            }
            diff=z-o;
            if(diff==0){
                res=max(res,i+1);
            }
            if(mp.find(diff)!=mp.end()){
                res=max(res,i-mp[diff]);
            }
            else{
                mp[diff]=i;
            }
        }
        return res;
    }
};