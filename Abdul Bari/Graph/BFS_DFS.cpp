#include <iostream>
#include <queue>
using namespace std;

void dfs(int arr[][7], int u)
{
    static int visited[7] = {0};

    if (visited[u] == 0)
    {
        cout << u << endl;
        visited[u] = 1;

        for (int v = 1; v <= 6; v++)
        {
            if (arr[u][v] == 1 && visited[v] == 0)
            {
                dfs(arr, v);
            }
        }
    }
}

void BFS(int arr[][7], int start, int n)
{
    int i = start, j;
    queue<int> q;
    int visited[7] = {0};

    cout << i << "\t";
    visited[i] = 1;
    q.push(i);

    while (q.empty() == false)
    {
        i = q.back();
        q.pop();

        for (j = 1; j < n; j++)
        {
            if (arr[i][j] == 1 && visited[j] == 0)
            {
                cout << j << "\t";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (visited[i] == 0)
            cout << i << endl;
    }
}

int main()
{
    //.        As vertices  = 7 and we ignore all zero element

    int arr[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    // BFS(arr, 3, 7);
    dfs(arr, 6);

    return 0;
}