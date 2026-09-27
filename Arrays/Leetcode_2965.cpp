#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class solution1{
    //T.C.:O(n^2 log n)
    //S.C.:O(n^2)
public:
    vector<int> missing_duplicate(vector<vector<int>>& grid){
        int duplicate=0,missing=0;
        int n=grid.size();

        vector<int> single;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                single.push_back(grid[i][j]);
            }
        }

        sort(single.begin(),single.end());

        for(int i=0;i<n*n-1;i++){
            if(single[i]==single[i+1]){
                duplicate=single[i];
                break;
            }
        }
        for(int i=0;i<n*n;i++){
            if(single[i]!=i+1){
                missing=i+1;
                break;
            }
        }
        return {duplicate,missing};
    }
};

class solution2{
    //T.C.:O(n^2)
    //S.C.:O(n^2)
public:
    vector<int> missing_duplicate(vector<vector<int>>& grid){
        int n=grid.size();
        int duplicate=0,missing=0;
        unordered_map<int,int> freq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }

        for(int i=1;i<=n*n;i++){
            if(freq[i]==2){
                duplicate=i;
            }
            if(freq[i]==0){
                missing=i;
            }
        }

        return {duplicate,missing};
    }
};

class solution3{
    //T.C.:O(n^2)
    //S.C.:O(n^2)
public:
    vector<int> missing_duplicate(vector<vector<int>>& grid){
        int n=grid.size();
        vector<int> freq(n*n+1,0);
        int duplicate=0,missing=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                freq[grid[i][j]]++;
            }
        }

        for(int i=1;i<=n*n;i++){
            if(freq[i]==2){
                duplicate=i;
            }
            if(freq[i]==0){
                missing=i;
            }
        }
        return {duplicate,missing};
    }
};

class solution4{
    //T.C.:O(n^2)
    //S.C.:O(1)
public:
    vector<int> missing_duplicate(vector<vector<int>>& grid){
        int n=grid.size();
        int N=n*n;
        int expectedSum=N*(N+1)/2;
        int expectedSquareSum=N*(N+1)*(2*N+1)/6;

        int actualSum=0,actualSquareSum=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int curr=grid[i][j];

                actualSum+=curr;
                actualSquareSum+=curr*curr;
            }
        }

        int diff=actualSum-expectedSum;

        int squareDiff=actualSquareSum-expectedSquareSum;

        int sum=squareDiff/diff;

        int duplicate=(diff+sum)/2;
        int missing=(sum-diff)/2;

        return {duplicate,missing};
    }
};

class solution5{
    //T.C.:O(n^2)
    //S.C.:O(1)
public:
    vector<int> missing_duplicate(vector<vector<int>>& grid){
        int n=grid.size();
        int N=n*n;
        
        int x=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                x^=grid[i][j];
            }
        }

        for(int i=1;i<=N;i++){
            x^=i;
        }

        int bit=x & -x;//different bit

        //two group separation
        int a=0;
        int b=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] & bit){
                    a^=grid[i][j];
                }else{
                    b^=grid[i][j];
                }
            }
        }

        for(int i=1;i<=N;i++){
            if(i&bit){
                a^=i;
            }else{
                b^=i;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==a){
                    return{a,b};
                }else if(grid[i][j]==b){
                    return{b,a};
                }
            }
        }
        return {};
    }
};

int main(){
    vector<vector<int>> grid={{9,1,7},{8,9,2},{3,4,6}};

    solution1 sol1;
    vector<int> ans1=sol1.missing_duplicate(grid);
    
    cout<<"Duplicate Value in the Grid:"<<ans1[0]<<endl;
    cout<<"Missing Value in the Grid:"<<ans1[1]<<endl;
    
    solution2 sol2;
    vector<int> ans2=sol2.missing_duplicate(grid);
    
    cout<<"Duplicate Value in the Grid:"<<ans2[0]<<endl;
    cout<<"Missing Value in the Grid:"<<ans2[1]<<endl;
    
    solution3 sol3;
    vector<int> ans3=sol3.missing_duplicate(grid);
    
    cout<<"Duplicate Value in the Grid:"<<ans3[0]<<endl;
    cout<<"Missing Value in the Grid:"<<ans3[1]<<endl;

    solution4 sol4;
    vector<int> ans4=sol4.missing_duplicate(grid);
    
    cout<<"Duplicate Value in the Grid:"<<ans4[0]<<endl;
    cout<<"Missing Value in the Grid:"<<ans4[1]<<endl;
    
    solution5 sol5;
    vector<int> ans5=sol5.missing_duplicate(grid);
    
    cout<<"Duplicate Value in the Grid:"<<ans5[0]<<endl;
    cout<<"Missing Value in the Grid:"<<ans5[1]<<endl;
    return 0;
}