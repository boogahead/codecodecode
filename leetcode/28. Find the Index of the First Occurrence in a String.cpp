/*
현타오네요 ㅅㅂ KMP인데 왜틀리는지 모르겠음 ㅅㅂ

https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

이거보라니까 이거나 볼란다


*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        /*vector<int> f(haystack.size());
        int j=0;
        for(int i=1;i<haystack.size();i++)
        {
            while(j>0&&haystack[i]!=haystack[j])j=f[j-1];
            if(haystack[i]==haystack[j])f[i]=++j;
        }
        for(auto i:f)
        {
            cout<<i<<" ";
        }
        j=0;
        for(int i=0;i<haystack.size();i++)
        {
            while(j>0&&haystack[i]!=needle[j])j=f[j-1];
            if(haystack[i]==needle[j])j++;
            if(j==needle.size()){
                return i-needle.size()+1;}
        }
        return -1;*/
        return haystack.find(needle);
        //return(search(haystack.begin(),haystack.end(),boyer_moore_searcher(needle))-haystack.begin());
    }
};
