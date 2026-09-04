class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> freq;
        unordered_map <char,int> free;
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]]++;
            free[tasks[i]]=1;
        }
        for(auto it: freq){
            pq.push({it.second,it.first});
        }
        int seat=1;
        while(!pq.empty()){
            vector<pair<int,char>> pulled;
            while(!pq.empty()){
                pair<int,char> p=pq.top();
                pq.pop();
                if(seat>=free[p.second]){
                    if(p.first>1){
                        pq.push({p.first-1,p.second});
                    }
                    free[p.second]=free[p.second]+n+1;
                    break;
                }
                else{
                    pulled.push_back(p);
                }
            }
            for(int i=0;i<pulled.size();i++){
                pq.push(pulled[i]);
            }
            seat++;
        }
        return seat-1;
    }
};