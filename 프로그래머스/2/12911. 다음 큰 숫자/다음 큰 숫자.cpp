// n의 다음 큰 숫자는 n보다 큰 자연수
// n과 n+1은 2진수로 변환했을때 1의 갯수가 같음. 0001   0010  0100   1000    1  2   4   8 
// n의 다음 큰 숫자는 최소임
// 78 - 1001110
// 83 - 1010011

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int first_n = n;
    int cnt = 0;
    while(first_n > 0)
    {
        int remain = first_n%2;
        if(remain == 1)
            cnt++;
        first_n /= 2;
    }
    int cnt_s = 0;
    while(cnt != cnt_s)
    {
        cnt_s = 0;
        n++;
        int second_s = n;

        while(second_s > 0)
        {
            int remain = second_s%2;
            if(remain == 1)
                cnt_s++;
            second_s /= 2;
        }
    }
    
    return n;
}