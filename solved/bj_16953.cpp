#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;
long long answer=-1;
typedef pair<long long,long long>info;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long a,b;
    cin>>a>>b;
    queue<info>qq;
    qq.push({a,1});
    while(!qq.empty()){
        info tmp=qq.front();qq.pop();
        if(tmp.first==b){
            answer=tmp.second;break;
        }
        long long timestwo=tmp.first*2;
        long long plusone=tmp.first*10+1;
        if(timestwo<=b)qq.push({timestwo,tmp.second+1});
        if(plusone<=b)qq.push({plusone,tmp.second+1});
    }
    cout<<answer;
}
