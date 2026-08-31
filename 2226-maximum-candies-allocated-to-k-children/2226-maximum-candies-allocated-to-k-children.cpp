class Solution {
public:
    bool isval(vector<int>& candies, int mid, long long k) {
    long long cnt = 0;

    for (int x : candies) {
        cnt += x / mid;

        if (cnt >= k)
            return true;
    }

    return false;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int s=0;
        for(int i=0;i<candies.size();i++){
            s=max(s,candies[i]);
        }
        int l=1;
        int r=s;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(isval(candies,mid,k)){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return r;
    }
};