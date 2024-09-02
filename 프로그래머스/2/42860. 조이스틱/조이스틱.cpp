#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
// 1 <= name <= 20
// only 대문자

// JEROEN 이면
// AAAAAA 에서
// A->J 9
// 커서이동 1
// A->E 4
// 커서이동 1
// A->R 17 or 9
// 커서이동 1
// A->O 12
// 커서이동 1
// A->E 4
// 커서이동 1
// A->N 13

// AAN이면?
// 
// JAN 이면
// AAA 에서
// A->J 9
// 커서이동 왼쪽이든 1
// A-> 무시
// 커서이동 1
// A->N 13
// 이렇게되면 24인데, A는 무시할꺼라 커서이동을 왼쪽 커서이동을 하면된다.
// 즉, 알파벳이 앞이랑 뒤 중에 뭐가 더 빠른지
// A는 아예 무시하고 다음 위치가 어딘지 확인한다음에 커서를 어떻게 이동할지 앞이 빠른지 뒤가 빠른지 이거 2개 체크

// 1. string으로 받는 name을 길이만큼 substr해서 하나씩 뜯어볼것.
// 2. answer에 계속 값을 담아줄것.
// 3. 담아줄때 체크할껀 1. 알파벳이 A인지 2. 아니라면 앞이빠른지 뒤가 빠른지 체크하고 이동값도 체크하기 3. 맞다면 무시하고 이동값 // 체크하기


#include <iostream>
#include <cmath>
int answer = 0;
int cur = 0;
using namespace std;

void Min(int dest)
{
    // 대문자 A는 65 Z는 90이다. 아스키코드
    int A = 65;
    int Z = 91; // 하지만 Z로 가는것도 조이스틱을 동작해야함.

    if(abs(dest - A) <= abs(Z - dest))
        answer += abs(dest - A);
    else
        answer += abs(Z - dest);
    
}
void Cur(int now, int i, int length) {
    // 오른쪽으로 이동하는 거리
    int rightMove = (i >= now) ? (i - now) : (length - now + i);

    // 왼쪽으로 돌아가는 거리
    int leftMove = (now + length - i) % length;

    // 최적의 이동 경로 선택
    if (rightMove <= leftMove) 
        answer += rightMove;
    else
        answer += leftMove;
    
    // 현재 커서 위치를 업데이트
    cur = i;
}

int solution(string name) {
    //int length = name.length(); // 총 길이
    //for(int i = 0; i < name.length(); ++i)
    //{
    //    if(name[i] != 'A')
    //    {
    //        if(i != 0) // 0일땐 커서를 움직이지 않음.
    //            Cur(cur, i, length); // 이걸로 커서질 하는거임
    //        Min(static_cast<int>(name[i])); // 값 더해주고
    //    }
    //}

   // return answer;
    int alphaMove[26] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int ans = 0, n = name.size();
    int minMove = n-1;
    for(int x = 0; x < n; x++){
        ans += alphaMove[name[x]-'A'];
        int y = x + 1; // x 오른쪽에 있으면서 A가 아닌 문자가 있는 위치를 y라하자
        while( y < n && name[y] == 'A') y++;
        minMove = min( minMove, min( x+x+(n-y), x+(n-y)+(n-y) ) );
    }
    ans += minMove;
    return ans;
}

