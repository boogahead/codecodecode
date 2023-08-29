class Solution {
public:
    int bestClosingTime(string customers) {
        int closingtime=0;
        int minpenalty;
        int penalty=0;
        for(auto i:customers){
            if(i=='Y')penalty++;
        }
        minpenalty=penalty;
        for(int i=1;i<=customers.length();i++){
            int curpenalty=penalty;
            if(customers[i-1]=='Y'){
                curpenalty--;
            }
            else{
                curpenalty++;
            }
            //cout<<i<<" "<<curpenalty<<"\n";
            if(curpenalty<minpenalty){
                closingtime=i;minpenalty=curpenalty;
            }
            penalty=curpenalty;
        }
        return closingtime;
    }
};
