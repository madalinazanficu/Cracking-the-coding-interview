#include <iostream>
#include "stack_min.h"


int main() {
    Stack <int, 5> st;
    int element = 2;
    st.push(element);
    element--;
    st.push(element);
    element = 3;
    st.push(element);
    std::cout << st;
    return 0;
}