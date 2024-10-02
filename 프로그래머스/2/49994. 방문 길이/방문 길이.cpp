// 문제는 쉬운데 범위를 잘 생각해야할듯
// x가 이동할수있는 거리는 -5 <= x <= 5 즉, -5 -4 -3 -2 -1 0 1 2 3 4 5 총 11
// y가 이동할수있는 거리도 -5 <= y <= 5 같다.
// 이걸 그대로 0 1 2 3 4 5 6 7 8 9 10 으로 옮기고 5,5부터 시작이라면
// 현재 찍어주는 위치는 맞는데, dot->dot으로 갈때 1을 올려주는방식인데
// 아 도착하면 이 전을 true 해주면 이동할때
// 내 위치가 false고 도착지점이 true면 이미 지나온길 (되돌아가는상황)
// 내 위치가 false고 도착지점이 true여도 지나온게 아닐수있음.
// true - false는 무조건 안간곳이고
// true - true는 말해뭐해
// false - false도 무조건 안간곳
// false - true
// 그냥 점을 해주면? 5,5 - true
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;
int dx[4] { -1 , 1, 0, 0}; 
int dy[4] { 0, 0, -1, 1};

// L R D U
int solution(string dirs) {
    int answer = 0;
    int sx = 5; // 시작 x 좌표
    int sy = 5; // 시작 y 좌표

    // 경로를 기록하는 set. 양방향 경로를 모두 기록하기 위해 문자열로 저장
    unordered_set<string> path;

    unordered_map<char, int> m;
    m['L'] = 0;
    m['R'] = 1;
    m['D'] = 2;
    m['U'] = 3;
    
    for(int i = 0; i < dirs.size(); ++i)
    {
        int dir = m[dirs[i]];
        int nx = sx + dx[dir]; // 새로운 x 좌표
        int ny = sy + dy[dir]; // 새로운 y 좌표

        // 범위를 벗어나지 않는 경우에만 이동
        if(nx >= 0 && nx <= 10 && ny >= 0 && ny <= 10)
        {
            // 현재 좌표와 다음 좌표를 기록 (양방향 경로 저장)
            string forward_path = to_string(sx) + to_string(sy) + to_string(nx) + to_string(ny);
            string backward_path = to_string(nx) + to_string(ny) + to_string(sx) + to_string(sy);

            if(path.find(forward_path) == path.end() && path.find(backward_path) == path.end()) {
                // 처음 지나가는 경로라면 answer 증가
                answer++;
                // 양방향 경로를 모두 저장
                path.insert(forward_path);
                path.insert(backward_path);
            }
            // 캐릭터 위치 업데이트
            sx = nx;
            sy = ny;
        }
    }
    
    return answer;
}