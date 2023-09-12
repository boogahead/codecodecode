#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <cmath>
#include <climits>
#include <map>
#include <tuple>
#include <queue>

using namespace std;
typedef struct pair<int,int>info;
struct compare{
    bool operator()(info a,info b){
        return a>b;
    }
};
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<bool>taken(n);
    priority_queue<info,vector<info>,compare>reversepq;
    priority_queue<info>pq;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        reversepq.push({tmp,i});
        pq.push({tmp,i});
    }
    int Sung=0,Park=0;
    for(int i=0;i<n;i++){
        if(i%2==1){
            while(taken[reversepq.top().second]){
                reversepq.pop();
            }
            Sung+=reversepq.top().first;
            //cout<<"SUNG "<<reversepq.top().first<<"\n";
            taken[reversepq.top().second];
            reversepq.pop();
        }
        else{
            while(taken[pq.top().second]){
                pq.pop();
            }
            Park+=pq.top().first;
            //cout<<"Park "<<pq.top().first<<"\n";
            taken[pq.top().second];
            pq.pop();
        }
    }
    cout<<Sung<<" "<<Park<<"\n";
}
