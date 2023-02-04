class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>s1table(26,0);
        vector<int>s2table(26,0);
        int s1size=s1.length();
        int s2size=s2.length();
        if(s1size>s2size)return false;
        int i;
        for(i=0;i<s1size;i++)
        {
            s1table[s1[i]-'a']++;
        }
        for(i=0;i<s1size;i++)
        {
            s2table[s2[i]-'a']++;
        }
        i--;
        while(i<s2size)
        {
            if(s1table==s2table)return true;
            s2table[s2[i-s1size+1]-'a']--;
            i++;
            if(i>=s2size)break;
            s2table[s2[i]-'a']++;
        }
        return false;
    }
};
