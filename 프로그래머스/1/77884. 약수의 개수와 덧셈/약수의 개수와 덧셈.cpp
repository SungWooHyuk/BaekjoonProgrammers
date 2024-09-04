#include <cmath>

int solution(int left, int right) {
    int result = 0;
    for (int num = left; num <= right; ++num) {
        // num이 완전 제곱수인지 확인
        if (sqrt(num) == static_cast<int>(sqrt(num))) {
            result -= num;  // 약수의 개수가 홀수인 경우 빼기
        } else {
            result += num;  // 약수의 개수가 짝수인 경우 더하기
        }
    }
    return result;
}