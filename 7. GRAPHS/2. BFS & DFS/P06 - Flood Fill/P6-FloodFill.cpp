// Flood Fill.  --> TC:O(N*M)   SC:O(N*M).

#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &ans, int inicolor, int newcolor, int delrow[], int delcol[])
{
    int n = ans.size();
    int m = ans[0].size();
    ans[row][col] = newcolor;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            ans[nrow][ncol] == inicolor)
        {
            dfs(nrow, ncol, ans, inicolor, newcolor, delrow, delcol);
        }
    }
    return;
}

vector<vector<int>> floodfill(vector<vector<int>> image, int sr, int sc, int newcolor)
{
    int inicolor = image[sr][sc];
    if (inicolor == newcolor)
        return image;
    vector<vector<int>> ans = image;
    
    // neighbours --> 4 directions;
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};

    dfs(sr, sc, ans, inicolor, newcolor, delrow, delcol);

    return ans;
}

int main()
{
    vector<vector<int>> image = {{1, 1, 1},
                                 {2, 2, 0},
                                 {2, 2, 2}};
    int sr = 2, sc = 0, newcolor = 3;

    vector<vector<int>> ans = floodfill(image, sr, sc, newcolor);
    for (auto it : ans)
    {
        for (auto i : it)
            cout << i << " ";
        cout << endl;
    }
}