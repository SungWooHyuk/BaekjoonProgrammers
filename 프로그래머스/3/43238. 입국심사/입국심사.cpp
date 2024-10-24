#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    long long left = 1; // 최소 시간
    long long right = (long long)times.back() * n; // 최대 시간 (최악의 경우)
    long long answer = right;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long total = 0;
        
        for (int time : times) {
            total += mid / time; // 해당 시간동안 각 심사관이 처리할 수 있는 사람 수
        }
        
        if (total >= n) { // n명 이상을 처리할 수 있으면 시간을 줄여본다
            answer = mid;
            right = mid - 1;
        } else { // 처리할 수 있는 사람 수가 부족하면 시간을 늘린다
            left = mid + 1;
        }
    }
    
    return answer;
}
