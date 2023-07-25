#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    unordered_map<int,int> uMap;
    int arr[]={1,2,3,2,1,5,4,1,3};
    vector<int> vec;
    for(int i=0;i<9;i++){
        if(uMap.count(arr[i])>0){
            continue;
        }
        else{
            uMap[arr[i]]=1;
            vec.push_back(arr[i]);
        }
    }

    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" "<<endl;
    }
}