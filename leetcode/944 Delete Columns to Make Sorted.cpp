class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int i,j;
        int colsize=strs[0].size();
        int cnt=0;
        //cout<<strs.size()<<"\n"<<strs[0].size()<<"\n";
        //for(i=0;i<strs.size();i++)
        for(i=0;i<colsize;i++)
        {
            //bool skip=false;
           
            //for(j=0;j<colsize-1;j++)
            for(j=0;j<strs.size()-1;j++)
            {
               // cout<<strs[j][i]<<" "<<strs[j+1][i]<<" ";
                if(strs[j][i]>strs[j+1][i])
                {

                    //skip=true;
                    cnt++;
                    break;
                }
            }
            cout<<"\n";
        }
        return cnt;
    }
};
