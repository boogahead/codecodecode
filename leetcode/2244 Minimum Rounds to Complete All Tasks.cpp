class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
       unordered_map<int,int> mpmp;
       int size=tasks.size();
       int i,j;
       for(i=0;i<size;i++)
       {
           mpmp[tasks[i]]++;
       } 
       for(i=0;i<mpmp.size();i++)
       {
           cout<<mpmp[tasks[i]]<<" ";
       } 
       int cnt=0;
       for(i=0;i<mpmp.size();i++)
       {
           if((mpmp[i]-(mpmp[i]/3)*3)%2==1)
            {
                if(mpmp[i]%2==0)
                {
                    cnt+=mpmp[i]/2;continue;
                }
                return -1;
            }
           cnt+=mpmp[i]/3;
           if((mpmp[i]-(mpmp[i]/3)*3)!=0){cnt++;}
       }
       return cnt;
    }
};
