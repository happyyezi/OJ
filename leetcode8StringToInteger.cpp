//
// Created by Alina on 16/7/12.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        //空白字符,整型越界
        int max = 2147483647;
        int min = -2147483648;
        int result = 0;
        int level = 0;
        int sign = 1;
        bool haschar = false;
        for(int i=0;i<str.length();i++){
            if((int)str[i]>=48 && (int)str[i]<=57){
                haschar = true;
                if(level<9) {
                    result = result * 10 + (int) str[i] - 48;
                    level++;
                }else if(level == 9){
                    if((sign>0 && ((result < max/10) || (result == max/10 && ((int)str[i]-48)<=7)))
                       ||(sign<0 && ((result < max/10) || (result == max/10 && ((int)str[i]-48)<=8)))){
                        result = result * 10 + (int)str[i] - 48;
                        level ++;
                    }else{
                        if(sign>0)
                            return max;
                        else
                            return min;
                    }
                }else{
                    if(sign>0)
                        return max;
                    else
                        return min;
                }
            }else if((int)str[i]==45 && level == 0 ){
                if (haschar == false) {
                    haschar = true;
                    sign = -1;
                }else{
                    return 0;
                }
            }else if((int)str[i]==43 && level == 0){
                if (haschar == false) {
                    haschar = true;
                    sign = 1;
                }else{
                    return 0;
                }
            }else if((int)str[i]==32 && haschar== false){
                continue;
            }else {
                return result*sign;
            }
        }
        return result*sign;
    }
};

//int main(){
//   //48~57:0~9,45:-,32:
//    Solution s;
//    int result = s.myAtoi("2147483647");
//    cout<<result<<endl;
//
//    return 0;
//}