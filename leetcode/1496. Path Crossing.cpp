class Solution {
public:
    typedef pair<int,int>coord;
    bool isPathCrossing(string path) {
        set<coord>previous;
        int y=0,x=0;
        previous.insert({y,x});
        for(auto i:path){
            if(i=='N')y++;
            if(i=='S')y--;
            if(i=='W')x--;
            if(i=='E')x++;
            if(previous.find({y,x})!=previous.end())return true;
            previous.insert({y,x});
        }
        return false;
    }
};
