//
// Created by Alina on 16/3/17.
//

#ifndef FORJOB_KMP_H
#define FORJOB_KMP_H

#include <iostream>
using namespace std;
int * GetNextArray(const string pattern){
    int * next = new int[pattern.size()];
    next[0] = -1;
    int compare_index;
    for (int i=1;i<pattern.size();i++){
        compare_index = next[i-1];
        while(compare_index != -1 && pattern[compare_index] != pattern[i-1]){
            compare_index = next[compare_index];
        }
        next[i] = compare_index + 1;
    }
    return next;
}
int StringMatch(const string str,const string pattern){
    int * next = GetNextArray(pattern);
    int j = 0;
    int match_begin = -1;
    for(int i=0;i<str.size();i++){
        while(str[i]!=pattern[j] && j!=-1){
            j = next[j];
        }
        if(j == pattern.size()-1){
            match_begin = i-j;
            break;
        }
        j++;
    }
    return match_begin;
}


#endif //FORJOB_KMP_H
