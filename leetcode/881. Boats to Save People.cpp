class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;int j=people.size()-1;
        int answer=0;
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)i++;
            j--;
            answer++;
        }
        return answer;
    }
};
