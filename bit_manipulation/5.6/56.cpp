#include <iostream>

int main() {

    int n, m;
    int cnt = 0;
    std::cin >> n >> m;

    // the xor operator makes 1 when the bits are different
    int x = n ^ m;

    // x & 1 => will be 1 or 0 depend on the x least semnificativ bit
    while (x != 0) {
        cnt = cnt + (x & 1);

        // shift it , in order to compare bit to bit
        x = x >> 1;
    }
    std::cout << cnt << '\n';
    return 0;
}