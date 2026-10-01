#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
            if(bestBuy<prices[i]){
                maxProfit=max(maxProfit,prices[i]-bestBuy);
            }
            bestBuy=min(bestBuy,prices[i]);
        }
        return maxProfit;
    }
};

int main(){
    vector<int>prices = {7,1,5,3,6,4};
    Solution sol;

    int ans=sol.maxProfit(prices);
    cout<<ans<<endl;
    
    return 0;
}