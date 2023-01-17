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


using namespace std;
typedef pair<string,int>info; //carnumber total time spent
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int size=records.size();
    unordered_map<string,int> table; //car number , time it came in
    unordered_map<string,bool> carpool;//car number, is it in the parking lot? bool
    unordered_map<string,int> overall;//stores cumulative info of car time
    
        string time;
        string number;
        string inout;
    for(int i=0;i<size;i++)
    {
        istringstream pp(records[i]);
        pp>>time>>number>>inout;
        int hour=stoi(time.substr(0,2));
        int min=stoi(time.substr(3,2));
        min+=hour*60;
        if(inout=="IN")
        {
            //cout<<"hi\n";
            if(carpool.count(number)==0)
            {
                //table.insert(number);
                table[number];
                carpool.insert(make_pair(number,true));
                //overall.insert(make_pair(number,0));
                overall[number];
                //cout<<"overall: "<<overall[number]<<"\n";
            }
            if(carpool[number]==false)
            {
                carpool[number]=true;
            }
            table[number]=min;
            //cout<<timetmp<<"\n";
        }
        if(inout=="OUT")
        {
            carpool[number]=false;
            overall[number]+=(min-table[number]);//((difftime(timetmp,table[number]))/60);
            table[number]=0;
            //cout<<number<<" "<<overall[number]<<"\n";
        }
    }
    for(auto i=overall.begin();i!=overall.end();i++)
    {
        if(carpool[i->first]==true)
        {
            i->second+=(1439-table[i->first]);
        }
    }
    vector<info> finale;
    for(auto i=overall.begin();i!=overall.end();i++)
    {
        finale.push_back(info(i->first,i->second));
    }
    sort(finale.begin(),finale.end());
    for(auto i=finale.begin();i!=finale.end();i++)
    {
        //cout<<i->first<<" "<<i->second<<"\n";
        int timespent=i->second;
        int value=0;
        if(timespent<=fees[0]){answer.push_back(fees[1]);continue;}
        value=((timespent-fees[0])/fees[2]);
        if((timespent-fees[0])%fees[2]>0)
        {
            value+=1;
        }
        value*=fees[3];
        value+=fees[1];
        answer.push_back(value);
    }
    return answer;
}
