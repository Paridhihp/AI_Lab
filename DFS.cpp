#include <bits/stdc++.h>
using namespace std;

pair<int, int> FindGap(vector<vector<int>> matrix)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] == -1)
            {
                return {i, j};
            }
        }
    }
}

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

bool dfs(vector<vector<int>> current, vector<vector<int>> final, vector<vector<vector<int>>> &ans, int depth)
{
    if (depth > 10)
    {
        return false;
    }
    if (checkisequal(current, final))
    {
        for (auto v : ans)
        {
            printmatrix(v);
        }
        cout << "Goal State Reached" << endl;
        return true;
    }

    int del_row[4] = {0, 1, 0, -1};
    int del_col[4] = {1, 0, -1, 0};
    pair<int, int> coord = FindGap(current);
    int x = coord.first;
    int y = coord.second;

    for (int i = 0; i < 4; i++)
    {

        int newrow = x + del_row[i];
        int newcol = y + del_col[i];
        if (newrow >= 0 && newrow < 3 && newcol >= 0 && newcol < 3)
        {

            swap(current[x][y], current[newrow][newcol]);
            ans.push_back(current);

            if (dfs(current, final, ans, depth + 1))

                return true;

            ans.pop_back();
            swap(current[x][y], current[newrow][newcol]);
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> St_matrix = {{2, 8, 3}, {1, 6, 4}, {7, -1, 5}};
    vector<vector<int>> En_matrix = {{1, 2, 3}, {8, -1, 4}, {7, 6, 5}};

    vector<vector<vector<int>>> ans;
    if (!dfs(St_matrix, En_matrix, ans, 0))
    {
        cout << "Cant reach final state" << endl;
    }

    return 0;
}

