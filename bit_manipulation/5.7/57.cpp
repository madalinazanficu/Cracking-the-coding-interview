#include <iostream>
// swap even bits with odd bits
//   ex: 01 00 11 00

//       01 00 11 00 &
//       01 01 01 01 
//       01 00 01 00 => even bits (par)
// shift even => 10 00 10 00

//       01 00 11 00 &
//       10 10 10 10
//       00 00 10 00 => odd bits (impar)
// shift odd =>  00 00 01 00

// result = even + odd => 10 00 11 00

int main() {
    int x;
    std::cin >> x;

    // 0xA (hexa) => 10 (decimal) => 1010 (binary)
    // 0xaaaaaaaa ( 8 * a => 8 * 4 = 32 bits) => 1010 1010 1010 1010 .... 1010 (binary)

    int odd_mask = 0xaaaaaaa;  // 1010 1010
    int even_mask = 0x55555555; // 0101 0101
    
    // extract the even bits
    int even = x & even_mask;

    // extract the odd bits;
    int odd = x & odd_mask;

    // shift them in order to swap; 
    even = even << 1;
    odd = odd >> 1;

    int result = even + odd;
    std::cout << result << '\n';
    return 0;
}