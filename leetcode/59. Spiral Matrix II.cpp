class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>answer(n,vector<int>(n,-1));
        int startno=1;
        bool right=true,down,left,up;
        int y=0,x=0;
        while(startno<=n*n)
        {
            
            if(right)
            {
                
                right=false;down=true;
                while(x<n&&answer[y][x]==-1)
                {
                    answer[y][x++]=startno++;
                }x--;y++;continue;
            }
            if(down)
            {
                down=false;left=true;
                while(y<n&&answer[y][x]==-1)
                {
                    answer[y++][x]=startno++;
                }y--;x--;continue;
            }
            if(left)
            {
                left=false;up=true;
                while(x>=0&&answer[y][x]==-1)
                {
                    answer[y][x--]=startno++;
                }x++;y--;continue;
            }
            if(up)
            {
                up=false;right=true;
                while(y>=0&&answer[y][x]==-1)
                {
                    answer[y--][x]=startno++;
                }y++;x++;continue;
            }
        }
        return answer;
    }
};
