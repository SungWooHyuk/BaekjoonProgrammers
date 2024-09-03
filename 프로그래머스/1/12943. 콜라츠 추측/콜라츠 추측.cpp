#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    while(1)
    {
        if(num == 1)
            return answer;
        
        if(num % 2 == 0) // 짝
        {
            num = num / 2;
        }
        else if(num % 2 == 1)// 홀
        {
            num = (num * 3) + 1; 
        }
        
        answer++;
        
        if(answer > 500)
            return -1;
        
    }
    
    return answer;
}