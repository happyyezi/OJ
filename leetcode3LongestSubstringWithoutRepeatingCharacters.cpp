//
// Created by Alina on 16/7/9.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sub_start = 0;
        int sub_max = 0;
        int locs[256];
        for (int i=0;i<256;i++){
            locs[i] = -1;
        }
        for(int i=0;i<s.length();i++){
            if(locs[(int)s[i]%256] < sub_start){
                locs[(int)s[i]%256] = i;
                if(i+1 - sub_start > sub_max)
                    sub_max = i+1-sub_start;

            }else{
                sub_start = locs[(int)s[i]%256] + 1;
                locs[(int)s[i]%256] = i;
            }
        }
        return sub_max;
    }
};

//int main(){
//    string str = "pwwkew";
//    Solution s;
//    int result = s.lengthOfLongestSubstring(str);
//    cout<<result<<endl;
//    return 0;
//}