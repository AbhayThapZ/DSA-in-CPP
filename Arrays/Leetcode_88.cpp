#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1
// T.C.: O(m+n)log(m+n)
// S.C.: O(1)
{
public:
    void merge(vector<int> &num1, int m, vector<int> &num2, int n)
    {
        int j=0;
        for (int i = m; i < n + m; i++)
        {
            num1[i]=num2[j];
            j++;
        }
        sort(num1.begin(),num1.end());
    }
};

class Solution2
// T.C.: O(n)
// S.C.: O(1)
{
public:
    void merge(vector<int> &num1, int m, vector<int> &num2, int n)
    {
        int i=m-1;
        int j=n-1;
        int k=m+n-1;
        while(j>=0){
            if(i>=0 && num1[i]>num2[j]){
                num1[k]=num1[i];
                i--;
            }else{
                num1[k]=num2[j];
                j--;
            }
            k--;
        }
    }
};

int main()
{
    // Solution1 sol1;
    Solution2 sol2;

    vector<int> num1 = {1, 2, 3, 0, 0, 0};
    vector<int> num2 = {2, 5, 6};

    int n = num2.size();
    int m = num1.size() - n;

    // sol1.merge(num1, m, num2, n);
    sol2.merge(num1, m, num2, n);

    cout << "Merged Elements oof Array1 and Array2 are:";
    for (int i = 0; i < m + n; i++)
    {
        cout << num1[i];
    }
    cout << endl;

    return 0;
}