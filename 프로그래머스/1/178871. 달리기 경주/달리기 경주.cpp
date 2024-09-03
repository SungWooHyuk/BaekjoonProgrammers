#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> playerPositions;
    
    for(int i = 0; i < players.size(); ++i)
        playerPositions[players[i]] = i;
    
    for (const string& calling : callings) {
        int currentIndex = playerPositions[calling];
        
        if (currentIndex > 0) { // 첫 번째 플레이어가 아니면
            int previousIndex = currentIndex - 1;
            string previousPlayer = players[previousIndex];
            
            // 두 플레이어의 위치를 스왑
            swap(players[currentIndex], players[previousIndex]);
            
            // 위치 맵 업데이트
            playerPositions[calling] = previousIndex;
            playerPositions[previousPlayer] = currentIndex;
        }
    }
    
    return players;
}