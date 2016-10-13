#include <stdint.h>

//
// Created by Alina on 16/7/11.
//
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        //1.个位是0的情况
        //2.反转后的整型越界
        if (x == 0 ){
            return 0;
        }
        int max = 2147483647;
        int sign = 1;
        if(x < 0) {
            sign = -1;
            x = -x;
        }
        int result = 0;
        int level = 0;
        while (x > 0){
            if(level<9) {
                result = result * 10 + x % 10;
                if(!(level == 0 && x%10 == 0))
                    level++;
                x = x / 10;
            }else if(level == 9){
                if(result<max/10 || (result==max/10 && x%10<=7)){
                    result = result * 10 + x % 10;
                    level++;
                    x = x / 10;
                }else{
                    return 0;//越界了
                }
            }else{
                return 0;
            }
        }
        return result*sign;
    }
};
//int main(){
//    Solution s;
//    int result = s.reverse(1000000003000);
//    result = s.reverse(-100);
//    cout<<result<<endl;
//    return 0;
//}

