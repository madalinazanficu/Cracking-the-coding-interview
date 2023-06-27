#include <iostream>
#include "/home/madalina/cracking/stacks/lab/Stack.h"
// Two stacks


int main() {
    Stack <int, 10> st;
    Stack <int, 10> min_st;

    int minn = 99999;
    int n, x, y;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> x;
        st.push(x);
        if (x <= minn) {
            minn = x;
            min_st.push(minn);
        }
    }
    std::cout << min_st.peek() << std::endl;

    // for testing
    x = st.peek();
    y = min_st.peek();
    st.pop();
    if (x == y) {
        min_st.pop();
    }

    std::cout << min_st.peek() << std::endl;
    return 0;
}

