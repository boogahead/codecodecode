#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <climits>
#include <deque>

using namespace std;
typedef pair<char,int>info;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    //cout<<tc<<"\n";
    for(int testcase=0;testcase<tc;testcase++){
        string input;
        cin>>input;
        deque<info>lower;
        deque<info>upper;
        int counter=0;
        for(auto i:input){
            if(i=='b'){
                if(!lower.empty()){
                    lower.pop_back();
                }
            }
            else if(i=='B'){
                if(!upper.empty()){
                    upper.pop_back();
                }
            }
            else{
                if(i>='a'&&i<='z'){
                    lower.push_back({i,counter++});
                }
                else{
                    upper.push_back({i,counter++});
                }
            }
        }
        string answer="";
        while(!lower.empty()&&!upper.empty()){
            if(lower.front().second<upper.front().second){
                answer+=lower.front().first;lower.pop_front();
            }
            else {
                answer+=upper.front().first;upper.pop_front();
            }
        }
        if(lower.empty()){
            while(!upper.empty()){
                answer+=upper.front().first;upper.pop_front();
            }
        }
        if(upper.empty()){
            while(!lower.empty()){
                answer+=lower.front().first;lower.pop_front();
            }
        }
        cout<<answer<<"\n";
    }
}
