//
// Created by Alina on 16/7/13.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        //装水容器的容积受最短边的限制,即容积为min(ai,aj)*(j-i)
        //容积最大时aj的右边没有比aj更合适的线存在,ai的左边没有比ai更合适的线存在
        //从两边像中间遍历
        int result = 0;
        int len = height.size();
        int l = 0;
        int r = len-1;
        int area = 0;
        while(l<r){
            if(height[l]<height[r]){
                area = height[l]*(r-l);
                l++;
            }else{
                area = height[r]*(r-l);
                r--;
            }
            if(area > result)
                result = area;
        }
        return result;
    }
};
//int main(){
//    vector<int> height;
//    height.push_back(3);
//    height.push_back(1);
//    height.push_back(2);
//    cout<<height.size()<<endl;
//    Solution s;
//    int result = s.maxArea(height);
//    cout<<result<<endl;
//    return 0;
//}
