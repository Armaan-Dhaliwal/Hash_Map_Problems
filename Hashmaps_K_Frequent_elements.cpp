#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> uMap;
        for(int i=0;i<nums.size();i++){
            if(uMap.count(nums[i])>0){
                uMap[nums[i]]+=1;
            }
            else{
                uMap.insert({nums[i],1});
            }
        }
        vector<pair<int,int>> tempVec;
        for(auto i=uMap.begin();i!=uMap.end();i++){
            tempVec.push_back({i->second,i->first});
        }
        sort(tempVec.rbegin(),tempVec.rend());

        vector<int> res;
        int i=0;
        while(k>0){
            k--;
            res.push_back(tempVec[i].second);
            i++;
        }
        return res;
    }