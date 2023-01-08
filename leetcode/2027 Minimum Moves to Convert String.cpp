class Solution {
public:
    int minimumMoves(string s) {
        int size=s.length();
        int i,j;
        int cnt=0;
        for(i=0;i<size;i++)
        {
            
                //cout<<i<<" ";
            if(s[i]=='X')
            {
                cnt++;
                /*for(j=i;j<i+3 && j<size;j++)
                {
                    //cout<<j<<"\n";
                    if(s[j]=='X'){s[j]='0';}
                }*/
                i+=2;
                
                //cout<<i<<" ";
            }
        }
        return cnt;
    }
};
