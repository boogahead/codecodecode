#include <iostream>
#include <list>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
int main(void)
{
    //commands that makes cin cout operations faster
    ios::sync_with_stdio(0);
    cin.tie(0);
    //////////////////////////////////////////////////

    string s;
    //char string[100000];
    //scanf("%s",string);
    cin >> s; //receives string input
    list<char> L(s.begin(),s.end());//elegant way of initializing list with given string
    list<char>::iterator tmp;//cursor
    //for(int i=0;i<strlen(string);i++)
    //{
    //    L.push_back(string[i]);
    //}
    tmp=L.end();//point cursor to the end
    int count;
    //scanf("%d",&count);
    cin>>count;
    int i=0;
    while(count--)
    {
        char cmd;
        char addi;
        //scanf(" %c",&cmd);
        cin>>cmd;
        if(cmd=='L')
        {
            if(tmp!=L.begin())
                tmp--;
        }
        else if(cmd=='D')
        {
            if(tmp!=L.end())
                tmp++;
        }
        else if(cmd=='B')
        {
            if(tmp!=L.begin())
            {
                tmp--;
                tmp=L.erase(tmp);
            }
        }
        else if(cmd=='P')
        {
            char addi;
            //scanf(" %c",&addi);
            cin>>addi;
            L.insert(tmp,addi);
        }
    }
    for(list<char>::iterator it=L.begin();it!=L.end();it++)
    {
        printf("%c",*it);
    }
    return 0;
}
