class Solution {
public:
    typedef tuple<int,int,int>info;//cost,start,end
    vector<int>rank,parent;
    void init(int n){
        for(int i=0;i<=n;i++){
            rank[i]=1;
            parent[i]=i;
        }
    }
    int find(int a){
        if(a==parent[a])return a;
        return parent[a]=find(parent[a]);
    }
    void merge(int a,int b){
        a=find(a);b=find(b);
        if(a==b)return;
        if(rank[a]>rank[b])swap(a,b);
        parent[a]=b;
        if(rank[a]==rank[b])rank[b]++;
    }
    struct cmp{
        bool operator()(info a,info b){
            return get<0>(a)>get<0>(b);
        }
    };
    int minimumCost(int n, vector<vector<int>>& connections) {
        priority_queue<info,vector<info>,cmp>pq;
        int answer=0;
        parent.resize(n+1);rank.resize(n+1);
        for(auto i:connections){
            //cout<<i[2]<<" "<<i[0]<<" "<<i[1]<<"\n";
            info tmp=make_tuple(i[2],i[0],i[1]);
            pq.push(tmp);
        }
        init(n);
        //return answer;
        while(!pq.empty()){
            info tmp=pq.top();pq.pop();
            int curcost=get<0>(tmp);
            int curstart=get<1>(tmp);
            int curend=get<2>(tmp);
            if(find(curstart)==find(curend))continue;
            answer+=curcost;
            merge(curstart,curend);
        }
        /*for(int i=1;i<=n;i++){
            cout<<parent[i]<<" ";
        }*/
        for(int i=2;i<=n;i++){
            if(find(parent[i])!=find(parent[i-1]))return -1;
        }
        return answer;
    }
};
