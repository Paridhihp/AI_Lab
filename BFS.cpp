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
}

int main()
{
    vector<vector<int>> St_matrix = {{2, 8, 3}, {1, 6, 4}, {7, -1, 5}};
    vector<vector<int>> En_matrix = {{1, 2, 3}, {8, -1, 4}, {7, 6, 5}};

    vector<vector<vector<int>>> ans;
    queue<pair<vector<vector<int>>, vector<vector<vector<int>>>>> q;
    q.push({St_matrix, ans});
    int del_row[4] = {0, 1, 0, -1};

    int del_col[4] = {1, 0, -1, 0};

    while (!q.empty())

    {
        bool flag = false;
        int size = q.size();
        while (size--)
        {

            vector<vector<int>> temp = q.front().first;
            vector<vector<vector<int>>> vec = q.front().second;
            q.pop();
            if (checkisequal(temp, En_matrix))
            {
                cout << "Path" << endl;
                for (auto i : vec)
                {
                    printmatrix(i);
                    cout << endl;
                }

                flag = true;
                break;
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
                    vec.push_back(temp);
                    q.push({temp, vec});
                    vec.pop_back();
                    swap(temp[x][y], temp[newrow][newcol]);
                }
            }
        }
        if (flag)
        {
            break;
        }
    }

    return 0;
}