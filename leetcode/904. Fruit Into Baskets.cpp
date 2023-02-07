/*
sliding window
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>table;
        int left=0,answer=0;
        for(int i=0;i<fruits.size();i++)
        {
            table[fruits[i]]++;
            while(table.size()>2)
            {
                table[fruits[left]]--;
                if(table[fruits[left]]==0)table.erase(fruits[left]);
                left++;
            }
            answer=max(answer,i-left+1);
        }
        return answer;
    }
};
