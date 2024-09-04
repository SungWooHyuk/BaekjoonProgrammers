#include <string>
#include <vector>

// 10이면

// 1 + 2 + 3 + 4
// 10

// 12면
// 1 + 2 + 3 + 4 = 10
// 3 + 4 + 5 = 12
// 
using namespace std;

int solution(int n) {
    int answer = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        int num = 0;
        for(int j = i; j <= n; ++j)
        {
            num += j;
            if(num == n)
            {
                answer++;
                break;
            }
            else if (num > n)
                break;
        }
    }
    
    return answer;
}