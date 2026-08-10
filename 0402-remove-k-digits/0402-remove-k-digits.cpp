class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        st.push(num[0]);
        for(int i=1;i<num.length();i++){
            while(!st.empty() && k >0 && num[i]<st.top()){
                
                    st.pop();
                   
                    k--;
                
            }
            st.push(num[i]);
        }
        string res="";
          while (k > 0) {
            st.pop();
            k--;
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
       
        reverse(res.begin(),res.end());
        int i=0;
        while(i<res.size() && res[i]=='0'){
            i++;
        }
        if(res.substr(i)=="" || res==""){
            return "0";
        }
        return res.substr(i);
    }
};