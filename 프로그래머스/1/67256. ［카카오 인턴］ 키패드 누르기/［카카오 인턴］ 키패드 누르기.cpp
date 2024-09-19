// 엄지손가락은 상하좌우
// 가운데만 더 가까운 엄지손가락을 이용 같다면 손잡이로
// 가운데 숫자 키패드를 어떻게 누르냐에 따라서 달라짐.
// 3에 있으면 1 2 3 4 순
// 6에 있으면 2 1 2 3
// 9에 있으면 3 2 1 2
// #에 있으면 4 3 2 1


// 오른손이 2에 있으면 그게 0
// 왼손이 4에 있으면 그게 1
// 그런데 5를 찾자면 5는 1
// 즉, 1,1 은 1이고
// 0,1은 2이다
#include <string>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

string solution(vector<int> numbers, string hand) {
    int middle[2][4][4] = 
    {
        {
        1, 2, 3, 4,
        2, 1, 2, 3,
        3, 2, 1, 2,
        4, 3, 2, 1
        },
        {
        0, 1, 2, 3,
        1, 0, 1, 2,
        2, 1, 0, 1,
        3, 2, 1, 0
        }
    };
    
    
    
    if(hand == "left")
        hand = "L";
    else
        hand = "R";

    string answer = "";
    pair<int,int> pos_l = make_pair(0, 3);
    pair<int,int> pos_r = make_pair(0, 3);
    for(auto n : numbers)
    {
        if(n%3 == 1) // 좌측
        {
            answer += "L";
            pos_l.first = 0;
            pos_l.second = n/3;
        }
        else if(n%3 == 0 && n != 0) // 우측
        {
            answer += "R";
            pos_r.first = 0;
            pos_r.second = n/3 - 1;
        }
        else
        {
            if(n == 0)
            {
                if(middle[pos_l.first][pos_l.second][3] < middle[pos_r.first][pos_r.second][3]){
                    answer += "L";
                    pos_l.first = 1;
                    pos_l.second = 3;
                }
                else if(middle[pos_l.first][pos_l.second][3] > middle[pos_r.first][pos_r.second][3]){
                    answer += "R";
                    pos_r.first = 1;
                    pos_r.second = 3;
                }
                else{
                    answer += hand;
                    if(hand == "R"){
                        pos_r.second = 3;
                        pos_r.first = 1;
                    }
                    else{
                        pos_l.second = 3;
                        pos_l.first = 1;
                    }
                }
            }
            else
            {
                if(middle[pos_l.first][pos_l.second][n/3] < middle[pos_r.first][pos_r.second][n/3]){
                    answer += "L";
                    pos_l.first = 1;
                    pos_l.second = n/3;
                }
                else if(middle[pos_l.first][pos_l.second][n/3] > middle[pos_r.first][pos_r.second][n/3]){
                    answer += "R";
                    pos_r.first = 1;
                    pos_r.second = n/3;
                }
                else{
                    answer += hand;
                    if(hand == "R"){
                        pos_r.second = n/3;
                        pos_r.first = 1;
                    }
                    else{
                        pos_l.second = n/3;
                        pos_l.first = 1;
                    }
                }
            }
        }
    }
    
    return answer;
}