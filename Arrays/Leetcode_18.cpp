#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution1
{//Time Complexity:O(n^4) ,Space Complexity:O(1)
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        long long sum = (long long)nums[i]
                                      + nums[j]
                                      + nums[k]
                                      + nums[l];

                        if (sum == target)
                        {
                            ans.push_back({
                                nums[i],
                                nums[j],
                                nums[k],
                                nums[l]
                            });
                        }
                    }
                }
            }
        }

        return ans;
    }
};

class Solution2
{//Time Complexity:O(n^3) ,Space Complexity:O(n)
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                unordered_set<int> seen;

                for (int k = j + 1; k < n; k++)
                {
                    long long required =
                        (long long)target
                        - nums[i]
                        - nums[j]
                        - nums[k];

                    if (seen.count(required))
                    {
                        ans.push_back({
                            nums[i],
                            nums[j],
                            (int)required,
                            nums[k]
                        });
                    }

                    seen.insert(nums[k]);
                }
            }
        }

        return ans;
    }
};

class Solution3
{//Time Complexity:O(n^3) ,Space Complexity:O(1)
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++)
        {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n; j++)
            {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int p = j + 1;
                int q = n - 1;

                while (p < q)
                {

                    long long sum = (long long)nums[i] + nums[j] + nums[p] + nums[q];

                    if (sum < target)
                    {
                        p++;
                    }
                    else if (sum > target)
                    {
                        q--;
                    }
                    else
                    {
                        ans.push_back({nums[i],
                                       nums[j],
                                       nums[p],
                                       nums[q]});

                        p++;
                        q--;

                        while (p < q && nums[p] == nums[p - 1])
                            p++;

                        while (p < q && nums[q] == nums[q + 1])
                            q--;
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution3 sol3;
    vector<vector<int>> result = sol3.fourSum(nums, target);

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