#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchInRow(vector<vector<int>> matrix,int target,int midR){
        int n=matrix[0].size();
        int sR=0;
        int eR=n-1;
        while(sR<=eR){
            int mid=sR+(eR-sR)/2;
            if(target==matrix[midR][mid]) return true;
            else if(target>matrix[midR][mid]) sR=mid+1;
            else eR=mid-1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int sR=0;
        int eR=m-1;
        while(sR<=eR){
            int midR=sR+(eR-sR)/2;
            if(target>=matrix[midR][0] && target<=matrix[midR][n-1]){
                return searchInRow(matrix,target,midR);
            }else if(target>matrix[midR][n-1]){
                sR=midR+1;
            }else{
                eR=midR-1;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    Solution solution;
    bool result = solution.searchMatrix(matrix, target);
    cout <<"The Element is Found: " <<(result ? "True" : "False") << endl;
    return 0;
}