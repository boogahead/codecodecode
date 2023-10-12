#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
void recursion(vector<int>&candidate,int M,int curidx,int no,vector<int>&numbers){
    if(curidx==M){
        for(auto i:candidate){
            cout<<i<<" ";
        }cout<<"\n";return;
    }
    for(int i=no;i<numbers.size();i++){
        candidate[curidx]=numbers[i];
        recursion(candidate,M,curidx+1,i,numbers);
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N,M;
    cin>>N>>M;
    vector<int>numbers(N);
    for(int i=0;i<N;i++){
        cin>>numbers[i];
    }
    sort(numbers.begin(),numbers.end());
    vector<int>candidate(M);
    recursion(candidate,M,0,0,numbers);
}
