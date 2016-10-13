//
// Created by Alina on 16/7/11.
//
#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int* l_interval = new int[numRows];
        string result = "";
        if (numRows == 1){
            return s;
        }
        for(int i=0;i<numRows;i++){
            l_interval[i] = 2*(numRows-1)-2*i;
        }
        int i=0;
        int old_head = 0;
        int old_cur = 0;
        int curl = 0;
        while(i<s.length()){
            if (curl >= numRows)
                break;
            if(old_cur<s.length()){
                if(l_interval[curl]>0){
                    result += s[old_cur];
                    i++;
                    old_cur = old_cur + l_interval[curl];
                }
            }else{
                old_head++;
                old_cur = old_head;
                curl++;
                continue;
            }
            if(old_cur<s.length()){
                if(l_interval[numRows-curl-1]>0){
                    result += s[old_cur];
                    i++;
                    old_cur = old_cur + l_interval[numRows-curl-1];
                }
            }else{
                old_head++;
                old_cur = old_head;
                curl++;

            }
        }
        delete[] l_interval;
        return result;
    }
};
//
//int main(){
//    Solution s;
//    string result = s.convert("ABCD",3);
//
//    cout<<result<<endl;
//    return 0;
//}