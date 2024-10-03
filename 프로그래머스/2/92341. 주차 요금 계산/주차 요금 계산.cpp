#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cctype>
#include <iostream>
#include <cmath>
using namespace std;

int TimeConvert(string str)
{

    int hours = stoi(str.substr(0, 2));
    int minutes = stoi(str.substr(3, 2));
    return hours * 60 + minutes;
    
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<pair<int,string>>> m;

    for(int i = 0; i < records.size(); ++i)
    {
        int time = TimeConvert(records[i].substr(0,5)); // 시간
        string number = records[i].substr(6,4); // 번호
        string str = records[i].substr(11); // 마지막
        
        m[number].push_back(make_pair(time, str));
    }
    
    for(auto nu : m)
    {
        
        std::vector<std::pair<int, std::string>>& records = nu.second;

        if(records.size() % 2 != 0)
            records.push_back(make_pair(TimeConvert("23:59"), "OUT"));
        
        int cost = 0;
        int time = 0;
        for(int i = 0; i < records.size(); i+=2) // 무조건 짝수
        {
            int t = abs(records[i].first - records[i+1].first);
            time += t;
        }
        
        if(time <= fees[0])
            cost += fees[1];
        else 
        {
            cost += fees[1]; 
            double add_cost = ceil((time-fees[0])/ (double)fees[2]); 
            add_cost *= fees[3];
            cost+=add_cost;
        }
    
        answer.push_back(cost);
    }
    
    
    return answer;
}