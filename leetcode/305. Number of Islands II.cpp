/*Union Find
https://leetcode.com/problems/number-of-islands-ii/solutions/3033683/number-of-islands-ii/?orderBy=most_votes
*/
class Solution {
public:
    int dirx[4]={1,0,-1,0};
    int diry[4]={0,1,0,-1};
    int count=0;
    int find(int i,vector<int>& parents)
    {
        if(parents[i]!=i)
        {
            parents[i]=find(parents[i],parents);
        }
        return parents[i];
    }
    void uni(int i,int j,vector<int>& parents,vector<int>& rank)
    {
        int iset=find(i,parents), jset=find(j,parents);
        if(iset==jset)return;
        else if(rank[iset]<rank[jset])
        {
            parents[iset]=jset;
        }
        else if(rank[iset]>rank[jset])
        {
            parents[jset]=iset;
        }
        else
        {
            parents[jset]=iset;
            rank[iset]++;
        }
        count--;
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int>parents(m*n,-1);
        vector<int>rank(m*n,0);

        vector<int>answer;
        //visited[positions[0][0]][positions[0][1]]=1;
        int y,x;
        for(auto i:positions)
        {
            y=i[0];x=i[1];
            int pos=y*n+x;
            if(parents[pos]<0)
            {
                parents[pos]=y*n+x;count++;
            }
            for(int g=0;g<4;g++)
            {
                int cury=y+diry[g],curx=x+dirx[g];
                int curneighbor=cury*n+curx;
                if(cury>=0&&cury<m&&curx>=0&&curx<n)
                {
                    if(parents[curneighbor]>=0)
                    {
                        uni(pos,curneighbor,parents,rank);
                    }
                }
            }
            answer.push_back(count);
        }
        return answer;
    }
};
