class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target=='z')return letters[0];
        sort(letters.begin(),letters.end());
        int i=0;bool exist;
        while(i<letters.size())
        {
            //cout<<letters[i]<<"\n";
            if(target<letters[i])
            {
                exist=true;
                break;
            }
            i++;
        }
        if(i==letters.size())return letters[0];
        //cout<<i<<"\n";
        if(exist)return letters[i];
        return letters[0];
    }
};
