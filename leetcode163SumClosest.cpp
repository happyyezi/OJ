//
// Created by Alina on 16/7/29.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int c;
        int result = nums[0] + nums[1] + nums[2];
        for(int k=0;k<nums.size();k++){
            c = nums[k];
            int i = k+1;
            int j = nums.size()-1;
            while(i<j){
                if(abs(nums[i] + nums[j] + c - target) < abs(result-target))
                    result = nums[i] + nums[j] + c;
                if(nums[i] + nums[j] + c <target){
                    i++;
                    while(nums[i] == nums[i-1])
                        i++;
                }else if (nums[i] + nums[j] + c > target){
                    j--;
                    while(nums[j] == nums[j+1])
                        j--;
                }else{
                    break;
                }
            }

        }
        return result;
    }
};
//int main(){
//    Solution s;
//    vector<int> sums = {-1,2,1,-4};
//    int result = s.threeSumClosest(sums,1);
//    cout<<result<<endl;
//    return 0;
//}