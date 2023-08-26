/*
    Given a list of tickets, find itinerary in order using the given list.

Example: 

Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output: 
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
It may be assumed that the input list of tickets is not cyclic and there is one ticket from every city except the final destination.
*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    cout<<"Enter number of enteries: "<<endl;
    int n;
    cin>>n;
    vector<pair<string,string>> vec;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a;
        cin>>b;
        vec.push_back({a,b});
    }

    unordered_map<string,int> fMap;
    unordered_map<string,string> lMap;
    for(int i=0;i<n;i++){
        fMap[vec[i].first]+=1;
        fMap[vec[i].second]+=1;
        lMap[vec[i].first]=vec[i].second;
    }

    string src, des;
    for(auto i=fMap.begin();i!=fMap.end();i++){
        if(i->second ==1){
            if(lMap.count(i->first)>0){
                src = i->first;
            }
            else{
                des = i->first;
            }
        }
    }
    // cout<<src<<endl;
    // cout<<des<<endl;

    string output="";

   for(int i=0;i<n;i++){
    output+=src+" -> "+lMap[src]+" ";
    src=lMap[src];
   } 
   cout<<"OUTPUT: "<<output<<endl;
}

// 4 Chennai Banglore Bombay Delhi Goa Chennai Delhi Goa
