#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    string str, output;
    cout<<"Enter your string: "<<endl;
    cin>>str;

    unordered_map<char,int> uMap;
    for(int i=0;i<str.length();i++){
        char current = str[i];
        if(uMap.count(current)>0){
            continue;
        }
        else{
            uMap[current]=1;
            output+=current;
        }
    }

    cout<<output<<endl;

}