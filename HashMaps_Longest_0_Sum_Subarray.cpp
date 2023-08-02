#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int> uMap;
      int sum = 0;
      int len=0;
      uMap.insert({0,0});
    
    for(int i=0;i<A.size();i++){
    sum+=A[i];
    if(uMap.count(sum)>0){
      int temp_len=i-uMap[sum]+1;
      if(temp_len>len){
        len=temp_len;
      }
    }
    else{
          uMap.insert({sum,i+1});
    }    
    }
  return len;
    }