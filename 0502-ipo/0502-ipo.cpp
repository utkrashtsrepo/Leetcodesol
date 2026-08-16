class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        vector<pair<int,int>> arr;

        for(int i=0;i<capital.size();i++){
            int x=profits[i];
            int y=capital[i];
            pair<int,int> p={y,x};
            arr.push_back(p);
        }
        int n=arr.size();
        sort(arr.begin(),arr.end());
       int idx=0;
        while(k--){
            
            while(idx<n){
                if(arr[idx].first>w){
                    break;
                }
                pq.push(arr[idx].second);
                idx++;
            }
            if(pq.empty()){
                return w;
            }
            int prof=pq.top();
            pq.pop();
            w+=prof;
        }
        return w;
    
    }
};