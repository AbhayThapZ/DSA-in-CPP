#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution1
{
public:
    int maxSubArray(vector<int> &nums)
    {

        int maxSum = INT_MIN;

        for (int i = 0; i < nums.size(); i++)
        {

            int sum = 0;

            for (int j = i; j < nums.size(); j++)
            {

                sum += nums[j];

                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};

class Solution2
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = 0;
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if (currSum < 0)
            {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

class Solution3
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = Solution1().maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << ans << endl;
    return 0;
}