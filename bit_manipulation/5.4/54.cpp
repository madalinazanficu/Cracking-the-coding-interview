#include <iostream>
// find the next smaller number with the same number of 1 bits as x
// example : 13938 => 13967
// binary :  11 0 11 00 11111 00
// 01001101 - another case, with no triling 0s

int getNext(int x) {
    
    // find the sequence 01, in order to swap the bits
    int c0 = 0;
    int c1 = 0;
    int n = x;

    // trailing 0s (at the end)
    // this maintain that we haven't found 01 bits seq yet
    while(((n & 1) == 0) && (n != 0)) {
        c0++;
        n = n >> 1;
    }

    // once we are done with 0, we count 1s
    while((n & 1) == 1) {
        c1++;
        n = n >> 1;
    }

    // edge case : 111111 000000 => equal number of 0s and 1s, and exceeds the sizeof(int) * 6 bits
    //  && 0
    if (c1 + c0 == 31 || c1 + c0 == 0) {
        return -1;
    }

    // position on the rightmost non-trailing (nu din coada) zero
    int p = c0 + c1;

    // before p, we need to rearrenge the 1s bits and 0s bits
    // 1 Step => flip the rightmost non-trailing 0 => 11 0 11 01 11111 00
    x = (x | (1 << p));

    // 2 Step => clear the bits before p 

    // ex:  00 0 00 01 00000 00
    int mask = (1 << p);

    // ex: 00 0 00 00 11111 11
    mask = mask - 1;

    // ex: 11 1 11 11 00000 00
    mask = ~mask;

    //  x: 11 0 11 0'1' 00000 00
    x = x & mask;

    // insert c1 - 1 ones, in the right

    // ex: 00 0 00 00 00100 00
    int insert = (1 << (c1 - 1));

    // ex: 00 0 00 00 00011 11
    insert = insert - 1;

    // : 11 0 11 0'1' 00011 11
    x = x | insert;

    return x;
}

// find the previous bigger number with the same number of 1 bits as x
int getPrev(int x) {

    // thinking about the first seq 10, to swap the bits
    int c0 = 0;
    int c1 = 0;
    int n = x;

    // trailing 1s (at the end)
        while((n & 1) == 1) {
        c1++;
        n = n >> 1;
    }

    // once we are done with 0, we count 1s
    while(((n & 1) == 0) && (n != 0)) {
        c0++;
        n = n >> 1;
    }

    // position on the rightmost non-trailing (nu din coada) 1
    int p = c0 + c1;
    
    // x: 100 111'1' 00000 11

    // Step 1: Clear the bits behind p (inclusive) => flip it to 0
    
    // mask : 000 0010 00000 00 => 000 0001 11111 11 => 111 1110 00000 00
    int mask = ~((1 << (p + 1)) - 1);

    // x cleared : 100 111'1' 00000 11 & 111 1110 00000 00 => 100 111'0' 00000 00
    x = x & mask;

    // Step 2: Put 1s in the left and 0s in the right
    int insert = ((1 << (c1 + 1)) - 1);

    // shift them until I am right behind p
    insert = (insert << (c0 - 1));

    x = x | insert;

    return x;
}



int main() {

    int x;
    std::cin >> x;
    std:: cout << "bigger: " << getNext(x) << '\n' << "smaller: " << getPrev(x) << '\n';


    return 0;
}