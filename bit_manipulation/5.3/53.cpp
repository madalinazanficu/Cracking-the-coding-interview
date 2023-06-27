#include <iostream>

// O(b) time, b = number of bits, O(1) space
int longestSequence(int x) {

    // in case the number is already full of 1
    if (~x == 0) {
        return sizeof(int) * 6;
    }

    int prevSeq = 0;
    int currSeq = 0;

    // we can always flip a bit from 0 to 1
    int maxSeq = 1; 

    while (x != 0) {

        // the current bit is 1
        if ((x & 1) == 1) {
            currSeq++;
        } else {

            // check the next bit behind him 
            if ((x & 2) == 0) {

                // two zeros after 1s sequence => this sequence can't be used
                currSeq = 0;
                prevSeq = 0;
            } else {

                // only one zero between the two 1s sequence
                prevSeq = currSeq;
                currSeq = 0; 
            }
        }
        if (currSeq + prevSeq + 1 > maxSeq) {
            maxSeq = currSeq + prevSeq + 1;
        }
        x = x >> 1;
    }
    return maxSeq;
}


int main() {

    int x;
    std::cin >> x;
    std::cout << longestSequence(x) << '\n';
    return 0;
}