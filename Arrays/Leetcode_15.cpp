#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution1
{ // Time Complexity:O(n^2) ,Space Complexity:O(1)
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                {
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};

class Solution2
{ // Time Complexity:O(n^3) ,Space Complexity:O(1)
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {

                    if (nums[i] + nums[j] + nums[k] == 0)
                    {
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return ans;
    }
};

class Solution3
{ // Time Complexity:O(n^2) ,Space Complexity:O(n)
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        int n = nums.size();
        unordered_set<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {

            unordered_set<int> seen;

            for (int j = i + 1; j < n; j++)
            {

                int required = -(nums[i] + nums[j]);

                if (seen.count(required))
                {

                    vector<int> triplet = {
                        nums[i],
                        nums[j],
                        required};

                    sort(triplet.begin(), triplet.end());

                    ans.insert(triplet);
                }

                seen.insert(nums[j]);
            }
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution1 sol1;
    vector<vector<int>> result = sol1.threeSum(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}