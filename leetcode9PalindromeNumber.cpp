//
// Created by Alina on 16/7/12.
//
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int temp = x;
        int unit = 1;
        int level = 1;
        while(temp/10 != 0){
            level++;
            unit *= 10;
            temp = temp/10;
        }
        temp = x;
        bool result = true;
        while(unit>1){
            int head = temp/unit%10;
            int tail = temp%10;
            if(head != tail){
                result = false;
                break;
            }else{
                temp = temp/10;
                unit /= 100;
            }

        }
        return result;
    }
};
//int main(){
//    Solution s;
//    bool result = s.isPalindrome(121);
//    cout<<result<< endl;
//    return 0;
//}