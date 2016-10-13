//
// Created by Alina on 2016/10/10.
//

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <time.h>
using namespace std;

struct event{
    int time;
    int sid;
    int oindex;
    event(int t,int s,int o):time(t),sid(s),oindex(o){}
    bool operator< (const event & e2) const{
        return time != e2.time ? time > e2.time : sid > e2.sid;
    }
};


int main(){
//    freopen("/Users/Alina/ClionProjects/ForJob/Google/c","r",stdin);
//    freopen("/Users/Alina/ClionProjects/ForJob/Google/cout","w",stdout);
    map<int,int> stu_index;
    map<int,int> stu_t;
    map<int,vector<int>> stu_o;
    map<int,vector<int>> stu_w;
    priority_queue<event> events;
    int result[10001];
    int off_wait[101];
    int stus[10001];
    memset(off_wait,0, sizeof(off_wait));

    int N,M,K;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++){
        int S,T,P;
        cin >> S >> T >> P;
        stus[i] = S;
        stu_index[S] = i;
        stu_t[S] = T;
        vector<int> temp(101,0);
        stu_w[S] = temp ;
        for(int j=0;j<P;j++){
            int oid,w;
            cin >> oid >> w;
            stu_o[S].push_back(oid);
            stu_w[S][oid] = w;
        }
    }

    for(int i=0;i<N;i++){
        event temp(stu_t[stus[i]]+K,stus[i],0);
        events.push(temp);
    }

    while(!events.empty()){
//        event temp(events.top().time,events.top().sid,events.top().oindex);
        int temp_time = events.top().time;
        int temp_oindex = events.top().oindex;
        int temp_sid = events.top().sid;
        events.pop();
        temp_time = max(temp_time,off_wait[stu_o[temp_sid][temp_oindex]]) + stu_w[temp_sid][stu_o[temp_sid][temp_oindex]];
        off_wait[stu_o[temp_sid][temp_oindex]] = temp_time;
        if(temp_oindex == stu_o[temp_sid].size()-1){
            result[stu_index[temp_sid]] = temp_time;
        }else{
            temp_time += K;
            temp_oindex ++;
            event temp(temp_time,temp_sid,temp_oindex);
            events.push(temp);
        }
    }
    for(int i=0;i<N;i++)
        cout << result[i] <<endl;
}