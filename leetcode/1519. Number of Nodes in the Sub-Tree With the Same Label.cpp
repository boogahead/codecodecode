class Solution {
public:
    vector<int>array;
    /*
    이것도 맨 밑에서부터 끌어올리는문제
    맨밑에서 count 시작해서 알파벳 갯수만큼 생성한 vector에 더해준다.

    */
    vector<int> dfs(int prev,int cur,vector<vector<int>>&table,string& labels)
    {
        vector<int>answer(26);//자식들 카운팅해다가 올릴거 리스트 받기
        for(auto x:table[cur])//현재 node의 adjacency list 확인하면서 자식들 있으면 걔네 숫자 카운팅 한 다음에 리스트를 위로 보내주는것
        {
            vector<int>tmp(26);
            if(x!=prev)
            {
                vector<int>res=dfs(cur,x,table,labels);
                for(int i=0;i<26;i++)
                {
                    answer[i]+=res[i];
                }
            }
        }
        array[cur]= ++answer[labels[cur]-'a'];//만약 자식 없으면 바로 여기로 넘어옴. 일단 나타난거 자체만으로 알파벳 빈도가 늘어나니 최종답안에 ++해줌. 자식 있으면 지금 임시로 만든 answer vector에서 구한 값의 알파벳값에다가 1 더해다가 주기
        return answer; 
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> table(n);
        array.resize(n);
        for(int i=0;i<edges.size();i++)
        {
            table[edges[i][0]].push_back(edges[i][1]);
            table[edges[i][1]].push_back(edges[i][0]);
        }//adjacency list 생성
        
        dfs(-1,0,table,labels);
        return array;
    }
};
