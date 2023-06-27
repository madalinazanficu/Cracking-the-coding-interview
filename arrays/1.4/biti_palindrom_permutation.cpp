#include <iostream>
#include <string>


// folosim un int care ocupa 4 * 8 = 32 de biti pentru a reprezenta caracterele

void set_bits(int &bitVector, int ch_to_int)
{
    // set the bit from the ch_to_int pos to 1

    // mask = 0010 => that bit become on
    int mask = 1 << ch_to_int;
    
    // if the bit from that position is 0 => set it to 1

    if ((bitVector & mask) == 0) {
        bitVector = bitVector | mask;
    } else {

        // if the bit from that position is 1 => set it to 0
        // ~mask = 1101 => the position became off
        bitVector = bitVector & (~mask); 
    }
}

int create_bit_vector(std::string str)
{
    int bitVector = 0;
    // parsing my string to get every chacater
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];

        if (isupper(ch)) {
            ch = tolower(ch);
        }
        if (ch >= 'a' && ch <= 'z') {
        
            // ch_to it is 0 -> a, 1 -> b... represent the bit position in the bitVector
            int ch_to_int = ch - 'a';
            set_bits(bitVector, ch_to_int);
        }
    }
    return bitVector;
}


int main() {
    std::string str;
    std::getline(std::cin, str);
    int bitVector = create_bit_vector(str);
    // 00010000 - // bit vector 
    // 00000001 =>
    // 00001111

    // 00010000 &
    // 00001111
    // 00000000 => a aparut doar o data

    // Daca aveam: 00010010 - // bitvector
    //             00000001
    //             00010001

    // 00010001 &
    // 00010010
    // 00010000 => mai multe aparintii 
    // std::cout<< bitVector;

    if (bitVector == 0) {
        std::cout<< "1" <<std::endl;
    } else {
        if ((bitVector & (bitVector - 1)) == 0) {
            std::cout<< "1" <<std::endl;
        } else {
            std::cout<< "0" <<std::endl;
        }
    }

    return 0;
}