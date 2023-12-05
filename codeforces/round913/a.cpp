#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <climits>

using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for(int testcase=0;testcase<tc;testcase++){
        string position;
        cin>>position;
        vector<string>answer;
        char alphabet=position[0];
        char number=position[1];
        for(char i=alphabet-1;i>='a';i--){
            string tmp="";
            tmp+=i;tmp+=number;
            answer.push_back(tmp);
        }
        for(char i=alphabet+1;i<='h';i++){
            string tmp="";
            tmp+=i;tmp+=number;
            answer.push_back(tmp);
        }
        for(char i='1';i<='8';i++){
            if(i==number)continue;
            string tmp="";
            tmp+=alphabet;tmp+=i;
            answer.push_back(tmp);
        }
        for(auto i:answer)cout<<i<<"\n";
    }
}
