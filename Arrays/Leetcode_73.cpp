#include <iostream>
#include <vector>
using namespace std;

class Solution1
{//Time Complexity:O(m*n) ,Space Complexity:O(m+n)
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> r(m, 0);
        vector<int> c(n, 0);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (r[i] == 1 || c[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution2
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> temp = matrix;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {

                    for (int k = 0; k < n; k++)
                    {
                        temp[i][k] = 0;
                    }

                    for (int k = 0; k < m; k++)
                    {
                        temp[k][j] = 0;
                    }
                }
            }
        }

        matrix = temp;
    }
};


class Solution3
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 1;

        for (int i = 0; i < m; i++)
        {
            if (matrix[i][0] == 0)
            {
                col0 = 0;
            }

            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {

            for (int j = n - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }

            if (col0 == 0)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    vector<vector<int>> original = {
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 1}};

    Solution3 s3;
    vector<vector<int>> matrix = original;

    cout << "APPROACH 3: O(1) AUXILIARY SPACE" << endl;
    s3.setZeroes(matrix);
    for (const auto &row : matrix)
    {
        for (int value : row)
        {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}