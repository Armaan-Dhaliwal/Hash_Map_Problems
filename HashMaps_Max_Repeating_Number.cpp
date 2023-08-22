#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;

int maxRepeating(int *arr, int n, int k) {
	    unordered_map<int,int> uMap;
	    int num=arr[0];
	    uMap[arr[0]]=1;
	    for(int i=1;i<n;i++){
	        uMap[arr[i]]+=1;
	     if(uMap[arr[i]]>uMap[num]){
	         num=arr[i];
	     }   
	    }
	    int maxFreq=uMap[num];
	    
	    for(auto i=uMap.begin();i!=uMap.end();i++){
	        if(i->second==maxFreq){
	            if(i->first<num){
	                num=i->first;
	            }
	        }
	    }
	    return num;
	}