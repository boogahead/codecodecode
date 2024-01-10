class MyCalendarTwo {
public:
    map<int,int>yes;
    int count=0;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        yes[start]++;
        yes[end]--;
        int cnt=0;
        for(auto i:yes){
            if(i.first>end)break;
            cnt+=i.second;
            if(cnt==3&&i.first>=start&&i.first<=end){
                yes[start]--;
                yes[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
