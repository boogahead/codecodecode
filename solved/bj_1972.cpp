#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
struct compare{
    bool operator()(int a,int b){
        return a>b;
    }
};
int main(void){
    int n;
    cin>>n;
    priority_queue<int,vector<int>,compare>pq;
    vector<int>answer;
    for(int i=0;i<n;i++){
        int command;
        cin>>command;
        if(command==0&&pq.size()==0){
            answer.push_back(0);continue;
        }
        else if(command==0&&pq.size()!=0){
            answer.push_back(pq.top());pq.pop();continue;
        }
        pq.push(command);
    }
    for(auto i:answer)cout<<i<<"\n";
}
