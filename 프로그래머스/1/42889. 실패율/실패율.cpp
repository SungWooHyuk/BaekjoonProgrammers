#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 실패율 - 스테이지에 도달했으나 클리어 못한 수 / 도달한 사람
// N은 스테이지의 개수
// stages는 사용자들이 현재 멈춰있는 스테이지의 번호가 담긴 배열
// 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return
// 아 총 인원은 stages에서 이제 점점 빠질것.
// float로 계산이 필요하겠고

//map으로 해결하면안되나?? 그냥
// [stage] - [인원] 해서
// 1 - 1 = 1stage 1/8 - 1 
// 2 - 3 = 2stage 3/7 - 3
// 3 - 2 = 3stage 2/4 - 2

// 이건 이렇게하면되고, 그 나머지 저거 비교해서 넣는걸 어떻게 할까~
// 그냥 float랑 stage 이건 걍 vector로 pair로 받아서 시원하게
// first로 sort하고 second 넣어주자

vector<int> solution(int N, vector<int> stages) {
    unordered_map<int, int> m;
    vector<pair<float, int>> answer;
    
    int person = stages.size();
    
    for(int i = 0; i < person; ++i)
        m[stages[i]]++;
    
    for(int i = 1; i <= N; ++i)
    {
        if(person>0)
        {
            float fail = (float)(m[i]) / person;
            person -= m[i];
            answer.push_back(make_pair(fail, i));    
        }
        else
        {
            answer.push_back(make_pair(0,i));
        }
    }
    
    sort(answer.begin(), answer.end(), [](const pair<float, int> a, const pair<float, int> b)
         {
             if(a.first != b.first)
                return a.first > b.first;
             else
                return a.second < b.second;
         });
    vector<int> v;
    for(auto n : answer)
        v.push_back(n.second);
    return v;
}