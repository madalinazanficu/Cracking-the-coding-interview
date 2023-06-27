
#ifndef __STACK_H__
#define __STACK_H__

#include <assert.h>
#include <vector>


template <typename T, int N>
class Stack {
private:
    // Underlying array
    T stackArray[N];

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
        stackArray[topLevel] = element;
        topLevel++;
    }

    void pop() {
        if (topLevel)
            topLevel--;
    }
    void pop_bottom() {

        // left shift
        for (int i = 0; i < topLevel - 1; ++i) {
            stackArray[i] = stackArray[i + 1];
        }
        if (topLevel != 0)
            topLevel--;
         
    }
    T peek_bottom() {
        if (topLevel != 0) {
            return stackArray[0];
        }
        return 0;
    }


    T peek() {
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
    std::vector<T> aux;

    while (!stack.isEmpty()) {
        aux.push_back(stack.peek());
        stack.pop();
    }

    for (int i = aux.size() - 1; i >= 0; i--) {
        os << aux[i] << " ";
        stack.push(aux[i]);
    }

    return os;
}


template <typename T, int N>
class Set_of_Stacks {

    private:
        std::vector < Stack<T, N> *> set;
        int threshold = 4;
        
    public:
        // Constructor
        Set_of_Stacks() {
        }

        // Destructor
        ~Set_of_Stacks() {

            while(set.size()) {
                pop();
            }
            
        }
        Stack <T, N> * stack_at_index(int index) {
            return set.at(index);
        }

        void push(T element) {

            // no stacks in set
            if (set.size() == 0) {

                Stack <T, N> *first_st = new Stack <T, N>;
                set.push_back(first_st);
            }

            Stack<T, N> *last = set[set.size() - 1];

            // in case the last stack is full
            if ((*last).size() >= threshold) {

                Stack <T, N> *new_stack = new Stack <T, N>;
                set.push_back(new_stack);
            }

            // adding elements on the last stack from the set_of_stacks
            Stack<T, N> *very_last = set[set.size() - 1];
           (*very_last).push(element);
            
        }

        void pop() {

            if (set.size() == 0) {
                return;
            }
            Stack <T, N> *last = set[set.size() - 1];
            (*last).pop();

            // in case the last stack has only one element
            if ((*last).isEmpty()) {

                delete last;
                last = nullptr;
                set.pop_back();
            }
        }

        void remove_rec(int index, bool flag) {

            // pop de pe ultima stiva
            Stack <T, N> *st = set[index];
            if (index == set.size()) {
                (*st).pop();
                return;
            } else {

                T removed_item;
                T transfer_item;
        
                Stack <T, N> *st = set[index];
                Stack <T, N> *st2 = set[index + 1];

                removed_item = (*st).peek();
                transfer_item = (*st2).peek_bottom();

                (*st).pop();

                (*st).push(transfer_item);
                index++;

                while (index + 1 < set.size()) {

                    st = set[index];
                    st2 = set[index + 1];

                    (*st).pop_bottom();

                    removed_item = (*st).peek();
                    transfer_item = (*st2).peek_bottom();

                    
                    (*st).push(transfer_item);
                    index++;

                }
                st2 = set[index];
                (*st2).pop_bottom();
            }
            // 1 2 3 4
            // 5 6 7 8
            // 9 10 11 12
            // 13 14 15 16
            // index = 1;

            // 1 2 3 5
            // 5 6 7 8 
            // 10 11 12
            // 13 14 15 16
            // index = 2;
        }

        //  pop the element at the index and peek it
        void pop_at(int index) {
            remove_rec(index, 1);
        }

        // number of stacks from the set_of_stacks
        int size() {
            return set.size();
        }
};
// For pop at
// imagine 3 stacks
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15

// we request to pop index 1 => element 5
// this means that my stacks will look like:

// 1 2 3 4 6
// 7 8 9 10 11
// 12 13 14 15
// we need to shift the elements in order to keep the threshold stable
// the first element from the second stack become the last element from the first stack and so on


#endif // __STACK_H__
