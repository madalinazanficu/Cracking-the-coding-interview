#ifndef __STACK_H__
#define __STACK_H__

#include <cassert>
#include <vector>

template <typename T>
struct node {
    T element;
    T minn;

    node() {
        this->minn = 0;
        this->element = 0;
    }
    node (T data) {
        this->minn = 0;
        this->element = data;
    }
    // copy-constructor
    node (const node &other) {
        element = other.element;
        minn = other.minn;
    }
};


template <typename T, int N>
class Stack {
private:
    // Underlying array
    node <T>  stackArray[N];
    int topLevel;

public:
    // Constructor
    Stack() {
        topLevel = 0;
    }

    // Destructor
    ~Stack() {
    }

    void push(T element) {
        if (topLevel >= N) {
            return;
        }
        stackArray[topLevel].element = element;

        // cautarea minimului dinainte
        if (topLevel == 0) {
            stackArray[topLevel].minn = stackArray[topLevel].element;
        } else {

            if (stackArray[topLevel].element < stackArray[topLevel - 1].minn) {
                stackArray[topLevel].minn = stackArray[topLevel].element;
            } else {
                stackArray[topLevel].minn = stackArray[topLevel - 1].minn;
            }

        }
        topLevel++;
    }

    void pop() {
        if (topLevel)
            topLevel--;
    }

    node <T>  peek() {
        if (topLevel != 0)
            return stackArray[topLevel - 1];
        return 0;
    }


    bool isEmpty() {
        if (topLevel == 0)
            return true;
        return false;
    }

    int size() {
        return topLevel;
    }

    template <typename U, int M>
    friend std::ostream& operator<<(std::ostream& os, Stack<U, M>& stack);
};

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, Stack<T, N>& stack) {
    os << "Bottom to top: ";
    std::vector<node<T>> aux;

    while (!stack.isEmpty()) {
        aux.push_back(stack.peek());
        stack.pop();
    }

    for (int i = aux.size() - 1; i >= 0; i--) {
        os << aux[i].element << " " << aux[i].minn << "\n";
        stack.push(aux[i].element);
    }

    return os;
}

#endif // __STACK_H__
