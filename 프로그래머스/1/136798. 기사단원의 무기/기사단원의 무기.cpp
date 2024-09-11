#include <string>
#include <vector>
#include <cmath>
using namespace std;

int sol(int num)
{
    if(num == 1)
        return 1;
    
    int n = 0;
    
    for(int i = 1; i <= sqrt(num); ++i)
    {
        if(num % i == 0)
        {
            if(i == num / i) // i와 num/i가 같은 경우 (제곱수)
                n++;
            else
                n += 2; // i와 num/i가 서로 다른 경우
        }
    }
    
    return n;
}
int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; ++i)
    {
        int k = sol(i);
        
        if(k > limit)
            answer += power;
        else
            answer += k;
    }
    
    return answer;
}