#include <string>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    pair<int,int> pos;
    
    for(int i = 0; i < park.size(); ++i){
        for(int j = 0; j < park[i].size(); ++j)
        {
            if(park[i][j] == 'S')
            {
                pos = {i,j};
                break;
            }
        }
    }
    
    unordered_map<char, pair<int,int>> directions = {
        {'N', {-1,0}}, {'S', {1,0}}, {'W',{0, -1}}, {'E', {0,1}}  
    };
    
    for(auto r : routes)
    {
        char direction = r[0];
        int move = r.back() - '0';
        
        int dx = directions[direction].first;
        int dy = directions[direction].second;
        
        int nx = pos.first;
        int ny = pos.second;
        
        bool valid = true;
        
        for(int step = 0; step < move; ++step){
            nx += dx;
            ny += dy;
            
            if(nx < 0 || nx >= park.size() || ny < 0 || ny >= park[0].size() ||
              park[nx][ny] == 'X')
            {
                valid = false;
                break;
            }
        }
        
        if(valid)
        {
            pos.first = nx;
            pos.second = ny;
        }
    }
    answer.push_back(pos.first);
    answer.push_back(pos.second);
    return answer;
}