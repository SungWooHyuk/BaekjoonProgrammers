#include <string>
#include <vector>
#include <algorithm>
// n편 중 - h번 이상 인용된 논문이 h편 이상이고 나머지 논문이 h번 이하 h의 최대값이 과학자의 H-INDEX
// 논문의 수 -  0 <= citations <= 10000
// 5편 중 - 3번 이상 인용된 논문이 3편 이상이고 나머지 논문이 3번 이하 인용되었다면 3이 과학자의 최대값

// 1. 정렬을 진행 내림차순으로
// 2. 6 5 3 1 0 이면 중앙값부터 차례대로 서칭해본다 return 3
// ex) 9 6 2 1 0 이면 ? 최대값은? return 1
// 5편 중 - 1번 이상 인용된 논문이 1편 이상이고 나머지 논문이 1번 이하 인용
// ex) 500 10 8 7 4 3 2 0 이면 최대값은?  return 4
// 8편 중 - 4번 이상 인용된 논문이 4편 이상이고 나머지 논문이 4번 이하 인용. 
// 정렬을하고 위에서부터 내려오면서 조건을 검색해준다
// 조건 1은 H번 이상 인용된 논문이 H편 이상이어야한다.
// 참 - 나머지 논문이 H번 이하 여야한다. - 불 다음 찾기
// 참 - 리턴

using namespace std;
// 100 98 50 43 33 25 12 8 5 0

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), [](int a, int b)
         {
             return a > b;
         });
   int answer = 0;
    for (int i = 0; i < citations.size(); i++) {
        if (citations[i] >= i + 1) {
            answer = i + 1;
        } else {
            break;
        }
    }
    return answer;
}