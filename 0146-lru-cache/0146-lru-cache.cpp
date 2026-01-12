class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node (int _key,int _val){
            key=_key;
            val=_val;
        }
    };

    int cap;
    Node *head= new Node(-1,-1);
    Node *tail= new Node(-1,-1);
    map<int,Node*>mp;


    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void addNode(Node *node){
        Node *temp= head->next;
        head->next=node;
        node->prev=head;
        temp->prev=node;
        node->next=temp;
    }
    void removeNode(Node *node){
        Node *left=node->prev;
        Node *right=node->next;
        left->next=right;
        right->prev=left;
        
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node *node=mp[key];
        removeNode(node);
        addNode(node);
        return node->val;

        
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *node=mp[key];
            node->val=value;
            removeNode(node);
            addNode(node);
        }
        else {
            if(cap==mp.size()){
            Node *deleteNode = tail->prev;
            removeNode(deleteNode);
            mp.erase(deleteNode->key);
            delete deleteNode;
            
            }
            Node *newNode = new Node(key,value);
            addNode(newNode);
            mp[key]=newNode;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */