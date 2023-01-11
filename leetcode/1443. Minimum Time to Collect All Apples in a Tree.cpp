class Solution {
public:
/*밑에서 싹 긁어다가 올라가는것
if문을 두어 hasApple이면 왔다갔다하는 간선 두개를 추가. 그리고 tmp>0이라는 내 밑에 있는 자식들이 hasApple 해당되는것들의 수를 측정하여 만약 currentnode가 hasApple 아니더라도 자식들 방문하기위해 부모한테 왔다갔다 해야하므로 +2 를 하여 올라가는것*/
    int depths(int prev,int curnode, vector<bool>& hasApple,vector<vector<int>>& table)
    {
        int ans=0;
        int tmp;
        for(auto i : table[curnode])
        {
            if(i!=prev)
            {
                tmp=depths(curnode,i,hasApple,table);
                if(tmp>0||hasApple[i]){ans+=(tmp+2);}
            }
        }
        return ans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int i;
        vector<vector<int>> table(n); //n row 개의 vector을 만든다. 이때 각 row마다 사이즈가 1로 되어있으니 조심.
        for(i=0;i<edges.size();i++)
        {
            table[edges[i][0]].push_back(edges[i][1]);
            table[edges[i][1]].push_back(edges[i][0]);
        }   
        
        return depths(-1,0,hasApple,table);
    }
};
