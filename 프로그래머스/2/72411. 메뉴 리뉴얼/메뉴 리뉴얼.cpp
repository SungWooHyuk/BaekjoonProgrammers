#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string,int> m;
    
    for(int i = 0; i < orders.size(); ++i)
    {
        sort(orders[i].begin(), orders[i].end());
        
        for(int j = 0; j < course.size(); ++j)
        {
            if(course[j] > orders[i].length())
                continue;
            vector<bool> v(orders[i].size(), true);
            for(int k = 0 ; k < course[j]; ++k)
                v[k] = false;
            
            do{
                string str ="";
                for(int k = 0; k < orders[i].size(); ++k)
                {
                    if(v[k] == false)
                        str += orders[i][k];
                }
                m[str]++;
            }while(next_permutation(v.begin(), v.end()));
        }
    }
    
    vector<pair<string,int>> sorted;
    for(auto map : m)
    {
        if(map.second > 1)
            sorted.push_back(make_pair(map.first, map.second));
    }
    sort(sorted.begin(), sorted.end(), [](const pair<string,int>& a, const pair<string,int>& b){
        return a.second > b.second; // 내림
    });
    
    for(int i = 0 ; i < course.size(); ++i)
    {
        int max = 0;
        for(int j = 0; j < sorted.size(); ++j)
        {
            if(sorted[j].first.length() != course[i])
                continue;
            else if(max == 0){
                answer.push_back(sorted[j].first);
                max = sorted[j].second;
            }
            else if(max == sorted[j].second)
                answer.push_back(sorted[j].first);
            else
                break;
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}