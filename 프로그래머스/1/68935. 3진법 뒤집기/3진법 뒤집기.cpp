#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    string str = "";
    int answer = 0;
    while(n > 0)
    {
        int remainder = n%3;
        n = n/3;
        
        str = to_string(remainder) + str;
    }
    
    for(int i = str.size(); i > 0; --i)
    {
        int num = 1;
        for(int j = 1; j < i; j++)
            num *= 3;
        answer += (str[i-1] - '0') * num; 
    }
    
    return answer;
}