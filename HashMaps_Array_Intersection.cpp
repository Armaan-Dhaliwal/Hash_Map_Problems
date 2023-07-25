#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    vector<int> res;
    vector<int> arr1;
    cout<<"Enter elements for Array 1: "<<endl;
    int ele;
    cin>>ele;
    while(ele!=-1){
        arr1.push_back(ele);
        cin>>ele;
    }

    vector<int> arr2;
    cout<<"Enter elements for Array 2: "<<endl;
    cin>>ele;
    while(ele!=-1){
        arr2.push_back(ele);
        cin>>ele;
    }

    unordered_map<int,int> map1;
    unordered_map<int,int> map2;

    for(int i=0;i<arr1.size();i++){
        if(map1.count(arr1[i])>0){
            map1[arr1[i]]+=1;
        }
        else{
            map1[arr1[i]]=1;
        }
    }

    for(int i=0;i<arr2.size();i++){
        if(map2.count(arr2[i])>0){
            map2[arr2[i]]+=1;
        }
        else{
            map2[arr2[i]]=1;
        }
    }

    sort(arr1.begin(),arr1.end());
    for(int i=0;i<arr1.size();i++){
        if(map2[arr1[i]]>0){
            int num=min(map1[arr1[i]],map2[arr1[i]]);
            map2[arr1[i]]=0;
            for(int k=0;k<num;k++){
                res.push_back(arr1[i]);
            }
        }
    }


    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}