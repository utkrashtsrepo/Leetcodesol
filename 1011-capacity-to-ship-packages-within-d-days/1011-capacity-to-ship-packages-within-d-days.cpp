class Solution {
public:
    bool isval(vector<int>&weights,int cap,int days){
        int c=0;
        int cnt=0;
        for(int i=0;i<weights.size()-1;i++){
            c+=weights[i];
            if(c+weights[i+1]>cap){
            c=0;
            cnt++;
            }
        }
        if(cnt<days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        int l=0;
        for(int i=0;i<weights.size();i++){
            s+=weights[i];
            l=max(l,weights[i]);
        }
        //int l=0;
        int r=s;
        int mid=l+(r-l)/2;
        while(l<r){
            if(isval(weights,mid,days)){
                r=mid;
            }
            else{
                l=mid+1;
            }
            mid=l+(r-l)/2;
        }
        return l;
    }
};