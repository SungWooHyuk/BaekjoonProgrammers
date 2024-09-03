#include <string>
#include <vector>

using namespace std;

// attack의 길이는 길어도 100이고, 일단 가장 마지막에 있는 attacks의 시간만큼 돌면된다.
// Heal의 카운트가 필요하며 해당 카운트가 유효할 시 연속 붕대로 체크된다.
struct Band
{
    int healTime;
    int heal;
    int bonusHeal;
};
struct Player
{
    int heal;
};

struct Monster
{
    int coolTime;
    int attackDamage;
};

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    Band band;
    band.healTime = bandage[0];
    band.heal = bandage[1];
    band.bonusHeal = bandage[2];
    
    Player player;
    player.heal = health;
    
    vector<Monster> monsters;
    for (int i = 0; i < attacks.size(); ++i) {
        Monster m;
        m.coolTime = attacks[i][0];
        m.attackDamage = attacks[i][1];
        monsters.push_back(m);
    }
    int cnt = 0;
    int monsterCnt = 0;
    int bandCnt = 0;
    int lastMonster = attacks[attacks.size()-1][0];
    while(1)
    {
        cnt++;
        bandCnt++;
        if(monsters[monsterCnt].coolTime == cnt)
        {
            player.heal -= monsters[monsterCnt].attackDamage;
            monsterCnt++;
            bandCnt = 0;
        }
        else if(band.healTime == bandCnt){
            player.heal += band.heal;
            player.heal += band.bonusHeal;
            bandCnt = 0;
        }
        else
        {
            player.heal += band.heal;
        }
        
        if(player.heal > health)
            player.heal = health;
        
        if(player.heal <= 0)
            return -1;
        
        if(cnt == lastMonster)
            break;
    }
    
    return player.heal;
}