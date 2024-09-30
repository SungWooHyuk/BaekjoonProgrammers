#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>
using namespace std;

// tuple의 길이가 중요한데
// { } 이 안에 숫자랑 , 로 길이를 파악해서
// 길이가 1인거부터 파악해서 넣어줘야하는데
// 왜냐면 1부터 500개의 길이까지 되는데
// 순서대로 집어넣으면서 없애줘야 answer에 넣을 수있음
// 그런데 생각해보면 1개 있는애부터 쭉 보면 
// 2는무조건
// 그러면 2를 전부 지우는과정은?
// 2를 다 지우게되면 또 길이 1인거 찾아서 ..
// 아 근데 그냥 string으로 되어있는게 왤케 맘에안들지
// {} 이거 구분해서 vector에다가 넣을까 
// s중에 가장 긴걸로 map 만든다음에
// 추가되면 1로 바꾸고 for문으로 돌때 
vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> vec(501, vector<int>(0)); //return하는 배열의 길이가 500이하니까 500개
    int cnt = 0; 
    unordered_map<int, int> m;
    bool open = false;
    string str = "";
    for(auto c : s)
    {
        if(c == '{') // 열렸을때
            open = true;
        else if(c == '}'){ // 닫혔을때
            open = false;
            if(str != "")
            {
                vec[cnt].push_back(stoi(str)); 
                str = "";
            }
        }
        else if(c == ',') 
        {
            if(!open){
                cnt++;
            }
            else
            {
                vec[cnt].push_back(stoi(str)); 
                str = ""; // 초기화
            }
        }
        else{ // 숫자일시
            str += c;
        }
    }
    
    sort(vec.begin(), vec.end(), [=](const vector<int>& a, const vector<int>& b){
       return a.size() < b.size(); 
    });
    
    
    
    for(auto n : vec.back())
        m[n] = -1;
    
    for(int i = 0; i < vec.size(); ++i)
    {
        for(int j = 0; j < vec[i].size(); ++j)
        {
            if(m[vec[i][j]] == -1)
            {
                answer.push_back(vec[i][j]);
                m[vec[i][j]] = 1;
            }
        }
    }
    return answer;
}