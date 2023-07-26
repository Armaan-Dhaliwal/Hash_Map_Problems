#include<iostream>
#include"HashMaps_Implementation_Class.cpp"
using namespace std;

int main(){
    OurMap<int> map;
    cout<<map.size()<<endl;
    map.insert("abc",1);
    map.insert("def",2);
    cout<<map.size()<<endl;
    cout<<map.remove("abc")<<endl;
    cout<<map.size()<<endl;
    cout<<map.getValue("def")<<endl;
    cout<<map.size()<<endl;
    cout<<map.remove("def")<<endl;

}