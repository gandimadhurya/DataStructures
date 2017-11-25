/*
Leetcode Problem 290. Word Pattern
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
*/


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string s;
        istringstream iss(str);
        int i=0;
        int n=pattern.length();
        unordered_map<char,string> um;
        unordered_map<string, char> um_reverse;
        while ( getline( iss, s, ' ' )) {
            if(i==n)
                return false;
            if(um.count(pattern.at(i))>0 || um_reverse.count(s.c_str())>0){
                if(um[pattern.at(i)]!=s.c_str() || um_reverse[s.c_str()]!=pattern.at(i))
                    return false;
            }
            else{
                um[pattern.at(i)] = s.c_str();
                um_reverse[s.c_str()] = pattern.at(i);
            }
            // printf( "`%s'\n", s.c_str() );
            i++;
        }
        if(i!=n)
            return false;
        return true;
    }
};