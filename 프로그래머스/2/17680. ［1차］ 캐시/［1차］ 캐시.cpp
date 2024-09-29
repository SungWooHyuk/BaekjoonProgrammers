#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cctype>
// cache는 queue로 관리하고 size만큼 할당해서 cities를 받을때마다
// size까지는 그냥 넣어주고 그 이후로는 front(), pop()을 이용해서 관리를 해준다.
// 생각해보니 queue는 find와 같은게 없으니까 vector를 이용해서
// 그런데 vector의 앞을 꺼내고 밀고 하는 과정이 너무 낭비가 심할것같으니 
// queue를 사용하는게 맞을것같고 
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0)
    {
        answer = cities.size() * 5;
        return answer;
    }
    queue<string> q;
    queue<string> temp_q;
    
    for(int i = 0; i < cities.size(); ++i)
    {
        queue<string> cache;
        temp_q = q;
        bool valid = false;
        string lru;
        for(int j = 0; j < q.size(); ++j)
        {
            string str1;
            string str2;
            string str = temp_q.front();
            temp_q.pop();
            for(auto c : str)
                str1 += toupper(c);
            for(auto ch : cities[i])
                str2 += toupper(ch);
            
            if(str1.compare(str2) == 0){
                lru = str1;
                valid = true;
                
                while(temp_q.size() > 0)
                {
                    cache.push(temp_q.front());
                    temp_q.pop();
                }
                cache.push(lru);
                break;
            }
            else
                cache.push(str); 
            
        }
        
        if(valid){ 
            answer += 1; // 히트
            q = cache;
        }
        else{
            answer += 5;
            
            if(q.empty() || q.size() < cacheSize)
                q.push(cities[i]);
            else{
                q.pop();
                q.push(cities[i]);
            }
        }
        
        
    }
    
    
    return answer;
}