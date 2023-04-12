#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
bool visited[1001];
bool bfsvisited[1001];
queue<int> bfs;
vector<int>bfsvec;
vector<int> adj[1001];
vector<int> dfsvec;
bool checkvis(int x)
{
    if (visited[x])return true;
    return false;
}
bool checkvisall(int x)
{
    for (int i = 0; i < adj[x].size(); i++)
    {
        if (checkvis(adj[x][i]) == false)return false;
    }return true;
}
void dfs(int x)
{
    if (adj[x].size() == 0 || checkvisall(x))
    {
        return;
    }
    for (int i = 0; i < adj[x].size(); i++)
    {
        if (checkvis(adj[x][i])==false)
        {
            visited[adj[x][i]] = true;
            dfsvec.push_back(adj[x][i]);
            dfs(adj[x][i]);
        }
    }
}
int main(void)
{
    int n, m, v;
    cin >> n >> m >> v;
    int i;
    for (i = 0; i < m; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    for (i = 1; i <= n; i++)
    {
        if (adj[i].size() > 0) {
            sort(adj[i].begin(), adj[i].end());
        }
    }
    dfsvec.push_back(v);
    visited[v] = true;
    for (int g = 0; g < adj[v].size();g++)
    {//dfs
        if (checkvis(adj[v][g])==false)
        {
            visited[adj[v][g]] = true;
            dfsvec.push_back(adj[v][g]);
            dfs(adj[v][g]);
        }
    }
    for (i = 0; i < dfsvec.size(); i++)
    {
        cout << dfsvec[i] << " ";
    }
    //bfs
    bfsvisited[v] = true;
    bfs.push(v);
    int k = v;
    bfsvec.push_back(k);
    while (!bfs.empty())
    {
        for (i = 0; i < adj[k].size(); i++)
        {
            if (bfsvisited[adj[k][i]] == false)
            {
                bfsvisited[adj[k][i]] = true;
                bfs.push(adj[k][i]);
            }
        }
        bfs.pop();
        if (bfs.empty())break;
        k = bfs.front();
        bfsvec.push_back(k);
    }
    cout << "\n";
    for (i = 0; i < bfsvec.size(); i++)
    {
        cout << bfsvec[i] << " ";
    }
}