//
// Created by Alina on 16/7/14.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        char c[256];
        int tail = 0;
        if (strs.size() == 0)
            return "";
        for(tail = 0;tail<strs[0].length();tail++){
            c[tail] = strs[0][tail];
        }
        for(int i=1;i<strs.size();i++){
            int j = 0;
            while(j<strs[i].length() && j<tail){
                if(strs[i][j] != c[j]){
                    break;
                }
                j++;
            }
            tail = j;
        }
        c[tail] = '\0';
        return c;
    }
};
//int main(){
//    Solution s;
//    vector<string> strs = {"ffgfg","abc","abggg"};
//    string result = s.longestCommonPrefix(strs);
//    cout<<result<<endl;
//    return 0;
//}
