#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numbers;

    // 초기 숫자 배열 생성
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }

    // 팩토리얼 계산
    long long fact = 1;
    for (int i = 2; i <= n; ++i) {
        fact *= i;
    }

    // 0-based 인덱스 조정을 위해 k 감소
    k -= 1;

    // 순열 계산
    for (int i = 0; i < n; ++i) {
        fact /= (n - i); // (n-1)! 계산
        int idx = k / fact; // 현재 자리의 숫자 결정
        answer.push_back(numbers[idx]);
        numbers.erase(numbers.begin() + idx); // 사용한 숫자 제거
        k %= fact; // 나머지를 통해 다음 자리 계산
    }

    return answer;
}
