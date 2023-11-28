#include <bits/stdc++.h>
using namespace std;

bool checkisequal(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix1[i][j] != matrix2[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

pair<int, int> FindGap(vector<vector<int>> matrix)
{
    pair<int, int> ans;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == -1)
            {
                ans = {i, j};
            }
        }
    }
    return ans;
}

void printmatrix(vector<vector<int>> matrix)
{

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int heuristic(vector<vector<int>> st, vector<vector<int>> en)
{
    int misplacedtile = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (st[i][j] != en[i][j])
            {
                misplacedtile++;
            }
        }
    }
    return misplacedtile;
}

int main()
{
    vector<vector<int>> St_matrix = {{2, 8, 3}, {1, 6, 4}, {7, -1, 5}};
    vector<vector<int>> En_matrix = {{1, 2, 3}, {8, -1, 4}, {7, 6, 5}};

    vector<vector<vector<int>>> ans;
    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>, greater<>> q;
    int x = heuristic(St_matrix, En_matrix);
    q.push({x, St_matrix});
    int del_row[4] = {0, 1, 0, -1};

    int del_col[4] = {1, 0, -1, 0};

    while (!q.empty())
    {

        vector<vector<int>> temp = q.top().second;

        q.pop();
        if (checkisequal(temp, En_matrix))
        {

            cout << (heuristic(temp, En_matrix)) << endl;
            printmatrix(temp);
            break;
        }
        else
        {
            cout << (heuristic(temp, En_matrix)) << endl;
            printmatrix(temp);
        }

        pair<int, int> coord = FindGap(temp);
        int x = coord.first;
        int y = coord.second;

        for (int i = 0; i < 4; i++)
        {

            int newrow = x + del_row[i];
            int newcol = y + del_col[i];
            if (newrow >= 0 && newrow < 3 && newcol >= 0 && newcol < 3)
            {

                swap(temp[x][y], temp[newrow][newcol]);

                int h = heuristic(temp, En_matrix);

                q.push({h, temp});

                swap(temp[x][y], temp[newrow][newcol]);
            }
        }
    }

    return 0;
}