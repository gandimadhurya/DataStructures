/*
Leetcode Problem 438. Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.
*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> um;
        vector<int> result;
        for(auto i: p)
            ++um[i];
        int begin =0, end = 0, counter;
        counter = um.size();
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
                
                if((end-begin)==p.length())
                    result.emplace_back(begin);
                begin++;                
            }
                     
        }
        return result;
    }
};