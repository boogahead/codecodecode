#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> st;
    int cnt;
    cin>>cnt;
    while(cnt--)
    {
        string cmd;
        cin>>cmd;
        if(cmd=="push")
        {
            int val;
            cin>>val;
            st.push(val);
        }
        else if(cmd=="pop")
        {
            if(st.empty()){cout<<-1<<"\n";}
            else
            {
                cout<<(int)st.top()<<"\n";
                st.pop();
            }
        }
        else if(cmd=="size")
        {
            cout<<st.size()<<"\n";
        }
        else if(cmd=="empty")
        {
            if(st.empty())
            {
                cout<<1<<"\n";
            }
            else
            {
                cout<<0<<"\n";
            }
        }
        else if(cmd=="top")
        {
            if(st.empty()){cout<<-1<<"\n";}
            else
            {
                cout<<(int)st.top()<<"\n";
            }
        }
    }
}
