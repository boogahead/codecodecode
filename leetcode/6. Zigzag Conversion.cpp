class Solution {
public:
    bool check(char a)
    {
        if(a>=65&&a<=90)return true;
        if(a>=97&&a<=122)return true;
        if(a==46||a==44)return true;
        return false;
    }
    string convert(string s, int numRows) {
        string answer;
        char table[1001][1001]={' '};
        if(numRows==1){return s;}
        if(numRows==2)
        {
            for(int i=0;i<s.size();i++)
            {
                table[i%2][i/2]=s[i];
            }
            for(int i=0;i<2;i++)
            {
                for(int j=0;j<1000;j++)
                {
                    if(check(table[i][j]))answer+=table[i][j];
                }
            }    
            return answer;
        }
        int diag=numRows-2;
        int vertcnt=0;
        int diagcnt=diag;
        int curx=0;
        int diagystart=numRows-2;
        int dx=1,dy=-1;
        for(int i=0;i<s.size();i++)
        {
            if(diagcnt==diag)
            {
                table[vertcnt++][curx]=s[i];
                if(vertcnt==numRows){diagcnt=0;curx++;continue;}
            }
            if(vertcnt==numRows)
            {//vertcnt=0;
                table[diagystart--][curx++]=s[i];
                diagcnt++;
                if(diagcnt==diag){diagystart=numRows-2;vertcnt=0;continue;}
            }
        }
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<=curx;j++)
            {
                //cout<<table[i][j];
                if(check(table[i][j]))answer+=table[i][j];
            }//cout<<"\n";
        }
        return answer;

    }
};
