#ifndef __MY_STACK_H__
#define __MY_STACK_H__

#include <assert.h>
#include <vector>

template <typename T, int N>
class Stack {

private:
    T stackArray[N];
    int topLevel;

public:
    Stack() {
        topLevel = 0;
    }

    ~Stack() {

    }

    void push(T element) {
        if (topLevel >= N) {
            return;
        }
        stackArray[topLevel] = element;
        topLevel++;
    }

    void pop() {
        if (topLevel)
            topLevel--;
    }

    T peek() {
        return stackArray[topLevel - 1];
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
    friend std::ostream& operator<<(std::ostream& os, Stack<U, M> & stack);
};

// template <typename T, int N>
// std::ostream& operator<<(std::ostream &os, Stack <T, N> &stack) {

//     os << "Bottom to top: ";
//     std::vector<T> aux;

//     while (!stack.isEmpty()) {
//         aux.push_back(stack.peek());
//         stack.pop();
//     }

//     for (int i = aux.size() - 1; i >= 0; i--) {
//         os << aux[i] << " ";
//         stack.push(aux[i]);
//     }

//     return os;
// }
#endif // __MY_STACK_H__