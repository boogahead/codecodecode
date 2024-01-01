class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int answer=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int finder=0;

        int sidx=0,gidx=0;
        while(gidx<g.size()&&sidx<s.size()){
            if(s[sidx]>=g[gidx]){
                gidx++;sidx++;answer++;continue;
            }sidx++;
        }

        return answer;
    }
};
