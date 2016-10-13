//
// Created by Alina on 16/7/14.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int k = 0;
        int c;
        for (int k = 0;k<nums.size();k++){
            if(k>0 && nums[k] == nums[k-1]){
                continue;
            }
            c = nums[k];
            int i = k+1;
            int j = nums.size()-1;
            while(i<j){
                if(nums[i]+nums[j] == -c){
                    vector<int> r = {c,nums[i],nums[j]};
                    result.push_back(r);
                    i++;
                    while(nums[i] == nums[i-1])
                        i++;
                    j--;
                    while(j<nums.size()-1 && nums[j] == nums[j+1])
                        j--;
                }else if(nums[i] + nums[j] < -c){
                    i++;
                    while(nums[i] == nums[i-1])
                        i++;

                }else if(nums[i] + nums[j] > -c){
                    j--;
                    while(j<nums.size()-1 && nums[j] == nums[j+1])
                        j--;
                }
            }
        }
        return result;
    }
};
//int main(){
//    Solution s;
//    vector<int> nums = {-1,0,1,2,-1,-4};
//    vector<vector<int>> result = s.threeSum(nums);
//    for(int i=0;i<result.size();i++){
//        for(int j=0;j<result[i].size();j++)
//            cout<<result[i][j]<<",";
//        cout<<endl;
//    }
//    return 0;
//}

