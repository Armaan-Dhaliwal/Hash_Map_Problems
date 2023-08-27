#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
    class comp{
        public:
        bool operator()(ListNode* &n1, ListNode* &n2){
            if(n2->val>n1->val){
                return false;
            }
            return true;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL){
                pq.push(lists[i]);
            }
        }
        
        ListNode* root = NULL;    
        if(!pq.empty()){
            root=pq.top();
            ListNode* tempTop = pq.top();
            pq.pop();
            if(tempTop->next!=NULL){
                pq.push(tempTop->next);
            }
            
        }
        
        ListNode* temp = root;
        while(!pq.empty()){
            temp->next=pq.top();
            temp=temp->next;
            ListNode* tempTop = pq.top();
            pq.pop();
            if(tempTop->next!=NULL){
                pq.push(tempTop->next);
            }      
        }

        return root;
    }