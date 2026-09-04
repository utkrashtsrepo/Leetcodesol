class Solution {
public:
    bool check(vector<int> &a,int m,int k,int pass){
        int n=a.size();
        vector<int> isflower(n,0);
        for(int i=0;i<a.size();i++){
            if(a[i]<=pass)
                isflower[i]=1;
        }
        int cnt=0;
        int bq=0;
        for(int i=0;i<a.size();i++){
            if(isflower[i]==1){
                cnt++;
                if(cnt==k){
                    bq++;
                    cnt=0.;
                    if(bq>=m)
                    return true;
                }
            }
            else 
            cnt=0;
        }
        return false;

    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l=INT_MAX;
        int r=INT_MIN;
        int ans=-1;
        if(1LL*k*m>bloomDay.size()){
            return -1;
        }
        for(int i=0;i<bloomDay.size();i++){
            l=min(l,bloomDay[i]);
            r=max(r,bloomDay[i]);
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(bloomDay,m,k,mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }

        }
        return ans;
    }
};