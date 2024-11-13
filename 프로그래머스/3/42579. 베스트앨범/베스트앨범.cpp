#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> genreMap;
    map<string,vector<pair<int,int>>> genreSort;
    for (int i=0; i<genres.size(); i++)
    {        
        genreMap[genres[i]]+=plays[i];
        genreSort[genres[i]].push_back(make_pair(i,plays[i]));
    }
    vector<pair<string,int>> genreV(genreMap.begin(),genreMap.end());
    sort(genreV.begin(),genreV.end(),[](pair<string,int> a, pair<string,int> b)
         {
             return a.second>b.second;
         });
    for (int i=0; i<genreV.size(); i++)
    {
        sort(genreSort[genreV[i].first].begin(),genreSort[genreV[i].first].end(),[](pair<int,int> a, pair<int,int>b)  {
             return a.second>b.second;
         });
        for (int j=0; j<genreSort[genreV[i].first].size(); j++)
        {
            if (j==2)
                break;
            answer.push_back(genreSort[genreV[i].first][j].first);            
        }
    }
    
    return answer;
}