class LRUCache {
public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int _key,int _val){
            key = _key;
            val = _val;
        }
    };
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int size;
    unordered_map<int,node*>mp;
    
    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    void deletenode(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
  
    
    int get(int key_) {
        //finding the key element if it already exist or not if existed in map,delete it and place it just after the head 
      if(mp.find(key_) != mp.end()){
          node* resnode = mp[key_];
          int res = resnode->val;
          mp.erase(key_);
          deletenode(resnode);
          addnode(resnode);
          mp[key_] = head->next;
          return res;
      }
        return -1;
    }
    
    void put(int key_, int value) {
        if(mp.find(key_) != mp.end()){
            node* existed = mp[key_];
            mp.erase(key_);
            deletenode(existed);
        }
            //if size is full then delete the tails->prev key i.e least recently used node(LRU)
        if(mp.size()==size){
            mp.erase(tail->prev->key); 
            deletenode(tail->prev);
        }
        addnode(new node(key_,value));
        mp[key_] = head->next;
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
