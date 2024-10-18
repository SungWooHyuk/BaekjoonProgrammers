#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <queue>
// 10분간 청소
// 1000개의 예약타임이 있음. - 대실 시작, 종료 
// 일단 시간은 다 분으로 바꿀것.
// 15시면 900
// 15시 30분이면 930
// 12시면 720 750은 
// 750/60 = 12 + 30 12시30분 ok ?
// 일단 다 숫자개념으로 바꾼 뒤 그리고 뒤에는 +10까지 더해준다.
// 정렬 진행 왜냐면 앞에서 부터 채워야하니
// vector에? 음 unordered_map /
// vector에서 하나씩 꺼내는게 나을듯.
// pair로
// room은 모든 예약이 있을 수있으니 정해진게없으니
// 1000개를만들어놔야하며
// vector로 pair -1 -1 로 
using namespace std;
int Cal(string str, bool end)
{
    string h = str.substr(0,2);
    string m = str.substr(3,2);
    if(end)
        return stoi(h)*60 + stoi(m) + 10;
    else
        return stoi(h)*60 + stoi(m);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<pair<int,int>> vec;
    vector<pair<int,int>> room;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    for(int i = 0; i < book_time.size(); ++i)
    {
        string s = book_time[i][0];
        string e = book_time[i][1];
        
        vec.push_back(make_pair(Cal(s, false),Cal(e, true))); // 분으로 바꿔서 넣기
    }
    
    sort(vec.begin(), vec.end(), [](const pair<int,int>& a, const pair<int,int>& b){
        return a.first < b.first;
    });
    
    for(int i = 0; i < vec.size(); ++i)
    {
        if(room.size() == 0)
            room.push_back(vec[i]);
        else
        {
            bool swap = false;
            for(int j = 0; j < room.size(); ++j)
            {
                if(room[j].second <= vec[i].first){
                    room[j] = vec[i];
                    swap = true;
                }
                
                if(swap)
                    break;
            }
            if(!swap)
                room.push_back(vec[i]);
        }
    }
    
    return room.size();
}