/*
Leetcode Problem 205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.

Note:
You may assume both s and t have the same length.
*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char,char> um;
        unordered_map<char,char> um_reverse;
        for(int i=0;i<s.length();i++){
            if(um.count(s.at(i))>0 || um_reverse.count(t.at(i))>0){
                if(um[s.at(i)]!=t.at(i) || um_reverse[t.at(i)]!=s.at(i))
                    return false;
            }                
            else{
                um[s.at(i)] = t.at(i);
                um_reverse[t.at(i)] = s.at(i);
            }
                
        }
        return true;
    }
};