/*

You are given an n x n integer matrix grid.

Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:

maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.

Return the generated matrix.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> largestLocal(vector<vector<int>>& grid)
{
    int n = grid.size(), m = grid[0].size(), max = 0;
    vector<vector<int>>result;
    for (int x = 0; x <= n - 3; x++)
    {
        result.push_back(vector<int>());
        for (int y = 0; y <= m - 3; y++) {
            int max_val = 0;
            for (int i = x; i < x + 3; i++) {
                for (int j = y; j < y + 3; j++) {
                    max_val = max_val > grid[i][j] ? max_val : grid[i][j];
                }
            }
            result[x].push_back(max_val);
        }
    }

    return result;
}
int main()
{
    vector<vector<int>> matrix =
    {
        {9,9,8,1},
        {5,6,2,6},
        {8,2,6,4},
        {6,2,2,2}
    };
    vector<vector<int>> res = largestLocal(matrix);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j]<<" ";
        }
        cout << "\n";
    }
    return 0;
}