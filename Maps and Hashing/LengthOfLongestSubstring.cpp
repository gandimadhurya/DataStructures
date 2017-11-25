/*
Leetcode Problem 3. Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<2)
            return s.length();
        unordered_map<char,int> um;
        int max_length = 0;
        int begin = 0,end = 0;
        while(end<(s.length())){
            if(um.find(s.at(end))==um.end()){
                um[s.at(end)] =1;
            end++;
            }
            else{
                max_length = max_length>um.size()?max_length:um.size();
                um.clear();
                begin++; 
                end=begin;
            }
            
        }
        return max_length>um.size()?max_length:um.size();
    }
};