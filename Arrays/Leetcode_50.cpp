#include <iostream>
using namespace std;

class Solution1//Time Complexity: O(n) and Space Complexity: O(1)
{
public:
    double myPow(int x, int n)
    {
        double ans = 1;

        for (int i = 1; i <= n; i++)
        {
            ans *= x;
        }
        return ans;
    }
};

class Solution2//Time Complexity: O(n) and Space Complexity: O(n)
{
public:
    double myPow(int x, int n)
    {
        if (n == 0)
        {
            return 1;
        }
        return x * myPow(x, n - 1);
    }
};

class Solution3//Time Complexity: O(log n) and Space Complexity: O(log n)
{
public:
    double myPow(int x, int n)
    {
        if (n == 0)
        {
            return 1;
        }

        if (n < 0)
        {
            return 1 / myPow(x, -n);
        }

        double half = myPow(x, n / 2);

        if (n % 2 == 0)
        {
            return half * half;
        }
        return half * half * x;
    }
};

class Solution4//Time Complexity: O(log n) and Space Complexity: O(log n)
{
public:
    double myPow(int x, int n)
    {
        long long N = n;

        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;

        while (N > 0)
        {
            if (N % 2 == 1)
            {
                ans *= x;
            }
            x *= x;
            N /= 2;
        }
        return ans;
    }
};

int main()
{
    int x;
    int n;
    cout << "Enter Your Number: ";
    cin >> x;
    cout << "Enter Power: ";
    cin >> n;

    // Solution1 sol1;
    // double ans=sol1.myPow(x,n);

    // Solution2 sol2;
    // double ans = sol2.myPow(x, n);
    
    // Solution3 sol3;
    // double ans = sol3.myPow(x, n);
    
    Solution4 sol4;
    double ans = sol4.myPow(x, n);

    cout << "Answer is: " << ans << endl;
    return 0;
}