#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution1
{ // Time Complexity:O(n) Space Complexity:O(n)
public:
    int majorityElements(vector<int> &nums)
    {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[nums[i]]++;
        }

        for (auto fq : freq)
        {
            if (fq.second > n / 2)
            {
                return fq.first;
            }
        }
    }
};

class Solution2 // Time Complexity:O(n log n) Space Complexity:O(1)
{
public:
    int majorityElements(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n / 2];
    }
};

class Solution3//Time Complexity:O(n^2) Space Complexity:O(1)
{
public:
    int majorityElements(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    count++;
                }
            }
            if (count > n / 2)
            {
                return nums[i];
            }else{
                count=0;
            }
        }
    }
};

class Solution4{
public://Time Complexity:O(n) Space Complexity:O(1)
    int majorityElements(vector<int> &nums){
        int count=0;
        int candidate=0;

        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count==0){
                candidate=nums[i];
            }

            if(nums[i]==candidate){
                count++;
            }else{
                count--;
            }
        }

        return candidate;
    }
};

int main()
{
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    // Solution1 sol1;
    // Solution2 sol2;
    // Solution3 sol3;
    Solution4 sol4;

    // int ans = sol1.majorityElements(nums);
    int ans = sol4.majorityElements(nums);

    cout << "Majority Element is " << ans;

    return 0;
}