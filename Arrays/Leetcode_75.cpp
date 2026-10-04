#include <iostream>
#include <vector>
using namespace std;

class Solution1
{ // Time Complexity: O(n), Space Complexity: O(1)
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

class Solution2
{ // Time Complexity: O(n), Space Complexity: O(1)
public:
    vector<int> sortColors(vector<int> &nums)
    {
        int zeros = 0;
        int ones = 0;
        int twos = 0;

        int n = nums.size();
        for (int i : nums)
        {
            if (i == 0)
            {
                zeros++;
            }
            else if (i == 1)
            {
                ones++;
            }
            else
            {
                twos++;
            }
        }

        int i = 0;
        while (zeros != 0)
        {
            nums[i] = 0;
            i++;
            zeros--;
        }
        while (ones != 0)
        {
            nums[i] = 1;
            i++;
            ones--;
        }
        while (twos != 0)
        {
            nums[i] = 2;
            i++;
            twos--;
        }
    }
};

class Solution3
{ // Time Complexity: O(n), Space Complexity: O(1)
public:
    vector<int> sortColors(vector<int> &nums)
    {
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[index]);
                index++;
            }
        }

        for (int i = index; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                swap(nums[i], nums[index]);
                index++;
            }
        }
    }
};

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    Solution1 sol1;
    sol1.sortColors(nums);
    cout << "Sorted Colors: ";
    for (int ele : nums)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}