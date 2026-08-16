class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        string res="";
        int seat=0;
        while(!pq.empty()){
            pair<int,char> p=pq.top();
            pq.pop();
            if(res=="" || res.back()!=p.second){
                res.push_back(p.second);
                seat++;
                p.first--;
                if(p.first>0)
                pq.push(p);
            }
            else{
                if(pq.empty()){
                    return "";
                }
                pair<int,char> p2=pq.top();
                pq.pop();
                res.push_back(p2.second);
                seat++;
                p2.first--;
                if(p2.first>0)
                pq.push(p2);
                pq.push(p);

            }
        }
        return res;
    }
};