#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  vector<int>answer;
  for (int testcase = 0; testcase < T; testcase++) {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if(x1==x2&&y1==y2&&r1==r2){
      answer.push_back(-1);continue;
    }
    //원점 사이의 거리
    double distance=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    double difference=abs(r2-r1);
    //두 점에서 만날때
    if(r1+r2>distance&&(difference<distance)){
      answer.push_back(2);continue;
    }
    //한점에서 만날ㄸ
      //원안 에 원 있을때 (원점사이의 거리==두 거리의 차이)
    if(distance==difference||r1+r2==distance){
      answer.push_back(1);continue;
    }answer.push_back(0);
  }
  for(auto i:answer)cout<<i<<"\n";
}
