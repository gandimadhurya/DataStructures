/*
Leetcode Problem 76. Minimum Window Substring
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> um;
        int begin = 0, end =0, counter;
        int min_length = s.length()+1, min_begin=-1;
        for(auto i:t)
            ++um[i];
        counter=um.size();
        while(end<s.length()){
            if(um.find(s.at(end))!=um.end()){
                um[s.at(end)]--;
                if(um[s.at(end)]==0)
                    counter--;
            }
            end++;
            while(counter==0){
                if(um.find(s.at(begin))!=um.end()){
                        um[s.at(begin)]++;
                    if(um[s.at(begin)]>0)
                        counter++;
                }
                if((end-begin<min_length) && counter>0){
                    min_length = end-begin;
                    min_begin = begin;
                }
                begin++;
            }
        }
        cout<<min_begin<<"->"<<min_length<<endl;
        return (min_begin!=-1)?s.substr(min_begin,min_length):"";
    }
};