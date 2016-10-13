//
// Created by Alina on 16/7/12.
//
#include <iostream>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        //以dp[i][j]表示s[0..i-1]和p[0..j-1]是否匹配,匹配为1,不匹配为0
        //遍历i,j
        //p[j-1] != '*':dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
        //p[j-1] == '*':
        //////*次数为0:dp[i][j] = dp[i][j-2]
        //////*次数大于0:dp[i][j] = dp[i-1][j] && (s[i-1] == p[j-1] || p[j-1] == '.')
        //初始化dp[0][j]和dp[i][0]
        int m = s.length();
        int n = p.length();
//        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        bool **dp = new bool * [m+1];
        for(int i=0;i<=m;i++){
            dp[i] = new bool [n+1];
        }
        dp[0][0] = true;
        for (int i=1;i<=m;i++){
            dp[i][0] = false;
        }
        dp[0][1] = false;
        for(int j=2;j<=n;j++){
            dp[0][j] = (p[j-1] == '*') && dp[0][j-2];
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(p[j-1] != '*'){
                    dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }else{
                    dp[i][j] = dp[i][j-2] || (dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
            }
        }
        return dp[m][n];
    }
};
//int main(){
//    Solution s;
//    bool result = s.isMatch("abced","a.*d");
//    cout<<result<<endl;
//    return 0;
//}

