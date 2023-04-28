class Solution {
public:
    vector<int>table;
    vector<int>rank;
    int finder(int a)
    {
        if(a==table[a])return a;
        return table[a]=finder(table[a]);
    }
    void merger(int a,int b)
    {
        int xa=finder(a),xb=finder(b);
        if(xa==xb)return;
        if(rank[xa]>rank[xb])swap(xa,xb);
        table[xa]=xb;
        if(rank[xa]==rank[xb])rank[xb]++;
    }
    bool checker(vector<string>&strs,int a,int b,int& length)
    {
        int diff=0;
        for(int i=0;i<length;i++)
        {
            if(strs[a][i]!=strs[b][i])diff++;
        }if(diff==2||diff==0)return true;
        return false;
    }
    int numSimilarGroups(vector<string>& strs) {
        int length=strs[0].length();
        int answer=strs.size();
        table.resize(strs.size());rank.resize(strs.size(),0);
        for(int i=0;i<table.size();i++)table[i]=i;
        for(int idx=0;idx<strs.size();idx++)
        {
            for(int jdx=idx+1;jdx<strs.size();jdx++)
            {
                if(finder(idx)!=finder(jdx))
                {
                    if(checker(strs,idx,jdx,length))
                    {
                        answer--;
                        merger(idx,jdx);
                    }
                }
            }
        }
        return answer;
    }
};
