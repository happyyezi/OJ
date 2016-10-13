//
// Created by Alina on 16/7/9.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int remain = (m + n)/2 + 1;
        int *arr = new int[remain];
        int i = 0;
        int j = 0;
        int k = 0;
        while(i + j < remain ){
            if(i<m && j<n) {
                if (nums1[i] > nums2[j]) {
                    arr[k] = nums2[j];
                    j++;
                } else {
                    arr[k] = nums1[i];
                    i++;
                }
            }else{
                if (i>=m){
                    arr[k] = nums2[j];
                    j++;
                }else{
                    arr[k] = nums1[i];
                    i++;
                }
            }
            k++;
        }
        if((m+n)%2 == 0){
            return (double)(arr[remain-1]+arr[remain-2])/2;
        }else{
            return (double)arr[remain-1];
        }
    }
};

//int main(){
//    vector<int> nums1;
//    nums1.push_back(1);
//    nums1.push_back(2);
//    vector<int> nums2;
//    nums2.push_back(3);
//    nums2.push_back(4);
//    Solution s;
//    double result = s.findMedianSortedArrays(nums1,nums2);
//    cout<<result<<endl;
//    return 0;
//}
