class Solution {
public:
    int answer=0;
    int numberOfMatches(int n) {
        if(n==1)return answer;
        if(n%2){
            answer++;
            answer+=n/2;
            return numberOfMatches(n/2);
        }
        else{
            answer+=n/2;
            return numberOfMatches(n/2);
        }
    }
};
