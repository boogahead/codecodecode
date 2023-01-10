//https://school.programmers.co.kr/learn/courses/30/lessons/92335?language=cpp#
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>
#include <math.h>
using namespace std;
bool isitprime(long long n)
{
    if(n<=1)return false;
    if(n==2)return true;
    if(n%2==0)return false;
    long long tmp=sqrt(n);
    //cout<<n<<"\n";
    for(long long i=3;i<=tmp;i+=2)
    {
        if(n%i==0)return false;
    }
    return true;
}
int solution(int n, int k) {
    bool nozero=true;
    int answer = -1;
    stack<int> pp;
    int tmpno=n;
    vector<int>dealwith;
    while(tmpno!=0)
    {
        pp.push(tmpno%k);
        tmpno/=k;
    }
    long long transfer=0;
    while(!pp.empty())
    {
        if(nozero){
            if(pp.top()==0){nozero=false;}
        }
        transfer= transfer*10 +pp.top();
        dealwith.push_back(pp.top());pp.pop();
    }
    int i;
    long long size=dealwith.size();
    if(nozero) //case P
    {
        if(isitprime(transfer))return 1;
        return 0;
    }
    long long tmptmp=0;
    long long cnt=0;
    for(i=0;i<=size;i++)
    {
        if(dealwith[i]==0||i>=size)
        {
            //cout<<i<<" ";
            if(tmptmp==0){continue;}
            //cout<<tmptmp<<"\n";
            if(isitprime(tmptmp))
            {
                cnt++;
            }
            tmptmp=0;
            continue;
        }//skip till reaching a non-zero number
        //cout<<i<<" ";
        tmptmp=tmptmp*10+dealwith[i];
    }
    return cnt;
}
