#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

// cnt를 하나 둬야하며, n명 즉, n번이 지나가면 cnt를 2로 늘려야한다. 처음에 1
// 그리고 words를 순서대로 읽을껀데, [0]과 back이 중요하다.
// 즉, char s와e를 갖고있으면서 살펴보면서 업데이트를 계속 해준다.
// 만약 s와e가 맞지않는다면 현재 cnt와
// 2명이 참가하고 5번째면 5%2 = 1
// 3명이 참가하고 9번째면 9%3 = 0
// 3명이 참가하고 8번째면 8%3 = 2
// 4명이 참가하고 12번째면 12%4 = 0 
// cnt % n 해서 나온걸로 만약에 0이면 n
// 그럼 push_back(n) , push_back(cnt)
// 만약끝까지 잘 이행하고 나왔다 ? 그럼 그냥 push_back(0) 2개하면된다.

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int cnt = 1;
    int rotation = 1;
    char s = words[0][0];
    char e = words[0].back();
    unordered_map<string, int> m;
    m[words[0]]++;
    for(int i = 1; i < words.size(); ++i)
    {
        if(cnt%n == 0)
            rotation++;
        cnt++;
        s = words[i][0];
        if(e == s && m[words[i]] == 0)
        {
            e = words[i].back();
            m[words[i]]++;
        }
        else
        {
            if(((i+1) % n) == 0)
                answer.push_back(n);
            else
                answer.push_back((i+1) % n);
            
            answer.push_back(rotation);
            s = ' ';
            e = ' ';
            break;
        }
    }
    
    if(s != ' ' && e != ' ')
    {
        answer.push_back(0);
        answer.push_back(0);
    }

    
    return answer;
}