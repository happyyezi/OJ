//
// Created by Alina on 16/7/13.
//
#include <iostream>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string s[4][10] = {{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                           {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                           {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                           {"", "M", "MM", "MMM"}};
        string result = "";
        int digit = 0;
        while (num > 0){
            int remain = num%10;
            result = s[digit][remain] + result;
            num = num/10;
            digit++;
        }
        return result;
    }
};
//int main(){
//    Solution s;
//    string result = s.intToRoman(4);
//    cout<<result<<endl;
//    return 0;
//}
