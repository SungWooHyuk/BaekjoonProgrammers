#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
set<int> GeneratePrimes(int max)
{
    vector<bool> v(max+1, true); // 0부터 max까지
    set<int> s;
    
    v[0] = v[1] = false;
    
    for(int i = 2; i <= sqrt(max); ++i)
    {
        if(v[i])
        {
            for(int j = i*i; j <= max; j+=i){
                v[j] = false;
            }
        }
    }
    
    for(int i = 2; i <= max; ++i){
        if(v[i]){
            s.insert(i);
        }
    }
    return s;
}

int solution(int n) {
    set<int> primes = GeneratePrimes(n);
    
    return primes.size();
}