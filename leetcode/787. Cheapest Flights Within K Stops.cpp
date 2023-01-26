/*
Use belmman-ford + DP 
*/
class Solution {
    public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>>table(n+2,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++) //table[i][j] = reach point j in i stops
        {
            table[i][src]=0; //always zero since reaching the source from source is always zero
        }

        for(int i=1;i<=k+1;i++)//iterate k+1 times because its bellman ford
        {
            for(auto &f:flights) //go through each 1d vector of the 2dvector flights
            {
                int u=f[0],v=f[1],w=f[2]; //accessing from , to , and price respectively
                if(table[i-1][u]!=INT_MAX) // if reaching the starting point (from) has been reached, 
                {
                    table[i][v]=min(table[i][v],table[i-1][u]+w); 
                }
            }
        }
        if(table[k+1][dst]==INT_MAX)return -1; //cannot be reached
        return table[k+1][dst];
    }
};
