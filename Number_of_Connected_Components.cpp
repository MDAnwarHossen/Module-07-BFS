#include <bits/stdc++.h>
using namespace std;
bool visited[1000];
void dfs(vector<int> adjList[], int root)
{
    visited[root] = true;
    for (int neighbour : adjList[root])
    {
        if (visited[neighbour])
        {
            continue;
        }
        dfs(adjList, neighbour);
    }
}
int main()
{
    int N, E;
    cin >> N >> E;
    vector<int> adjList[N + 1];
    for (int i = 1; i <= N; i++)
    {
        int from, to;
        cin >> from >> to;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }

    int cc = 0;
    for (int i = 1; i <= N; i++)
    {
        if (visited[i])
        {
            continue;
        }
        dfs(adjList, i);
        cc++;
    }
    cout << cc << " ";

    return 0;
}