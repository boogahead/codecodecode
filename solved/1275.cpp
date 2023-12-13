#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <cmath>
using namespace std;
vector<long long>SegmentTree;
vector<long long>number;
long long make_Segment_tree(int node,int start,int end){
    if(start==end)return SegmentTree[node]=(long long)number[start];
    int mid=(start+end)/2;
    long long left=make_Segment_tree(node*2,start,mid);
    long long right=make_Segment_tree(node*2+1,mid+1,end);
    return SegmentTree[node]=left+right;
}
long long calculate(int node,int start,int end,int left,int right){
    if(left>end||right<start)return 0;//범위 완전밖에있는경우 그냥 리턴
    if(left<=start&&end<=right)return SegmentTree[node];//범위안에 완전히 들어오는 경우 해당 노드값 리턴
    int mid=(start+end)/2;//아닌경우 왼쪽 오른쪽 자식노드로 내려가 더욱 검색
    long long left_result=calculate(node*2,start,mid,left,right);
    long long right_result=calculate(node*2+1,mid+1,end,left,right);
    return left_result+right_result;
}
void update(int node,int start,int end,int idx,long long difference){
    if(idx<start||idx>end)return;
    SegmentTree[node]+=difference;
    if(start!=end){
        int mid=(start+end)/2;
        update(node*2,start,mid,idx,difference);
        update(node*2+1,mid+1,end,idx,difference);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,q;
    cin>>n>>q;
    number.resize(n);
    for(int i=0;i<n;i++){
        cin>>number[i];
    }
    int tree_height=(int)ceil(log2(n));
    int tree_size=(1<<(tree_height+1));//seg tree 만드는 계산법
    SegmentTree.resize(tree_size);
    make_Segment_tree(1,0,n-1);//세그먼트 트리 만들기. idx 1 부터 시작할거므로 node 값이 1이다
    for(int i=0;i<q;i++){
        int x,y,b,a;
        cin>>x>>y>>a>>b;
        x--;y--;a--;//1번째 3번째 구간 합 구하라 해도 우리 array에서는 0idx 부터 시작하기때문에 1씩 빼준다
        if(x>y)swap(x,y);//구간계산할댸 편의를 위해 x가 크면 값 교체
        cout<<calculate(1,0,n-1,x,y);
        long long diff=b-number[a];//바꿔질 숫자와 바꿔야하는 수의 차를 구한다. 이는 나중에 segment tree의 다른 노드들에 대해 update 해야하기 때문
        number[a]=b;
        update(1,0,n-1,a,diff);
        cout<<"\n";
    }
}
