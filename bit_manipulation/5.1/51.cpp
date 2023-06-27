#include <iostream>

// for example i = 2 j = 6
// m = 1111
// first I clear the bits in n, between i, j
// I need my mask to be => 11 0000 11
// mask & n => the clear operation)
//  for example : 11010101 &
//                11000011 
//                11000001
int updateBits(int n, int m, int i, int j) {

    // sequence full of 1 bits => equivalent with -1
    int allOnes = ~0;

    // the first mask => 11111111 shifted left with j + 1 will cause
    // => 11000000, I have zeros until j(inclusive)
    int left = (allOnes << (j + 1));

    // the second mask => 00000100 - 1 => 00000011
    int right = (1 << i) - 1;

    // merge the masks => '|' => '+'
    // 11000000 |
    // 00000011
    // 11000011 => the final mask
    int mask = left | right;

    // the and operator => '*' on bits will clear my number
    int n_cleared = n & mask;
    int m_shifted = m << i;

    // n cleared => 11000001
    // m shifted => 00111100
    //              11111101
    return n_cleared | m_shifted;
}



int main() {

    int n, m, i, j;
    std::cin >> n >> m >> i >> j;
    std::cout << updateBits(n, m, i, j) << '\n';
    return 0;
}