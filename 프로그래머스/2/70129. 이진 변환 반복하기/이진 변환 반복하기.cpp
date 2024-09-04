#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int num = 0;
    int loop = 0;
    
    while(1)
    {
        string next = ""; 
        loop++;
        int n = 0;
        for(auto c : s)
            if(c == '0')
                n++;
    
        num = s.size() - n; // 0 제거 후 길이
        cnt += n;
        while (num > 0)
        {
            int remainder = num%2;
            num = num/2;
            next = to_string(remainder) + next; // 변환해서 next에 넣기
        }
        
        if(next.compare("1") == 0)
            break;
        
        s = next;
    }
    answer.push_back(loop);
    answer.push_back(cnt);
    return answer;
}