#include <vector>

using namespace std;

long long answer = 0;
vector<long long> dp;  // 결과를 저장할 배열

long long Fibo(int n, int dest) {
    if(n == dest) return 1;
    if(n > dest) return 0;

    // 이미 계산된 값이 있으면 그 값을 반환
    if(dp[n] != -1) return dp[n];
    
    // 값을 계산하고 저장
    dp[n] = (Fibo(n + 1, dest) + Fibo(n + 2, dest)) % 1234567;
    return dp[n];
}

long long solution(int n) {
    dp = vector<long long>(n + 1, -1);  // dp 배열 초기화
    return Fibo(0, n) % 1234567;
}