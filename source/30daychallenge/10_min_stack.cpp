#include <iostream>

class MinStack {
private:
    struct elem{
        int v, min;
        elem* next;

        elem(int v, int min, elem* next) : v(v), min(min), next(next) {}
    };

    elem* head;
public:
    /** initialize your data structure here. */
    MinStack() {
        head = nullptr;
    }
    
    void push(int x) {
        if(!head) head = new elem(x, x, nullptr);
        else head = new elem(x, x < head->min ? x : head->min, head);
    }
    
    void pop() {
        head = head->next;        
    }
    
    int top() {
        return head->v;
    }
    
    int getMin() {
        return head->min;
    }
};

int main() {
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    std::cout << minStack->getMin() << std::endl;   //--> Returns -3->
    minStack->pop();
    std::cout << minStack->top() << std::endl;      //--> Returns 0->
    std::cout << minStack->getMin() << std::endl;   //--> Returns -2->
}