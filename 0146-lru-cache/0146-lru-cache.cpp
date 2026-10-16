class LRUCache {
public:
    class Node {
        public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
        }

    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> keyToAddressMapping;
    int capacity;
    LRUCache(int capacity) { 
        this->capacity = capacity;
        head->next=tail;
        tail->prev=head;
        }

    void addNextToHead(Node *node){
        Node *nodeNextToHead = head->next;
        head->next=node;
        node->prev=head;
        node->next=nodeNextToHead;
        nodeNextToHead->prev=node;
    }

    void removeNode(Node *node){

        Node * prevNode = node->prev;
        Node * nextNode = node->next;
        node->prev=NULL;
        node->next=NULL;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }

    int get(int key) {
        if(keyToAddressMapping.find(key)==keyToAddressMapping.end()) return -1;

        Node *node=keyToAddressMapping[key];
        removeNode(node);
        addNextToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if(keyToAddressMapping.find(key)!=keyToAddressMapping.end()){
            Node *node = keyToAddressMapping[key];
            node->value=value;
            removeNode(node);
            addNextToHead(node);
        }
        else{
            if(keyToAddressMapping.size()==capacity){
                Node *deleteNode = tail->prev;
                removeNode(deleteNode);
                keyToAddressMapping.erase(deleteNode->key);
                delete deleteNode;
            }
            Node *newNode = new Node(key,value);
            keyToAddressMapping[key]=newNode;
            addNextToHead(newNode);

        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */