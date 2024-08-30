#include <string>
#include <vector>
#include <map>
// 종류별로 최대 1가지 의상만.
// 다른 의상이 겹치지 않거나, 추가로 착용하면 다른 옷
// 일단 [headgear] [eyewear] 같은애들이 대 분류 [1] 
// headgear에 2개 eyewear에 1개면
// 총 5 
// 1. map을 만들어서 string을 키로 벨류를 그냥 int로해서 ++해준다.
// 2. 만들어진 map의 개수가 5개면 총 5개의 종류가 있는것이고
// 3. value들을 다 더해준 값은 일단 기본 베이스 (하나씩 착용하는 버전)
// 4. 
// 5. hat에 3개 eye에 4개 pants에 3개가 있으면 만들 수 있는 조합의 수는
// 6.
// 7. 2 1 이면
// 첫번째자리에 0 1 2 3
// 두번째자리에 0 1 2 3 4
// 세번째자리에 0 1 2 3
// 4 * 5 * 4 - 1 = 79개의 종류
// 000은 안되니까 -1
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> clothesmap;
    
    for(int i = 0; i < clothes.size(); ++i)
        clothesmap[clothes[i][1]]++; 
    
    int k = 1;
    for(auto& n : clothesmap)
        k *= (n.second+1); // 0추가
    
    return k-1; // 모두가 0일확률 없애기
}