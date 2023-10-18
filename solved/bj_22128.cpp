#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    deque<int>table;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        table.push_back(tmp);
    }
    sort(table.begin(),table.end());
    int count=0;
    while(true){
        if(table.size()==1)break;
        count++;
        table.front()--;
        int realback,backminone;
        realback=table.back();table.pop_back();
        backminone=table.back();table.pop_back();
        backminone+=realback;
        table.push_back(backminone);
        if(table.front()==0)table.pop_front();
    }
    cout<<count;
}
