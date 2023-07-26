#include<string>
using namespace std;

template <typename T>
class MapNode{
    public:
    string key;
    T val;
    MapNode<T>* next; 

    MapNode(string key, T val){
        this->key=key;
        this->val=val;
        next=NULL;
    }

    ~MapNode(){
        delete next;
    }
};

template <typename T>
class OurMap{
    private:
    int count;
    int nbuckets;
    MapNode<T>* *buckets;

    int getBucketIndex(string key){
        int hashCode=0;
        int currentCoeeficient=1;
        for(int i=key.size()-1;i>=0;i--){
            hashCode+=key[i]*currentCoeeficient;
            hashCode= hashCode%nbuckets;
            currentCoeeficient*=37;
            currentCoeeficient = currentCoeeficient%nbuckets;
        }

        return hashCode%nbuckets;
    }

    public:
    OurMap(){
        count=0;
        nbuckets=5;
        buckets = new MapNode<T>*[nbuckets];
        for(int i=0;i<nbuckets;i++){
            buckets[i]=NULL;
        }
    }

    ~OurMap(){
        for(int i=0;i<nbuckets;i++){
            delete buckets[i];
        }
        delete []buckets;
    }

    int size(){
        return count;
    }

    void insert(string key, T val){
        int bucketIndex=getBucketIndex(key);
        MapNode<T>* head=buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                head->val=val;
                return;
            }
            head=head->next;
        }

        MapNode<T>* newNode = new MapNode<T>(key,val);
        head=buckets[bucketIndex];
        newNode->next=head;
        buckets[bucketIndex]=newNode;
        count++;
        return;
    }

    T remove(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<int>* head = buckets[bucketIndex];
        if(head==NULL){
            return -1;
        }
        if(head->key==key){
            buckets[bucketIndex]=head->next;
            T data = head->val;
            head->next=NULL;
            delete head;
            count--;
            return data;
        }

        while(head->next!=NULL){
            if(head->next->key==key){
                MapNode<int>* nextNode = head->next;
                T data = nextNode->val;
                head->next=nextNode->next;
                nextNode->next=NULL;
                delete nextNode;
                count--;
                return data;
            }
        }
        return -1;
    }

    T getValue(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<int>* head = buckets[bucketIndex];
        while(head!=NULL){
            if(head->key==key){
                return head->val;
            }
            head=head->next;
        }
        return -1;
    }
};