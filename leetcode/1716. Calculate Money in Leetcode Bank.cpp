class Solution {
public:
    int totalMoney(int n) {
        int weeks=n/7;
        int extradays=n%7;
        int answer=0;
        if(weeks>0){
            for(int i=1;i<=weeks;i++){
                answer+=28;
                answer+=7*(i-1);
            }
        }
        int adddays=1+weeks;
        for(int i=0;i<extradays;i++){
            answer+=adddays++;
        }
        return answer;
    }
};
