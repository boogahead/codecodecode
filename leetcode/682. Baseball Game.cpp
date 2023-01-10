class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> yes;
        int size=operations.size();
        int idx=-1;
        for(int i=0;i<size;i++)
        {
            if(operations[i]=="+")
            {
                yes.push_back(yes[idx]+yes[idx-1]);
                idx++;
                continue;
            }
            if(operations[i]=="D")
            {
                yes.push_back(yes[idx]*2);
                idx++;
                continue;
            }
            if(operations[i]=="C")
            {
                yes.pop_back();
                idx--;
                continue;
            }
            int tmp=stoi(operations[i]);
            idx++;
            yes.push_back(tmp);
        }
        return(accumulate(yes.begin(),yes.end(),0));
    }
};
