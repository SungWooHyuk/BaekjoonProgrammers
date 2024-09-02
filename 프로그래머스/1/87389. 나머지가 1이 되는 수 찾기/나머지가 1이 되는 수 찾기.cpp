#include <string>
#include <vector>

// n을 x로 나눈 나머지가 1이 되도록 하는 가장 작은 자연수 x를 리턴

using namespace std;


int solution(int n) {   
    for(int i = 1; i < n; ++i)
    {
        if(n%i == 1)
            return i;
    }
}