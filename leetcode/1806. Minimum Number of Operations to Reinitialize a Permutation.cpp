class Solution {
public:
    set<vector<int>>yes;
    int answer=INT_MAX;
    vector<int>ult;
    void recursion(int&n, vector<int>cur,int step){
        //for(auto i:cur)cout<<i<<" ";
        //cout<<"\n";
        if(cur==ult){
            answer=min(answer,step);return;
        }
        if(yes.find(cur)!=yes.end()){return;}
        yes.insert(cur);
        vector<int>next(n);
        for(int i=0;i<n;i++){
            if(i%2==1)next[i]=cur[n/2+(i-1)/2];
            else if(i%2==0)next[i]=cur[i/2];
        }
        recursion(n,next,step+1);
    }

    int reinitializePermutation(int n) {
        vector<int>cur;
        for(int i=0;i<n;i++)cur.push_back(i);
        ult=cur;
        vector<int>next(n);
        for(int i=0;i<n;i++){
            if(i%2==1)next[i]=cur[n/2+(i-1)/2];
            else if(i%2==0)next[i]=cur[i/2];
        }
        recursion(n,next,1);
        return answer;
    }
};
