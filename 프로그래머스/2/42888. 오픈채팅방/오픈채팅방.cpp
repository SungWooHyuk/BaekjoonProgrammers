#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <iostream>
using namespace std;

// Enter, Leave는 들어왔습니다, 나갔습니다구분이고 Change는 같은 
// id를 가진 곳 찾아서 이름을 바꿔줘야함

// id - Prodo
// 결국 마지막에 변경된 닉네임으로 할꺼라서 사실 마지막꺼만보면된다.
// 참고로 닉네임 중복가능
// 그러면 일단 id부분으로 unordered_map을 만들어서 최종닉네임을 저장해놓은후에
// 즉, 0이랑 1로는 vector<pair로 하나씩 push를 한뒤에
// vec[0].first 랑 .second로 닉네임 찾아서 넣어주면 어때 ??
// change면 그냥 unordered_map에서 미리 바꾸면되잖아
// 오키 그러면 어차피 순서대로니까 닉네임 
string enter_s = "님이 들어왔습니다.";
string leave_s = "님이 나갔습니다.";
vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string, string> m;
    vector<pair<string, string>> vec;
    
    for(auto re : record)
    {
        stringstream ss(re);
        string state;
        string id;
        string name;
        
        ss >> state;
        ss >> id;
        ss >> name;
        
        if(m[id] == "") // 첫 등록
            m[id] = name;
        
        if(state == "Change") // 변경
            m[id] = name;
        else if(state == "Enter")
        {
            if(m[id] != name)
                m[id] = name; // 나가서 바꾼거라 업데이트
            vec.push_back(make_pair(state, id));
        }
        else 
            vec.push_back(make_pair(state, id));
        
        
    }
   
    for(int i = 0; i < vec.size(); ++i)
    {
        string str;
        if(vec[i].first == "Enter")
            str = str + m[vec[i].second] + enter_s;
        else
            str = str + m[vec[i].second] + leave_s;
        
        answer.push_back(str);
    }
    
    return answer;
}