class Solution {
public:
    bool isValid(string s) {
        stack<char>qq;
        if(s.length()%2)return false;
        for(auto i:s)
        {
            if(i=='('||i=='['||i=='{')
            {
                qq.push(i);
            }
            else if(i==')'||i==']'||i=='}')
            {
                if(qq.empty())return false;
                char tmp=qq.top();
                if((tmp=='('&&i==')')||(tmp=='['&&i==']')||(tmp=='{'&&i=='}'))
                {
                    qq.pop();continue;
                }
                else{
                    return false;
                }
            }
        }
        if(qq.empty())
        {
            return true;
        }
        return false;
    }
};
