#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N,M;
    cin>>N>>M;
    set<string>list;
    for(int i=0;i<N;i++){
        string tmp;
        cin>>tmp;
        list.insert(tmp);
    }
    priority_queue<string,vector<string>,greater<string>>pq;
    for(int i=0;i<M;i++){
        string tmp;
        cin>>tmp;
        if(list.find(tmp)!=list.end()){
            pq.push(tmp);
        }
    }
    cout<<pq.size()<<"\n";
    while(!pq.empty()){
        cout<<pq.top()<<"\n";
        pq.pop();
    }
}
