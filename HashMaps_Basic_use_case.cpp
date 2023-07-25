#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> uMap;
    pair<string,int> p("abc",1);
    
    //INSERTION
    uMap.insert(p);
    uMap["def"] = 2;

    cout<<"Size of the Map is: "<<uMap.size()<<endl;

    //ACCESS
    cout<<uMap.at("abc")<<endl;
    cout<<uMap["def"]<<endl;

    //DELETION
    uMap.erase("abc");
    cout<<"Size of the Map is: "<<uMap.size()<<endl;

    //CHECK PRESENCE
    if(uMap.count("xyz")>0){
        cout<<"xyz exists "<<endl;
    }
    else{
        cout<<"xyz does not exist :( "<<endl;  
    }
}