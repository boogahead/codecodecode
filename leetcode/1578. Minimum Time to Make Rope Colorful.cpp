class Solution {
public:
    typedef pair<char,int>info; //color index
    int minCost(string colors, vector<int>& neededTime) {
        stack<info>qq;
        int answer=0;
        for(int i=0;i<colors.size();i++){
            if(qq.empty()){
                qq.push({colors[i],i});continue;
            }
            if(qq.top().first==colors[i]){
                if(neededTime[qq.top().second]>neededTime[i]){
                    //cout<<i<<"\n";
                    answer+=neededTime[i];
                    continue;
                }
                else{
                    answer+=neededTime[qq.top().second];
                    //cout<<"popped from back "<<i<<"\n";
                    qq.pop();qq.push({colors[i],i});continue;
                }
            }
            qq.push({colors[i],i});
        }
        while(!qq.empty()){
            //cout<<qq.top().first<<" "<<qq.top().second<<"\n";
            qq.pop();
        }
        return answer;
    }
};
