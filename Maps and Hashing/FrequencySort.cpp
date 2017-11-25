/*
Leetcode Problem 451. Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.
*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> um;
        string result;
        for(int i=0;i<s.length();i++){
            if(um.count(s.at(i))>0)
                um[s.at(i)]++;
            else
                um[s.at(i)] = 1;
        }
        priority_queue<pair<int,char>> mypq;
        for ( auto it = um.begin(); it != um.end(); ++it ){
            mypq.push(make_pair(it->second,it->first));
        }
        while (!mypq.empty())
          {
            for(int i=0;i<mypq.top().first;i++)
                result += mypq.top().second;
            mypq.pop();
          }
        
        return result;
    }
};