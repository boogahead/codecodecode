#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <utility>
using namespace std;
int n,r,c;
long long answer=0;
void divide(int curi,int curj,int size){
    if(curi==r&&curj==c){
        cout<<answer;
        return;
    }
    if(r<curi+size&&r>=curi&&c<curj+size&&c>=curj){
        divide(curi,curj,size/2);
        divide(curi,curj+size/2,size/2);
        divide(curi+size/2,curj,size/2);
        divide(curi+size/2,curj+size/2,size/2);
    }
    else{
        answer+=size*size;
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>r>>c;
    divide(0,0,pow(2,n));
}
