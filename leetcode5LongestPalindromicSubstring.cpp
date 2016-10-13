//
// Created by Alina on 16/7/10.
//
#include <iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        //动归求以i开头,以j结尾的字串是否为回文字串,1为是,0为否
        //p[i,j] = p[i+1,j-1] && s[i]==s[j]
        //初始求j-i=0和j-i=1的值
        int maxl = 0;
        int start = 0;
        int len = s.length();
        int a[1000][1000];
        for(int i=0;i<len;i++){
            a[i][i] = true;
            if (maxl < 1) {
                maxl = 1;
                start = i;
            }
            if (i+1<len) {
                a[i][i + 1] = (s[i] == s[i + 1]);
                if (a[i][i+1]){
                    maxl = 2;
                    start = i;
                }
            }

        }
        //遍历长度大于2的字串判断是否为回文
        for (int l=3;l<=len;l++){
            for(int i=0;i+l-1<len;i++){
                a[i][i+l-1] = (a[i+1][i+l-2] && (s[i] == s[i+l-1]));
                if (a[i][i+l-1] && l>maxl) {
                    maxl = l;
                    start = i;
                }

            }
        }
        return s.substr(start,maxl);
    }
};

//int main(){
//    Solution s;
//    string result = s.longestPalindrome("abcbe");
//    cout<<result<<endl;
//    return 0;
//}