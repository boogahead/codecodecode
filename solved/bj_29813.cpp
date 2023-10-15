#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>

using namespace std;
typedef pair<string,int>info;//initial number
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    deque<info>table;
    for(int i=0;i<n;i++){
        string init;
        int hakbun;
        cin>>init>>hakbun;
        table.push_back({init,hakbun});
    }
    while(table.size()>1){
        info turn=table.front();table.pop_front();
        int times=turn.second;
        for(int i=1;i<times;i++){
            table.push_back(table.front());
            table.pop_front();
        }
        table.pop_front();
    }
    cout<<table.front().first;
}
