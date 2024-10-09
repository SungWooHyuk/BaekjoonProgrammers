#include <string>
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for(long long num : numbers) {
        if (num % 2 == 0) {
            // 짝수일 경우 num + 1이 비트가 1개 다른 가장 작은 수
            answer.push_back(num + 1);
        } else { // 홀
         
            long long bit = 1;
            while (num & bit) {
                bit <<= 1;
            }
            // 첫 번째 0을 1로 바꾸고, 그 다음 비트를 0으로 바꿈
            answer.push_back((num | bit) & ~(bit >> 1));
        }
    }
    
    return answer;
}