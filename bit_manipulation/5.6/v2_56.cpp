#include <iostream>

int main() {

    int n, m;
    int cnt = 0;
    std::cin >> n >> m;

    // the xor operator makes 1 when the bits are different
    int x = n ^ m;

    // x = x & (x - 1) remove bits of 1 from the end, until the x become 0
    for (x = n ^ m; x != 0; x = x & (x - 1)) {
        cnt++;
    }
    std::cout << cnt << '\n';
    return 0;
}