//
// Created by Alina on 2016/10/10.
//

#include <iostream>
using namespace std;

int main(){
//    freopen("/Users/Alina/ClionProjects/ForJob/Google/b","r",stdin);
    int N,M;
    cin >> N;
    string org;
    cin >> org;
    cin >> M;
    int invalid[26][26];
    memset(invalid,0, sizeof(invalid));
    for(int i=0;i<M;i++){
        string temp;
        cin >> temp;
        invalid[temp[0]-'a'][temp[1]-'a'] = 1;
        invalid[temp[1]-'a'][temp[0]-'a'] = 1;
    }
    int dp[26];
    memset(dp,0, sizeof(dp));
    for(int i=0;i<N;i++){
        int temp_max = 0;
        for(int j=0;j<26;j++){
            if(invalid[org[i]-'a'][j] == 1)
                continue;
            else{
                temp_max = max(temp_max,dp[j] + 1);
            }
        }
        dp[org[i]-'a'] = temp_max;
    }
    int max = 0;
    for(int i=0;i<26;i++)
        max = max > dp[i] ? max : dp[i];
    cout << N - max << endl;

}