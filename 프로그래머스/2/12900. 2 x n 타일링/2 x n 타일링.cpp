#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> vec(n+1);
    
    vec[0] = 0;
    vec[1] = 1;
    vec[2] = 2;
    
    for(int i = 3; i <= n; ++i)
    {
        vec[i] = (vec[i-1] + vec[i-2]) % 1000000007;
    }
    
    return vec[n];
}