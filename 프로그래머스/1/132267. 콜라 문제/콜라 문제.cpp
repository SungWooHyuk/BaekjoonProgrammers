#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(1)
    {
        if(n<a)
            break;
        
        int ret = n/a; // 나누기
        ret *= b; // 리턴병
        int remainder = n%a; // 남은병
        
        answer += ret;
        n = remainder + ret;
    }
    
    return answer;
}