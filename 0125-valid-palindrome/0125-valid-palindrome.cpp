class Solution {
public:
    bool isPalindrome(string s) {
    string r="";
    for(int i=0;i<s.length();i++){
        if(s[i]>=97 && s[i]<=122){
            r+=s[i];
        }
        else if(s[i]>=65 && s[i]<=90){
            s[i]+=32;
            r+=s[i];
        }
        else if(s[i] >= 48 && s[i] <= 57) {
                r += s[i];
            }
    }
    int l=0;int ri=r.length()-1;
    while(l<ri){
        if(r[l]!=r[ri]){
            return 0;
        }
        l++;ri--;

    }
    return 1;
    }
};