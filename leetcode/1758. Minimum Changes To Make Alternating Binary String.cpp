class Solution {
public:
    int minOperations(string s) {
        int one=0,zero=0;
        int cur=1,alt=0;
        for(auto i:s){
            if(cur!=i-'0'){one++;}
            if(alt!=i-'0'){zero++;}
            alt^=1;cur^=1;
        }
        return min(one,zero);
    }
};
