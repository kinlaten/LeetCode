class Node {
public:
  int key, val;
  Node *next, *prev;
  Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
  int _capacity;
  unordered_map<int, Node *> cache;
  Node *head, *tail;

  void removeNode(Node *node) {
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    next->prev = prev;
  }

  void addNode(Node *node) {
    Node *prev = tail->prev;

    node->prev = prev;
    tail->prev = node;

    prev->next = node;
    node->next = tail;
  }

public:
  LRUCache(int capacity) {
    _capacity = capacity;
    head = new Node(0, 0);
    tail = new Node(0, 0);

    // Both are actually dummy node, used to track LRU and MRU using next/prev
    // pointer

    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (cache.find(key) != cache.end()) {
      Node *node = cache[key];

      // this element become Most resent Used
      removeNode(node);
      addNode(node);
      return node->val;
    }
    return -1;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      removeNode(cache[key]); // remove it then we insert again to make sure it
                              // is most recent used
    }
    Node *newNode = new Node(key, value);
    cache[key] = newNode;
    addNode(newNode);

    if (cache.size() > cap) {
      Node *lru = head->next;
      removeNode(lru);
      cache.erase(lru->key);
      delete lru;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
