class Solution {
public:
    int addDigits(int num) {
        if(num==0)return 0;
        if(num==1)return 1;
        string tmp=to_string(num);
        int answer;
        while(tmp.length()!=1)
        {
            answer=0;
            for(auto i:tmp)
            {
                answer+=(i-'0');
            }
            tmp=to_string(answer);
            //cout<<tmp<<"\n";
        }
        return answer;
    }
};

/*
Digit root method
class Solution {
public:
    int addDigits(int num) {
      if(num==0)
          return 0;
      else if(num%9==0)
          return 9;
      else
          return num%9;
    }
};
*/
