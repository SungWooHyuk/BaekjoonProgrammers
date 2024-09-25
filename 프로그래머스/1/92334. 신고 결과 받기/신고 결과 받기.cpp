// 유저는 한 번에 한명의 유저 신고
// 중복은 1회고 무제한
// k번 이상 중복되면 이용 정지, 신고한 모든 유저들에게 정지 사실 메일 발송 -> 마지막에

// id_list 크기로 2차원 배열을 만들어서 진행을 하는게 좋을듯
// 2차원배열로 만들어서 report로 0->1로 바꿔주고 
// 이제 frodo 라인을 쭉 봐서 k 이상이면 각 frodo line에 체크 한 사람들을 + 1 해준다.

// 위 방법은 괜찮은거같으면서도 함정이 있는게, report가 이제 muzi 이런식이라 int형으로는 힘들다.
// 그렇다면 ? 신고한 사람 , 신고 당한 사람 이 짝꿍이 되어야함.
// 2차원 배열이 제일 좋은데, 

// 세로 즉, j줄을 쭉 봤을때 k랑 비교해서 만약에 i번째(frodo가 1번째일때)
// 1을 쭉 봐서 k랑 비교
// i가 1이고 j는 0~size 까지보고 k랑 비교할것. k보다 크다?? 이러면 정지인데 메일 날려야겠지?
// 0,1 , 2, 1 즉, [변수][j] 해서 0이 아닌애들은 배열 하나 더 만들어서
// 추가해주기. id[i]++; 이런식으로 하면 되겠네

#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    unordered_map<string, int> u_m;
    int cnt = 0;
    for(auto id : id_list)
    {
        u_m[id] = cnt;
        cnt++;
    }
    
    int id_map[1001][1001] { 0, }; // 0번이 1번을.
    // 4 * 4
    for(auto str : report)
    {
        string from = "";
        string to = "";
        int cnt = 0;
        for(auto c : str)
        {
            if(c != ' ')
            {
                cnt++;
                from += c;
            }
            else
            {
                to += str.substr(cnt+1);
                break;
            }
        }
        id_map[u_m[to]][u_m[from]]++;
    }
    
    vector<int> answer(id_list.size(), 0);
    
    for(int i = 0; i < id_list.size(); ++i)
    {
        int num = 0;
        for(int j = 0; j < id_list.size(); ++j)
        {
            if(id_map[i][j] != 0)
                num++;
        }
        
        if(num >= k) // 메일 날리기 
        {
            for(int k = 0; k < id_list.size(); ++k)
            {
                if(id_map[i][k] != 0)
                    answer[k]++;
            }
        }
        
    }
    
    return answer;
}