#include<unordered_map>
#include<map>
#include<iostream>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int,int> uMap;
	int count=0;
	for(int i=0;i<n;i++){
		int current = arr[i];
		if(uMap.count(current)>0){
			uMap[current]+=1;
		}
		else{
			uMap[current]=1;
		}
	}

	for(auto i=uMap.begin();i!=uMap.end();i++){
		if(k==0){
			while(i->second>0){
			i->second-=1;
			int current = i->first;
			if(uMap[current+k]>0){
				count++;
			}
			if(uMap[current-k]>0){
				count++;
			}
			}	
		}
		else{
            if(i->second>0){
                i->second-=1;
                int current = i->first;
                int temp_count=0;
                int temp_count2=0;
                if(uMap.count(current+k)>0){
                    temp_count++;
                    temp_count*=uMap[current+k];
                }
                if(uMap.count(current-k)>0){
                    temp_count2++;
                    temp_count2*=uMap[current-k];
                }
                count+=temp_count+temp_count2;
		    }
        }
	}
	return count;
}

int main(){
    int arr[]={4,4,4,4};
    int k=0;
    cout<<getPairsWithDifferenceK(arr,4,k)<<endl;;
}