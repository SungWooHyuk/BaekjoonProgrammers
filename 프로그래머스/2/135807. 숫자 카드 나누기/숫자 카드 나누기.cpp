#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> getDivisors(int n) {
    vector<int> divisors;
    for(int i = 1; i * i <= n; ++i){
        if(n%i == 0) { // i가 약수라면
            divisors.push_back(i); // 작은 약수 추가
            if( i != n / i) { // 다른지 체크 
                divisors.push_back(n/i); // 큰 약수 추가 
            }
        }
    }
    return divisors;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    vector<int> aDivisor = getDivisors(arrayA[0]);
    vector<int> bDivisor = getDivisors(arrayB[0]);
    
    
    for(int i = 0; i < bDivisor.size(); ++i)
    {
        int di = bDivisor[i];
        bool Check = true;
        for(int j = 1; j < arrayB.size(); ++j)
        {
            if(arrayB[j]%di != 0)
            {
                Check = false;
                break;
            }
        }
        
        if(Check)
        {
            for(int j = 0; j < arrayA.size(); ++j)
            {
                if(arrayA[j] % di == 0)
                {
                    Check = false;
                    break;
                }
            }
        }
        
        if(Check)
            answer = max(answer, di);
    }
    
    for(int i = 0; i < aDivisor.size(); ++i)
    {
        int di = aDivisor[i];
        bool Check = true;
        for(int j = 1; j < arrayA.size(); ++j)
        {
            if(arrayA[j]%di != 0)
            {
                Check = false;
                break;
            }
        }
        
        if(Check)
        {
            for(int j = 0; j < arrayB.size(); ++j)
            {
                if(arrayB[j] % di == 0)
                {
                    Check = false;
                    break;
                }
            }
        }
        
        if(Check)
            answer = max(answer, di);
    }
    
    
    return answer;
}