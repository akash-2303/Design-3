// Time Complexity: O(1) for both get and put operations
// Space Complexity: O(n) where n is the capacity of the cache
// Did this code successfully run on Leetcode : Yes

// Approach:
// 1. We will use a doubly linked list to maintain the order of the keys and a hashmap to store the key-node pairs.
// 2. We will maintain a head and a tail node. Head will be the least recently used node and tail will be the most recently used node.
// 3. For get operation, we will check if the key is present in the hashmap. If yes, we will remove the node from its current position and add it to the head.
// 4. For put operation, we will check if the key is present in the hashmap. If yes, we will update the value of the node and move it to the head.
// 5. If the capacity is full, we will remove the node before the tail node and delete it from the hashmap.


class LRUCache {
    private: 
        struct Node{
            int key, value; 
            Node* prev;
            Node* next;
            Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
        };
    
        int capacity; 
        unordered_map<int, Node*> cache;
        Node* head;
        Node* tail;
    public:
        LRUCache(int capacity) {
            this -> capacity = capacity;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head -> next = tail;
            tail -> prev = head;
    
        }
        
        int get(int key) {
            if(cache.find(key) != cache.end()){
                Node* node = cache[key];
                removeNode(node);
                addtoHead(node);
                return node -> value;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if(cache.find(key) != cache.end()){
                Node* node = cache[key];
                node -> value = value;
                removeNode(node);
                addtoHead(node);
            }else{
                //Check capacity
                if(capacity <= cache.size()){
                    Node* tailPrev = tail -> prev;
                    removeNode(tailPrev);
                    cache.erase(tailPrev -> key);
                    delete tailPrev;
                }
                Node* newNode = new Node(key, value);
                cache[key] = newNode;
                addtoHead(newNode);
            }
        }
    private: 
        void removeNode(Node* node){
            node -> prev -> next = node -> next;
            node -> next -> prev = node -> prev;
        }
    
        void addtoHead(Node* node){
            node -> prev = head;
            node -> next = head -> next;
            head -> next -> prev = node;
            head -> next = node;
        }
    };