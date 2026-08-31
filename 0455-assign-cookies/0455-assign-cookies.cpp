class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res=0;
        int i=0;
        int j=0;
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(i<n && j<m){
            if(s[j]>=g[i]){
                res++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return res;
    }
};