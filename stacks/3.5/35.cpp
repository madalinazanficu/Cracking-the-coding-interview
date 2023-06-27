#include <iostream>
#include "/home/madalina/cracking/stacks/lab/Stack.h"
#define NMAX 101
// O(n ^ 2) time complexity
// O (n) additional space

int main() {

    int n = 5, x;

    Stack <int, NMAX> st;
    Stack <int, NMAX> sorted;

    for (int i = 0; i < n; i++) {
        std::cin >> x;
        st.push(x);
    }

    // take top element from the st and place it in increase order on the sorted stack
    while(!st.isEmpty()) {

        int save = st.peek();
        st.pop();
        while (!sorted.isEmpty() && sorted.peek() > save) {

            // move elements from the second stack in the first
            st.push(sorted.peek());
            sorted.pop();
        }
        sorted.push(save);
    }
    std::cout << sorted << std::endl;
    return 0;
}