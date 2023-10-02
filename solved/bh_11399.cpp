#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;
struct compare{
    bool operator()(int a,int b){
        return a>b;
    }
};
int main(void){
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    priority_queue<int,vector<int>,compare>pq;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        pq.push(tmp);
    }
    long long answer=0;
    long long cumul=0;
    while(!pq.empty()){
        cumul+=pq.top();
        answer+=cumul;
        //cout<<cumul<<"\n";
        pq.pop();
    }
    cout<<answer;
}
