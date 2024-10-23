#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = n - 1;  // 마지막 인덱스부터 시작
    
    while (d >= 0) {
        int delivery_cap = 0;  // 배송 잔여 용량
        int pickup_cap = 0;    // 픽업 잔여 용량
        int furthest = -1;     // 가장 먼 집을 저장하는 변수
        
        // 배송 처리
        for (int i = d; i >= 0; --i) {
            if (deliveries[i] > 0) {
                furthest = max(furthest, i);  // 가장 먼 배송처 갱신
                
                // 배송 처리
                if (delivery_cap + deliveries[i] <= cap) {
                    delivery_cap += deliveries[i];
                    deliveries[i] = 0;  // 해당 집의 배송 완료
                } else {
                    deliveries[i] -= (cap - delivery_cap);  // 남은 용량만큼 배송
                    delivery_cap = cap;  // 용량이 다 찼으므로 더 이상 배송 불가
                    break;
                }
            }
        }
        
        // 픽업 처리
        for (int i = d; i >= 0; --i) {
            if (pickups[i] > 0) {
                furthest = max(furthest, i);  // 가장 먼 픽업처 갱신
                
                // 픽업 처리
                if (pickup_cap + pickups[i] <= cap) {
                    pickup_cap += pickups[i];
                    pickups[i] = 0;  // 해당 집의 픽업 완료
                } else {
                    pickups[i] -= (cap - pickup_cap);  // 남은 용량만큼 픽업
                    pickup_cap = cap;  // 용량이 다 찼으므로 더 이상 픽업 불가
                    break;
                }
            }
        }
        
        // 가장 먼 집까지 왕복해야 하므로 거리 두 배를 더함
        if (furthest != -1) {
            answer += (furthest + 1) * 2;
        }

        // d 갱신: 방문하지 않은 가장 먼 집을 찾음
        while (d >= 0 && deliveries[d] == 0 && pickups[d] == 0) {
            --d;  // 배송과 픽업이 모두 완료된 경우 다음 집으로 이동
        }
    }
    
    return answer;
}
