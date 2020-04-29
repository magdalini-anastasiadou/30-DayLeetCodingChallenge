#include <iostream>
#include <limits>

class Node {
public:
    int val;
    Node* prev;

public:
    Node() : val(0), prev(nullptr) {}
    Node(int val, Node* prev) : val(val), prev(prev) {}

    ~Node() {
        delete prev;
    }
};

class MinStack {
private:
    Node* root;
    int min_n;
public:
    /** initialize your data structure here. */
    MinStack(): root(nullptr), min_n(std::numeric_limits<int>::max()) {}
    ~MinStack() {
        delete root;
    }

    void push(int x) {
        this->root = new Node(x, this->root);
        if (x < min_n)
            this->min_n = x;
    }

    void pop() {
        if (this->root)
            this->root = this->root->prev;
    }

    int top() {
        return this->root->val;
    }

    int getMin() {
        Node* cur = this->root;
        int min = cur->val;
        while (cur)
        {
            if (cur->val < min)
                min = cur->val;
            cur = cur->prev;
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
