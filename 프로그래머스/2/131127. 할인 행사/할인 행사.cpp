#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> m;
    unordered_map<string, int> temp_m;
    int size = 0;
    bool valid = true;
    for(int i = 0; i< want.size(); ++i){
        m[want[i]] += number[i];
        size += number[i];
    }
    temp_m = m;
    
    for(int i = 0; i <= discount.size() - size; ++i)
    {
        temp_m = m;
        valid = true;
        
        for(int j = i; j < i+size; ++j)
        {
            if(temp_m[discount[j]] != 0)
                temp_m[discount[j]]--; 
            else{
                valid = false;
                break;
            }    
        }
        
        if(valid)
            answer++;
    }
    return answer;
}