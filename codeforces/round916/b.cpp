#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <climits>
#include <deque>
#include <stack>


using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for(int testcase=0;testcase<tc;testcase++){
        int n,k;
        cin>>n>>k;
        deque<int>problem;
        queue<int>solve;
        for(int i=n;i>=1;i--)problem.push_back(i);
        for(int i=0;i<k;i++){
            solve.push(problem.back());
            problem.pop_back();
        }
        while(!solve.empty()){
            cout<<solve.front()<<" ";
            solve.pop();
        }
        while(!problem.empty()){
            cout<<problem.front()<<" ";
            problem.pop_front();
        }
        cout<<"\n";
    }    
}
