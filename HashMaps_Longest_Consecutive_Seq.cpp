#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> uMap;
        int len=0;
        for(int i=0;i<nums.size();i++){
            uMap[nums[i]]=true;
        }

        for(auto i=uMap.begin();i!=uMap.end();i++){
            if(i->second){
                int ei=1;
                int current=i->first;
                while(uMap.count(current-1)>0){
                    uMap[current]=false;
                    ei++;
                    current-=1;
                }

                current=i->first;
                while(uMap.count(current+1)>0){
                    uMap[current]=false;
                    ei++;
                    current+=1;
                }
                if(ei>len){
                    len=ei;
                }
            }
        }
        return len;
    }