#include <string>
#include <vector>

// 최대공약수
// 최대공배수

// 배열의 맨 앞에 최대공약수 -> 최소공배수
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 최소공배수를 구하는 함수
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    answer.push_back(gcd(n,m));
    answer.push_back(lcm(n,m));
    
    return answer;
}