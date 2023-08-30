#include<unordered_map>
#include<iostream>
using namespace std;

struct obj{
    int one;
    int two;
    obj(int i,int j){
        one=i;
        two=j;
    }

    bool operator==(const obj &ob) const{
        return one==ob.one && two==ob.two;
    }
};

struct myHash{
    size_t operator()(const obj &ob) const {
        return(hash<int>()(ob.one)^hash<int>()(ob.two));
    }
};

int main(){
    unordered_map<obj,int,myHash> cMap;
    obj x(1,2);
    obj y(1,3);
    cMap[x]+=1;
    cMap[y]+=2;
    cMap[{1,9}]=3;
    cout<<cMap[{1,2}]<<endl;
    cout<<cMap[y]<<endl;
}