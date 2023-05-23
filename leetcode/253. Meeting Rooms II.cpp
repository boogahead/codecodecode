class Solution {
public:
    typedef pair<int,int>info;//start,end
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int count=0;
        priority_queue<info,vector<info>,greater<info>>qq;
        for(auto i:intervals)qq.push({i[0],i[1]});
        int start,end;
        vector<info>rooms;
        while(!qq.empty())
        {
            tie(start,end)=qq.top();qq.pop();
            if(rooms.size()==0)
            {
                rooms.push_back({start,end});continue;
            }
            bool roomfound=false;
            for(int i=0;i<rooms.size();i++)
            {
                if(start>=rooms[i].second)
                {
                    roomfound=true;
                    rooms[i].first=start;rooms[i].second=end;break;
                }
            }
            
            if(!roomfound)
            {
                rooms.push_back({start,end});continue;
            }
        }
        return rooms.size();
    }
};
