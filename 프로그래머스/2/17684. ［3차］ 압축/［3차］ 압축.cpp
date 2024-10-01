#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> solution(string msg) {
    unordered_map<string, int> m;
    for(int i = 0; i < 26; ++i)
        m[string(1, 'A'+i)] = i+1; // A부터Z까지 1~26 할당
    
    int cnt = 27; // m 추가용
    string str; // 추가용
    string str2; // 넣기용
    vector<int> answer;
    
    for(int i = 0; i < msg.size(); ++i) // msg를 처음부터 끝까지 살펴볼껀데
    {    
        str += msg[i];
        int skip = 0; // 스킵용

        while(1)
        {    
            if(m[str] == 0) // 존재하지않음 
            {
                m[str] = cnt;
                answer.push_back(m[str2]);
                cnt++; // 사전순서 관리
                str.clear(); // str 비워주고
                i += (skip-1); // skip만큼 i를 뛰어넘어주고
                break; // 종료
            }
            else // 존재함
            {
                str2 =str; // 무조건 처음엔 옴
                skip++; // skip을 늘려주고
            }
            
            // 범위체크
            if(i+skip < msg.size())
                str += msg[i+skip];
            else // 범위초과임
                if(!str.empty())
                {
                    if(m[str] == 0)
                        answer.push_back(cnt);
                    else
                        answer.push_back(m[str]);
                    
                    i += (skip);
                    break; // 끝내기
                }
        }
    }
    
    
    
    
    return answer;
}