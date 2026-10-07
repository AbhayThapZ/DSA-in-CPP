#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;

        for (int i = 0; i < height.size(); i++) {
            for (int j = i + 1; j < height.size(); j++) {

                int width = j - i;
                int h = min(height[i], height[j]);

                int area = width * h;

                maxWater = max(maxWater, area);
            }
        }

        return maxWater;
    }
};

class Solution2 {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lb=0;
        int rb=n-1;
        int maxWater=0;
        while(lb<rb){
            int w=rb-lb;
            int h=min(height[lb],height[rb]);
            maxWater=max(maxWater,w*h);
            height[lb]<height[rb]?lb++:rb--;
        }
        return maxWater;
    }
};

int main(){
    Solution2 sol2;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout <<"The maximum water that can be stored is: "<<sol2.maxArea(height) << endl;
    return 0;
}