/*
Leetcode Problem 347. Top K Frequent Elements
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            if(um.count(nums.at(i))>0)
                um[nums.at(i)]++;    
            else
                um[nums.at(i)] = 1;    
        }
        priority_queue<pair<int,int>> pq;
        vector<int> result;
        for(auto it=um.begin();it!=um.end();++it){
             pq.emplace(make_pair(it->second,it->first));
        }
        while(!pq.empty() && k>0){
            result.emplace_back(pq.top().second);
            pq.pop();
            k--;
        }
        return result;
    }
};