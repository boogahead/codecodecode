class Solution {
public:
    vector<string>answer;
    void recur(vector<int>&input,vector<string>&table,int curidx,string number){
        if(curidx>=input.size()){
            answer.push_back(number);return;
        }
        int curnum=input[curidx];
        for(int i=0;i<table[curnum-2].size();i++){
            number+=table[curnum-2][i];
            recur(input,table,curidx+1,number);
            number.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)return answer;
        vector<string>table;
        table.push_back("abc");
        table.push_back("def");
        table.push_back("ghi");
        table.push_back("jkl");
        table.push_back("mno");
        table.push_back("pqrs");
        table.push_back("tuv");
        table.push_back("wxyz");
        vector<int>input;
        for(auto i:digits){
            input.push_back(i-'0');
        }
        recur(input,table,0,"");
        return answer;
    }
};
