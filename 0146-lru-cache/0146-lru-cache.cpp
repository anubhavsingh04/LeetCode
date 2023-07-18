class LRUCache {
public:
    class node{
        public:
        int key,val;
        node*prev,*next;
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    node*head=new node(-1,-1);
    node*tail=new node(-1,-1);
    int cap;
    unordered_map<int,node*>m;
    
    void addnode(node*newnode){
        node*tmp=head->next;
        newnode->next=tmp;
        tmp->prev=newnode;
        newnode->prev=head;
        head->next=newnode;
    }
    
    void deletenode(node* delnode){
        node*delprev=delnode->prev;
        node*delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key_) {
        if(m.find(key_)!=m.end()){
            // if key is existing in cache 
            node*resnode=m[key_];
            int res=resnode->val;
            m.erase(key_); // becuse it holds old adress 
            deletenode(resnode); // delete it to make it insert at head ->next
            addnode(resnode); // adding after head which means most recently used 
            m[key_]=head->next; // assigining new adress 
            return res;
        }
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_)!=m.end()){
            // if key is already exists in map take it from map and also delete from list and upadte 
            node*existingnode=m[key_];
            m.erase(key_);  // deleting from the map 
            deletenode(existingnode); // deleting from the list
        }
        if(m.size()==cap){
            m.erase(tail->prev->key); // if size becomes equal to capacity delete that adress from map
            deletenode(tail->prev); // delete fromm the list 
        }
        addnode(new node(key_,value));//add the new key and value after head as it is most recently used
        m[key_]=head->next; // update the new adress 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */