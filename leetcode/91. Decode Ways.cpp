class Solution {
public:
    /*int answer=0;
    void recursion(string s,int idx){
        if(idx==s.length()){
            answer++;
        }
        for(int i=1;i<=2;i++){
            if(idx+i-1>=s.length())continue;
            if(stoi(s.substr(idx,i))==0||stoi(s.substr(idx,i))>26){continue;}
            if(s[idx]=='0')continue;
            //cout<<s.substr(idx,i)<<"\n";
            recursion(s,idx+i);
        }
    }*/
    //   ^ exceeds time limit

    /*
    memoization
    since we will be going top down and the same index will be touched upon multiple times,
    we put them in a memoization table
    */

    map<int,int>memo;
    int recursion(string&s, int idx){
        if(memo.contains(idx))return memo[idx];
        if(s[idx]=='0')return 0;
        if(idx==s.length())return 1;
        if(idx==s.length()-1)return 1;
        int ans=recursion(s,idx+1);
        if(stoi(s.substr(idx,2))<=26){
            ans+=recursion(s,idx+2);
        }
        memo[idx]=ans;
        return ans;
    }
    int numDecodings(string s) {
        //recursion(s,0);
        //return answer;
        return recursion(s,0);
    }
};
