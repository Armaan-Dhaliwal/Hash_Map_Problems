#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;



int ZeroPairSum(int n, vector<int> arr){
    //Using HashMaps

    int counter=0;
    int zeroes=0;
    unordered_map<int,int> negMap;
    unordered_map<int,int> posMap;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            int ele=-arr[i];
            if(negMap.count(ele)<0){
                negMap[ele]=1;
            }
            else{
                negMap[ele]+=1;
            }
        }
        else if(arr[i]>0){
            if(posMap.count(arr[i])<0){
                posMap[arr[i]]=1;
            }
            else{
                posMap[arr[i]]+=1;
            }
        }
        else{
            zeroes+=1;
        }
    }

    for(int i=0;i<arr.size();i++){
        if(posMap[arr[i]]>0 && negMap[arr[i]]>0){
            int num=posMap[arr[i]]*negMap[arr[i]];
            counter+=num;
            negMap[arr[i]]=0;
        }
        if(arr[i]==0 && zeroes>0){
            zeroes-=1;
            counter+=zeroes;
        }
    }

    return counter;
}

int main(){
    vector<int> res;
    vector<int> arr;
    cout<<"Enter elements for Array 1: "<<endl;
    int ele;
    cin>>ele;
    while(ele!=-999){
        arr.push_back(ele);
        cin>>ele;
    }
    cout<<ZeroPairSum(arr.size(),arr);
}