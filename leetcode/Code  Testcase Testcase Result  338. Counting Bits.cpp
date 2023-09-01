class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>answer;
        for(int i=0;i<=n;i++){
            int tmp=i;
            int count=0;
            while(tmp>0){
                if(tmp%2==1)count++;
                tmp/=2;
            }
            answer.push_back(count);
        }
        return answer;
    }
};
