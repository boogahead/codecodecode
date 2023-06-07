class Solution {
public:
    int minFlips(int a, int b, int c) {
        stack<int> aa,bb,cc;
        int maxsize=-1;
        if(a==b&&b==c)return 0;
        while(c!=0)
        {
            cc.push(c%2);c/=2;
        }
        maxsize=max((int)cc.size(),maxsize);
        while(a!=0)
        {
            aa.push(a%2);a/=2;
        }
        maxsize=max((int)aa.size(),maxsize);
        while(b!=0)
        {
            bb.push(b%2);b/=2;
        }
        maxsize=max((int)bb.size(),maxsize);
        while(aa.size()!=maxsize)aa.push(0);
        while(bb.size()!=maxsize)bb.push(0);
        while(cc.size()!=maxsize)cc.push(0);
        int answer=0;
        while(!cc.empty())
        {
            int atop=aa.top(),btop=bb.top(),ctop=cc.top();
            //cout<<atop<<" "<<btop<<" "<<ctop<<"\n";
            aa.pop();bb.pop();cc.pop();
            if(atop==btop&&btop==ctop)continue;
            if(atop==btop&&ctop==1)
            {//cout<<"cc";
                answer++;continue;
            }
            if(atop!=btop&&(ctop==0))
            {//cout<<"aa";
                answer++;continue;
            }
            if(atop==1&&btop==1&&ctop==0)
            {//cout<<"bb";
                answer+=2;continue;
            }
        }
        return answer;
    }
};
