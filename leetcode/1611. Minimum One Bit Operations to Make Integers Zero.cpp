class Solution {
public:
    /*
    equivalent to graycode index
    int 0 = gray code 0
    int 1 = gray code 1
    int 6 = gray code 4
    int 9 = gray code 14 ....
    consider the given n as a gray code and change them back to int

    */
    int minimumOneBitOperations(int n) {
        int answer=0;
        while(n>0){
            answer^=n;
            n=n>>1;
        }
        return answer;
    }
};
