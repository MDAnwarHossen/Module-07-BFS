#include <bits/stdc++.h>
using namespace std;
bool visited[1000];
int level[1000];
void Bfs(vector<int> adjList[], int root)
{
    queue<int> q;
    q.push(root);
    visited[root] = true;
    while (!q.empty())
    {
        int r = q.front();
        // visited[r] = true;
        cout << r << " ";
        q.pop();
        for (int neighbour : adjList[r])
        {
            if (visited[neighbour])
            {
                continue;
            }
            q.push(neighbour);
            visited[neighbour] = true;
            level[neighbour] = level[r] + 1;
        }
    }
}
int main()
{
    int N, E;
    cin >> N >> E;
    vector<int> adjList[N + 1];
    for (int i = 1; i <= E; i++)
    {
        int from, to;
        cin >> from >> to;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
    Bfs(adjList, 1);
    // for (int i = 1; i <= N; i++)
    // {
    //     for (int val : adjList[i])
    //     {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    cout << endl
         << "***********************************" << endl;
    for (int i = 1; i <= N; i++)
    {
        cout << "Level of " << i << " is " << level[i] << endl;
    }

    return 0;
}