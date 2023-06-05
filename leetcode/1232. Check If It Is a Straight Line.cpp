class Solution {
public:
    typedef pair<int,int>info;
    int gcd(int a,int b)
    {
        if(b==0)return a;
        return gcd(b,a%b);
    }
    info getreduced(int dy,int dx)
    {
        int g=gcd(abs(dy),abs(dx));
        bool sign=(dy<0)^(dx<0); //checks if either one of the numbers are negative
        if(sign)
            return make_pair(abs(dx)/g,-abs(dy)/g);
        else
            return make_pair(abs(dx)/g,abs(dy)/g); //divide each coordinates with the gcd to get reduced form
    }
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()==2)return true;
        bool xflat=true;
        for(int i=1;i<coordinates.size();i++)
        {
            if(coordinates[i][0]!=coordinates[i-1][0]){xflat=false;break;}
        }
        if(xflat)return true;
        info gijun=getreduced(coordinates[0][1]-coordinates[1][1],coordinates[0][0]-coordinates[1][0]);
        //cout<<"gijun "<<gijun.first<<" "<<gijun.second<<"\n";
        for(int i=2;i<coordinates.size();i++)
        {
            info tmp=getreduced(coordinates[0][1]-coordinates[i][1],coordinates[0][0]-coordinates[i][0]);
            //cout<<tmp.first<<" "<<tmp.second<<"\n";
            if(tmp.first!=gijun.first||tmp.second!=gijun.second)return false;
        }
        return true;
    }
};
