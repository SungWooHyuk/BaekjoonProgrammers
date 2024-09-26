#include <iostream>
using namespace std;

// 이진수에서 1의 개수를 계산하는 함수
int countOnes(int num) {
    int count = 0;
    while (num > 0) {
        count += num % 2;
        num /= 2;
    }
    return count;
}

int solution(int n) {
    int cnt = countOnes(n); // n의 1의 개수
    
    while (true) {
        n++;
        if (cnt == countOnes(n)) { // 1의 개수가 같으면 종료
            break;
        }
    }
    
    return n;
}
