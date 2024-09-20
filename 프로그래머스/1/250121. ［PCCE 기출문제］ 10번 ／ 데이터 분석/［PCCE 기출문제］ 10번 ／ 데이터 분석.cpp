#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// data에서 ext값이 val_ext보다 작은 데이터로 sort_by에 해당하는 값을 기준으로 오름차순 정렬
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    map<string, int> m;
    m["date"] = 1;
    m["code"] = 0;
    m["maximum"] = 2;
    m["remain"] = 3;
    
    // ext가 어떤 정보 기준
    // val_ext 보다 작은애들
    // sort_by값으로 오름차순 정렬
    int ex = m[ext];
    for(int i = 0; i < data.size(); ++i)
    {
        if(data[i][ex] < val_ext)
            answer.push_back(data[i]);
    }
    // remain이 string이긴한데, 
    int sot = m[sort_by];
    
    sort(answer.begin(), answer.end(), [sot](vector<int> a, vector<int> b){
        return a[sot] < b[sot];
    });
    
    return answer;
}