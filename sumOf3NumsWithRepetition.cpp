//3Sum-  find triplets so that their sum is zero
//https://leetcode.com/problems/3sum/description/

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums){
   
    vector<vector<int>> answer;
    int size=nums.size(); //sizeof(answer)/sizeof(int); <- this is giving heap overflow runtime error on leetcode
    
    sort(nums.begin(),nums.end());
    

    //find 2 elements whose sum is -1*nums[i]
    for(int i=0;i<size-2;i++)
        for(int j=i+1;j<size-1;j++){
            
            //find answer =-1*(num[i]+nums[j])
            for(int k=j+1;k<size;k++)
                if((nums[i]+nums[j]+nums[k])==0){
                    
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[k]);
                    answer.push_back(temp);
                }
        }
    
    return answer;
    
}
int main() {
    // Write C++ code here
    vector<int> numberInputs = {-1,0,1,2,-1,-4};//-1,0,1,2,-1,-4
    vector <vector<int>> result;
    
    
    
 /*   for(const auto& element:numberInputs){
        cout<<element<<" ";
    }
*/
    result=threeSum(numberInputs);
    cout<<endl;
    for(const auto& row:result){
        for(const auto& element:row){
            cout<<element<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
