class Solution {
public:
    int maxScore(string s) {
        int left=0,right=0;
        if(s[0]-'0'==0)left++;
        for(int i=1;i<s.length();i++){
            if(s[i]-'0'==1)right++;
        }
        int answer=left+right;
        for(int i=1;i<s.length()-1;i++){
            if(s[i]-'0'==1)right--;
            else left++;
            answer=max(answer,right+left);
        }
        return answer;
    }
};
