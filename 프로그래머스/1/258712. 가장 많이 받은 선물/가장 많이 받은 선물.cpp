// 기록이 있으면 크기비교
// 없거나 같으면 선물 지수 비교
// 선물 지수는 친구들에게 준 선물의 수 - 받은 선물의 수 -> 음수가능
// 만약 같다면 이젠 끝
// 다음달에 가장 많은 선물을 받는 친구가 받을 선물의 수를 return
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// 2차원 배열
// 선물지수
// 기록할거
// i와 j 비교
int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    int cnt = 0;
    int size = friends.size();
    int f[51][51] {0}; // 2차원 배열
    unordered_map<string, int> m; // 순서
    vector<int> gift(size, 0); // 선물지수
    vector<int> ret(size, 0); // 기록용
    
    for(auto str : friends){
        m[str] = cnt;
        cnt++;
    }
    
    for(auto gift : gifts)
    {
        int space_num = gift.find(" ");
        string from = gift.substr(0, space_num);
        string to = gift.substr(space_num+1);
        
        f[m[to]][m[from]]++; // 2차원 배열 생성
    }
    
    for(int i = 0; i < size; ++i)
    {
        int to = 0;
        int from = 0;
        for(int j = 0; j < size; ++j)
        {
            from += f[i][j];
            to += f[j][i];
        }
        
        gift[i] = to - from;
    }
    
    
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            
                if(f[i][j] < f[j][i]){ // i가j한테 준 선물의 수가 j가 i한테 준 선물의 수보다 많으면
                    
                    ret[i]++;
                }
                else if(f[i][j] == f[j][i]) // 선물 지수
                {
                    if(gift[i] > gift[j])
                        ret[i]++;
                }
            
        }
    }
   

    sort(ret.begin(), ret.end(), greater<>());
    
    return ret[0];
}