class Solution {
public:
    int modder=1000000007;
    int numMusicPlaylists(int n, int goal, int k) {
        int answer=n;
        int count=1;
        vector<vector<long>>table(goal+1,vector<long>(n+1,0));
        table[0][0]=1;
        for(int i=1;i<=goal;i++){
            for(int j=1;j<=min(i,n);j++){
                table[i][j]=table[i-1][j-1]*(n-(j-1))%modder;
                if(j>k){
                    table[i][j]=(table[i][j]+table[i-1][j]*(j-k))%modder;
                }
            }
        }
        return table[goal][n];
    }
};
/*
DP
create a table that goes up until table[goal][n] <- combination of " goal " length playlist using " n " music
two cases possibl
    1. play a new song
        to achieve this, we compute from table[n-1][j-1] <- j-1 meaning j-1 unique music used
        adding a song creates a new playlist of length n
        and adding a unique song creates j, therefore table[n][j]
        from j-1 unique songs, the number of unique songs we can add are n-(k-1) 
        multiply n-(k-1) with table[n-1][j-1]
        
    2. play an old song
        because of the value k, there are cases when we have to play old songs
        since there are no change in number of unique songs
        we come from table[n-1][j]
        multiply this by j-k , which is the number of possible songs available after considering the constraint

    add both of these cases to table[n][j]
    reach the end
    
*/
