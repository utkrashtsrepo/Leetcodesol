class Solution {
public:
    void fun(string &tmp,vector<string> &res,int n,int idx,unordered_map<char,string> f,string s){ 
        if(idx==n){
            res.push_back(tmp);
            return;
        }
        string choice=f[s[idx]];
        for(int i=0;i<choice.size();i++){
            tmp.push_back(choice[i]);
            fun(tmp,res,n,idx+1,f,s);
            tmp.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        unordered_map <char,string> f;
        int n=digits.length();
        string tmp="";
        vector<string> res;
        f['2']="abc";
        f['3']="def";
        f['4']="ghi";
        f['5']="jkl";
        f['6']="mno";
        f['7']="pqrs";
        f['8']="tuv";
        f['9']="wxyz";
        fun(tmp,res,n,0,f,digits);
        return res;
    }
};