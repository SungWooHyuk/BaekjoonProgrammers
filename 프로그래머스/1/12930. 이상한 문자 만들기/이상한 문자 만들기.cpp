#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    string answer = "";
    
    int cnt = 0;
    for(auto n : s)
    {
        if(n == ' '){
            cnt = 0;
            answer += ' ';
        }
        else
        {
            if(cnt%2 == 0) // 짝
                answer += toupper(n);
            else
                answer += tolower(n);
        
            cnt++;
        }
        
    }
    
    return answer;
}