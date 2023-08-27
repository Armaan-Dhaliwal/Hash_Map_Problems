#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector <int> countDistinct (int A[], int n, int k)
    {   
        unordered_map<int,int> uMap;
        vector<int> res;
        for(int i=0;i<k;i++){
            uMap[A[i]]+=1;
        }
        
        int count=0;
        for(auto i=uMap.begin();i!=uMap.end();i++){
                count++;
        }
        res.push_back(count);
        
        for(int i=k;i<n;i++){
            if(uMap[A[i]]==0){
                uMap[A[i]]+=1;
                count++;
            }
            else{
               uMap[A[i]]+=1; 
            }
        
            if(uMap[A[i-k]]==1){
                uMap[A[i-k]]-=1;
                count--;
            }

            else if(uMap[A[i-k]]>=2){
                uMap[A[i-k]]-=1;
            }
            res.push_back(count);
        }
       