/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

You must write an algorithm that runs in O(m log(n)) or O(n log(m)) time.

Example 1:
Input: mat = [[1,4],[3,2]]
Output: [0,1]
Explanation: Both 3 and 4 are peak elements so [1,0] and [0,1] are both acceptable answers.
*/

/*
Using example 2: prove 30 is peak.
We choose the middle element of whatever row to see which row on that column is
max (1. We have middle > top, bottom); Now we have which row, we binary search
on that row see if middle > left,right; if compare top,bottom again
*/

class Solution
{
public:
    int findGlobalMax(vector<vector<int>> &mat, int col)
    {
        int max = 0;
        int index = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][col] > max)
            {
                max = mat[i][col];
                index = i;
            }
        }
        return index; // which row max reside on, given fixed column
    }

    vector<int> helper(vector<vector<int>> &mat, int left = 0, int right = -1)
    {
        // if (mat.size() <= 0)
        //     return {0,0};
        if (right == -1)
            right = mat[0].size(); // same as number of column

        // The middle's column index
        int j = left + (right - left) / 2;
        // The middle's row index
        int globalMax = findGlobalMax(mat, j);

        if (
            // middle >= top; middle is not in the very top line
            (globalMax - 1 > 0 && mat[globalMax][j] >= mat[globalMax][j - 1]) &&
            // middle >= bottom; middle is not in the very bottom line
            (globalMax + 1 < mat.size() &&
             mat[globalMax][j] >= mat[globalMax + 1][j]) &&
            // middle >= right; middle is not in the very right edge
            (j + 1 < mat[globalMax].size() &&
             mat[globalMax][j] >= mat[globalMax][j + 1]) &&
            // middle >= left; middle is not in the very left edge
            (j - 1 > 0 && mat[globalMax][j] >= mat[globalMax][j - 1]))
        {
            return vector<int>{globalMax, j};
        }
        else if (
            // left > middle
            j > 0 && mat[globalMax][j] <= mat[globalMax][j - 1])
        {
            right = j;
            return helper(mat, left, right);
        }
        else if (
            // right > middle
            j + 1 < mat[globalMax].size() &&
            mat[globalMax][j] <= mat[globalMax][j + 1])
        {
            left = j + 1;
            return helper(mat, left, right);
        }
        return vector<int>{globalMax, j};
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        vector<int> res = helper(mat);
        return res;
    }
};
