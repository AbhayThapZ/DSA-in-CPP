#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution1{//Time Complexity:O(n^2) Space Complexity:O(1)
public:
    int singleNumber(vector<int> nums){
        int n=nums.size();
        
        if(n==1){
            return nums[0];
        }

        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            if(count==1){
                return nums[i];
            }
        }
        return -1;
    }
};

class Solution2{//Time Complexity:O(n log n) Space Complexity:O(1)
public:
    int singleNumber(vector<int> nums){
        int n=nums.size();
        
        if(n==1){
            return nums[0];
        }

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i+=2){
            if(nums[i]!=nums[i+1]){
                return nums[i];
            }
        }
    }
};

class Solution3{
public:
    int singleNumber(vector<int> nums){
        int n=nums.size();
        
        unordered_map<int,int> freq;

        for(int num:nums){
            freq[num]++;
        }

        for(auto it:freq){
            if(it.second==1){
                return it.first;
            }
        }
        return -1;
    }
};

class Solution4{//Time Complexity:O(n) Space Complexity:O(1)
public:
    int singleNumber(vector<int> nums){
        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }

        return ans;
    }
};

int main(){
    vector<int> nums={1,2,1,4,2};
    
    // Solution1 sol1;
    // int ans=sol1.singleNumber(nums);
    
    // Solution2 sol2;
    // int ans=sol2.singleNumber(nums);
    
    // Solution3 sol3;
    // int ans=sol3.singleNumber(nums);
    
    Solution4 sol4;
    int ans=sol4.singleNumber(nums);
    
    cout<<"Single Number:"<<ans;
    return 0;
}