#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdint>

using namespace std;

string Convert(int n, int k)
{
    if(n == 0)
        return "0";
    
    if(k == 10)
        return to_string(n);
    
    string str;
    while(n>0)
    {
        int remain = n%k;
        n /= k;
        str += remain + '0';
    }
    
    reverse(str.begin(), str.end());
    return str;
}

bool IsPrime(long long n)
{
    if(n==0 || n == 1)
        return false;
    
    for(long long i = 2; i <= sqrt(n); ++i)
    {
        if(n%i == 0)
            return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    string str = Convert(n,k);
    string temp;
    for(auto c : str)
    {
        if(c != '0')
            temp += c;
        else if( c== '0' && !temp.empty())
        {       
            if(IsPrime(stoll(temp)))
                answer++;
            
            temp.clear();
        }
    }
    
    if(!temp.empty() && IsPrime(stoll(temp))){ 
        
            answer++;
        
    }
    
    return answer;
}