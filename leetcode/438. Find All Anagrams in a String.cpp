class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int analen=p.length();
        int slen=s.length();
        vector<int>palp(26,0);
        vector<int>salp(26,0);
        vector<int>answer;
        if(analen>slen)return answer; 
        for(int i=0;i<analen;i++)
        {
            palp[p[i]-'a']++;
        }
        int i;
        for( i=0;i<analen;i++)
        {
            salp[s[i]-'a']++;
        }
        i--;
        while(i<slen)
        {
            if(salp==palp){answer.push_back(i-analen+1);}
            salp[s[i-analen+1]-'a']--;
            i++;
            if(i>=slen)break;
            salp[s[i]-'a']++;
        }
        return answer;
    }
};
