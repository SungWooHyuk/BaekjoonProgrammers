#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    unordered_map<int,int> m;
    
    for(auto n :tangerine)
        m[n]++;
    
    vector<pair<int,int>> vec;
    
    for(auto t : m)
        vec.push_back(make_pair(t.first, t.second));
    
    sort(vec.begin(), vec.end(), [](pair<int,int> a, pair<int,int> b){
        if(a.second == b.second)
            return a.first > b.first;
        else
            return a.second > b.second;
    });
    
    for(auto v :vec){
        k -= v.second;
        answer += 1;
        if(k <= 0)
            return answer;
    }
    return answer;
}