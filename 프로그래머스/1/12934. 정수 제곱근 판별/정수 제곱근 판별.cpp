#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    while(true)
    {
        if(sqrt(n) == answer)
            break;
        else if(sqrt(n) < answer)
        {
            return -1;
        }
        else
            answer++;
    }
    
    answer += 1;
    
    return answer*answer;
}