#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    stack<int> add_con; // 보조 컨테이너
    int truck_top = 0; // 현재 트럭에 적재된 상자 번호
    int answer = 0; // 적재된 상자의 수

    for (int i = 0; i < order.size(); ++i) {
        while (truck_top < order[i]) {
            truck_top++; // 트럭에 넣을 상자 번호 증가
            add_con.push(truck_top); // 새로운 상자를 추가 컨베이어에 넣기
        }

        if (add_con.top() == order[i]) {
            add_con.pop(); // 추가 컨베이어에서 상자를 꺼내서 트럭에 적재
            answer++; // 적재된 상자 수 증가
        } else {
            break; // 상자가 적재될 수 없는 경우
        }
    }

    return answer; // 적재된 상자의 수 리턴
}
