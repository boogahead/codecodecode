class Solution {
public:
/*
logic : until we count the plants in between two seats , we dont have to count them since they cant be partitioned between other rooms
we just need to count the plants from the second time we see a Seat up until the next instance of chair and multiply
*/
    int MOD=1e9+7;
    int numberOfWays(string corridor) {
        int chairs=0;
        long answer=1;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                chairs++;//'First' chair found
                while(++i<corridor.length()&&corridor[i]!='S');
                //skip counting until we see a 'Second' Chair

                if(i<corridor.length()&&corridor[i]=='S'){
                    chairs++;
                    //found 'Second' chair
                }
                int untilnext=1;
                while(++i<corridor.length()&&corridor[i]!='S'){
                    untilnext++;
                    //counting number of plants between 'Second' chair and the next instance of chiar ( this will be the 'First' chair of next room)
                }

                if(untilnext>1&&i<corridor.length()){
                    //multiply the number of plants
                    answer=(answer*untilnext)%MOD;
                }
                i--;
            }

        }
        if(chairs==0)return 0;
        if(chairs%2)return 0;
        return (int)answer;
    }
};
