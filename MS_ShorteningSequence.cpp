//
// Created by Alina on 2016/10/10.
//

#include <iostream>
using namespace std;
int main(){
//    freopen("/Users/Alina/ClionProjects/ForJob/Google/a","r",stdin);
//    freopen("/Users/Alina/ClionProjects/ForJob/Google/SafeSquaresOutput","w",stdout);
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    int cnt = 0;
    int num1 = 0;
    int num2 = 0;
    for(int i=0;i<n;i++){
        if(arr[i]%2==0)
            num2++;
        else
            num1++;
    }
    cnt = num1 - num2;
    if(cnt < 0)
        cnt = -cnt;
    cout << cnt << endl;
    return 0;
}