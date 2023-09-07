#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <climits>
#include <math.h>
#include <tuple>
#include <queue>
#include <stack>

using namespace std;
int answer=0;
bool checkforsurvivor(vector<vector<int>>&table,int curegg){
    for(int i=0;i<table.size();i++){
        if(i==curegg)continue;
        if(table[i][0]==1)return true;
    }
    return false;
}
void go(vector<vector<int>>&table,int curegg,int crackcount){
    if(curegg==table.size()){
        //cout<<curegg<<"\n";
        /*for(auto i:table){
            cout<<i[0]<<" ";
        }cout<<"\n\n";*/
        answer=max(answer,crackcount);return;
    }
    if(!checkforsurvivor(table,curegg)||table[curegg][0]==0){
        //cout<<"???????\n";
        go(table,curegg+1,crackcount);return;
    }
    for(int i=0;i<table.size();i++){
        int tmpcrackcount=crackcount;
        if(i==curegg)continue;
        if(table[i][0]==1){
            //cout<<curegg<<" attempts at "<<i<<"\n";
            table[i][1]-=table[curegg][2];
            table[curegg][1]-=table[i][2];
            if(table[i][1]<=0){
                tmpcrackcount++;table[i][0]=0;
            }
            if(table[curegg][1]<=0){
                tmpcrackcount++;table[curegg][0]=0;
            }
            go(table,curegg+1,tmpcrackcount);
            table[i][1]+=table[curegg][2];
            table[curegg][1]+=table[i][2];
            table[i][0]=1;table[curegg][0]=1;
        }
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<int>>table(n,vector<int>(3));
    /*
    table[i][0] = 1 if not cracked 1 if cracked
    table[i][1] = durability
    table[i][2] = weight
    */
    for(int i=0;i<n;i++){
        cin>>table[i][1]>>table[i][2];
        table[i][0]=1;
    }
    go(table,0,0);
    cout<<answer<<"\n";
}
