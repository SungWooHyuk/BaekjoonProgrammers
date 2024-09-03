#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n > 0)
    {
        int remainder = n%3;
        n = n/3;
        
        if(remainder == 0)
        {
            answer += '4';
            n -= 1;
        }
        else if(remainder == 1)
            answer += '1';
        else
            answer += '2';
    }
    
    reverse(answer.begin(), answer.end());
    return answer;
}