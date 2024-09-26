#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
    
    if(a > b)
    {
        int temp = b;
        b = a;
        a = temp;
    }
    // 첫라운드는 무조건 홀수 vs 짝수
    if(a % 2 != 0 && b % 2 == 0) // 홀수
    {    
        if(a+1==b)
            return answer;
    }
    else if(b%2 != 0 && a % 2 == 0)
    {
        if(b+1 == a)
            return answer;
    }
    
    
    while(n > 0)
    {
        n /= 2;
        answer++;
        if(a%2 != 0)
        {
            a+=1;
            a/=2;
        }
        else
            a/=2;
        
        if(b%2 != 0)
        {
            b+=1;
            b/=2;
        }
        else
            b/=2;
        
        if(a %2 != 0 && b%2 == 0)
            if(a+1 == b)
                return answer;
        else if(a%2 == 0 && b%2 != 0)
            if(b+1 == a)
                return answer;
    }
    
    return answer;
}