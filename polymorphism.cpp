#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
#include <stdexcept>

using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};


class LRUCache: public Cache {
public:
    LRUCache(const int capacity) {
        cp = capacity;
        tail = nullptr;
        head = nullptr;
    }

    virtual void set(int key, int value) {
        if (get(key) == -1) {
            Node* node = new Node{key, value};

            // not in cache yet
            if (mp.size() == cp) {
                // Remove LRU node
                Node* lru_node = tail;

                // Since it has a value in the cache
                // we need to erase the entry
                mp.erase(lru_node->key);

                // Set next to new tail
                tail = lru_node->next;

                // Release free store memory
                delete lru_node;

                // Finally set new node
                mp[key] = node;

                // Add new node to the front
                head->next = node;
                node->prev = head;
                head = node;

            } else {
                // Just add it to front since it's most recently used
                if (head == nullptr) {
                    head = node;
                    tail = node;
                } else {
                    head->next = node;
                    node->prev = head;
                    head = node;
                }
                mp[key] = head;
            }
        } else {
            // Since it's in the cache just update it
            Node* n = mp.at(key);
            n->value = value;
        }
    }

    virtual int get(int key) {
        try {
            Node* n = mp.at(key);
            return n->value;
        } catch(std::out_of_range& e) {
            return -1;
        }
    }

};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

