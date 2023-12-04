class Solution {
public:
    string largestGoodInteger(string num) {
        string answer="";
        for(int i=0;i<num.length()-2;i++){
            char cur=num[i];
            if(cur==num[i+1]&&cur==num[i+2]){
                string tmp;
                tmp+=cur;tmp+=cur;tmp+=cur;
                if(answer==""){
                    answer=tmp;continue;
                }
                if(stoi(answer)<stoi(tmp))answer=tmp;
            }
        }
        return answer;
    }
};
