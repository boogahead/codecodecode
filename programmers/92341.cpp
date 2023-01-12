#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <math.h>
#include <sstream>
#include <ctime>
#include <iomanip>
//https://school.programmers.co.kr/learn/courses/30/lessons/92341?language=cpp

using namespace std;
typedef pair<string,int>info; //carnumber total time spent
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int size=records.size();
    unordered_map<string,time_t> table; //car number , time it came in
    unordered_map<string,bool> carpool;//car number, is it in the parking lot? bool
    unordered_map<string,int> overall;//stores cumulative info of car time
    
    for(int i=0;i<size;i++)
    {
        istringstream pp(records[i]);
        string time;
        string number;
        string inout;
        pp>>time>>number>>inout;
        istringstream ttmp(time);
        struct tm when;
        ttmp>>get_time(&when,"%H:%M");
        time_t timetmp=mktime(&when);
        if(inout=="IN")
        {
            //cout<<"hi\n";
            if(carpool.count(number)==0)
            {
                table.insert(make_pair(number,0));
                carpool.insert(make_pair(number,true));
                overall.insert(make_pair(number,0));
            }
            if(carpool[number]==false)
            {
                carpool[number]=true;
            }
            table[number]=timetmp;
            //cout<<timetmp<<"\n";
        }
        if(inout=="OUT")
        {
            carpool[number]=false;
            overall[number]+=((difftime(timetmp,table[number]))/60);
            table[number]=0;
            cout<<overall[number]<<"\n";
        }
    }
    return answer;
}
