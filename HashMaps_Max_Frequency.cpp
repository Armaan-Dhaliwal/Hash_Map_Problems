#include<iostream>
#include<unordered_map>
#include<vector>
#include<climits>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> uMap;
    unordered_map<int,int> indexer;

    int max_freq=0;

    for(int i=0;i<arr.size();i++){
        if(uMap.count(arr[i])>0){
            uMap[arr[i]]+=1;
            if(uMap[arr[i]]>uMap[arr[max_freq]]){
                max_freq=i; 
            }
            if(uMap[arr[i]]==uMap[arr[max_freq]] && indexer[arr[i]]<indexer[arr[max_freq]]){
                max_freq=i;
            }
        }
        else{
            uMap[arr[i]]=1;
            indexer[arr[i]]=i;
            if(uMap[arr[i]]>uMap[arr[max_freq]]){
                max_freq=i;
            }
        }   
    }


   return arr[max_freq];
}