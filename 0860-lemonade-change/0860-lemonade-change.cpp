class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int five=0;
        int ten=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five==0){
                    return 0;
                }
                ten++;
                five--;
            }
            else{
                if(ten>0){
                    ten--;
                    if(five==0){
                        return 0;
                    }
                    five--;
                }
                else {
                    if(five<3){
                    return 0;
                    }
                    five=five-3;
                }
            }
        }
        return true;
    }
};