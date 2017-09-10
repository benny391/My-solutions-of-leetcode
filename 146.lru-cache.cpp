struct node 
{
    int val;
    node *next = nullptr, *prior = nullptr;
    node(int v) :val(v) {}
};

class mylist 
{
public:
    void move_to_last(node *);
    node *push_back(int);
    int remove_head();
private:
    node *head = nullptr, *rear = nullptr;
};

node *mylist::push_back(int k) 
{
    if (head == nullptr) 
    {
        head = rear = new node(k);
    }
    else 
    {
        rear->next = new node(k);
        rear->next->prior = rear;
        rear = rear->next;
    }
    return rear;
}

void mylist::move_to_last(node * n)
{
    if (head == rear || n == rear)
        return;
    if (n == head)
    {
        head = head->next;
        head->prior = nullptr;
    }
    else 
    {
        n->prior->next = n->next;
        n->next->prior = n->prior;
    }
    rear->next = n;
    n->prior = rear;
    n->next = nullptr;
    rear = n;
}

int mylist::remove_head()
{
    if (head == nullptr) 
        return -1;
    node *tmp = head;
    head = head->next;
    if (head != nullptr) 
        head->prior = nullptr;
    int ret = tmp->val;
    delete tmp;
    return ret;
}

class LRUCache 
{
public:
    LRUCache(int capacity) 
    {
        this->capacity = capacity;
    }
    
    int get(int key) 
    {
        if (m.find(key) == m.end()) 
            return -1;
        pair<int, node*> ret = m[key];
        l.move_to_last(ret.second);
        return ret.first;
    }
    
    void put(int key, int value) 
    {
        node *n;
        if (m.find(key) == m.end()) 
        {
            size++;
            n = l.push_back(key);
        }
        else 
        {
            n = m[key].second;
            l.move_to_last(n);
        }
        m[key] = make_pair(value, n);
        if (size > capacity) 
        {
            size--;
            int ret = l.remove_head();
            if (ret != -1) 
                m.erase(ret);
        }
    }
    int capacity, size = 0;
    unordered_map<int, pair<int, node*> > m;
    mylist l;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
