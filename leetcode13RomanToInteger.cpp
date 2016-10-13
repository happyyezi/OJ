//
// Created by Alina on 16/7/14.
//
#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int i = 0;
        while(i<s.length()-1){
            int l = toNumber(s[i]);
            int r = toNumber(s[i+1]);
            if(l<r){
                result += r - l;
                i+=2;
            }else{
                result += l;
                i++;
            }
        }
        if(i<s.length())
            result += toNumber(s[s.length()-1]);
        return result;
    }

private:
    int toNumber(char c){
        switch (c){
            case 'I':return 1;
            case 'V':return 5;
            case 'X':return 10;
            case 'L':return 50;
            case 'C':return 100;
            case 'D':return 500;
            case 'M':return 1000;
        }
        return 0;
    }
};
//int main(){
//    Solution s;
//    int result = s.romanToInt("XVIII");
//    cout<<result<<endl;
//    return 0;
//}