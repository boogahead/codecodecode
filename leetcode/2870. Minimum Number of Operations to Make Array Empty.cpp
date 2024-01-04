class Solution {
public:
    typedef pair<int,int>info;
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mm;
        int answer=0;
        for(auto i:nums)mm[i]++;
        for(auto i:mm){
            if(i.second<2)return -1;
            queue<info>qq;
            qq.push({i.second,0});
            int minimum=INT_MAX;
            while(!qq.empty()){
                info tmp=qq.front();qq.pop();
                if(tmp.first==0){
                    minimum=min(minimum,tmp.second);
                }
                if(tmp.first<2)continue;
                int two=tmp.first,three=tmp.first;
                if(two>=2){
                    int steps=tmp.first/2;
                    qq.push({tmp.first-2*steps,tmp.second+steps});
                }
                if(three>=3){
                    int steps=tmp.first/3;
                    qq.push({tmp.first-3*steps,tmp.second+steps});
                    if(tmp.first%3==1){
                        if(steps>1&&(tmp.first-3*(steps-1))%2==0)qq.push({tmp.first-3*(steps-1),tmp.second+steps-1});
                        if(steps>=2&&(tmp.first-3*(steps-2))%2==0)qq.push({tmp.first-3*(steps-2),tmp.second+steps-2});
                    }
                }
            }
            answer+=minimum;
        }
        return answer;
    }
};
/*
initially thought that reaching the smallest number by subtracting multiples of 2 or 3 will give answer
but there are other possibilities e.g. count = 10 : 3*2 2*2 <- 4 steps giving out last number of steps
had to check if the remainder by 3 leaves 1 which also means that its also divisible by 2
so i took at most two steps ( +3 , +6 ) to see if such values are divisible by 2 and added to queue
*/
