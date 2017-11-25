/*
Leetcode Problem 609. Find Duplicate File in System

Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.

A group of duplicate files consists of at least two files that have exactly the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:

"directory_path/file_name.txt"

Example 1:
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"]
Output:  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
*/


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        //hashmap
        //content-key, vector dir_filename-value
        multimap<string,string> um;
        vector<vector<string>> result;
        vector<string> tmp;
        unordered_map<string,int> keys;
        
        for(int i=0;i<paths.size();i++){
            istringstream iss(paths.at(i));
            string s, dir,dirfile,content;
            int j=0;
            while(getline(iss,s,' ')){
                if(j==0){
                    dir = s.c_str();
                    j=1;
                }                    
                else{
                    string temp = s.c_str();
                    
                    content = temp.substr(temp.find('(')+1,(temp.find(')')-temp.find('('))-1);
                    keys[content] = i;
                    dirfile = dir+"/"+temp.substr(0,temp.find('('));
                    um.emplace(content, dirfile);               
                }                
            }
        }

        // multimap<string,string>::iterator it = um.find("abcd");
        for(auto i:keys){
            pair <std::multimap<string,string>::iterator, std::multimap<string,string>::iterator> ret;
            ret = um.equal_range(i.first);
            
            for(multimap<string,string>::iterator it=ret.first; it!=ret.second; ++it){
                tmp.emplace_back(it->second);
            }
                
            // cout<<it.first<<"-->"<<tmp;
            if(tmp.size()>1)
                result.emplace_back(tmp);    
            tmp.clear();
        }
        std::reverse(result.begin(),result.end());
        return result;
    }
};