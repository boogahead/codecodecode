class Solution {
public:
    int numberOfSpecialSubstrings(string s) {
        int answer=0;
        for(int i=0;i<s.length();i++){
            vector<bool>check(26);
            for(int j=i;j<s.length();j++){
                if(check[s[j]-'a'])break;
                check[s[j]-'a']=true;
                answer++;
            }
        }
        return answer;
    }
};
