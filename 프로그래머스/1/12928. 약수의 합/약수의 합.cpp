#include <string>
#include <vector>

// n의 약수를 모두 더한 값

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n; ++i)
        if(n%i == 0) answer+=i;
    
    return answer;
}