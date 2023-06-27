#include <iostream>
#include <vector>
// implement a function that draws a horizontal line from (x1, y) to (x2, y)

void drawLine(char screen[], int width, int x1, int x2, int y) {

    // how many bits we left on 0 in the byte of x1
    int start_offSet = x1 % 8;
    int first_full_byte = x1 / 8;

    // in case x1 is the first bit of the byte => that byte will be full of 1
    // otherwise, we need to go to the next byte, that one will be full of 1

    if (start_offSet != 0) {
        first_full_byte++;
    }

    // how many bits we flip on 1, in the byte of x2
    int end_offSet = x2 % 8;
    int last_full_byte = x2 / 8;

    // in case x2, is the last bit of the byte, last_full_byte will remain the byte of x2
    // otherwise, we need to go back to the previous byte

    if (end_offSet != 7) {
        last_full_byte--;
    }

    for (int byte = first_full_byte; byte <= last_full_byte; ++byte) {
       screen[(width / 8) * y + byte] = 0xFF;
    }

    int maskStart = (0xFF >> start_offSet);
    int maskEnd = ~(0xFF >> (end_offSet + 1));

    // the bits are in the same byte
    if (x1 / 8 == x2 / 8) {

        int mask = maskStart & maskEnd;
        int byte_number = (width / 8) * y + x1 / 8;
        screen[byte_number] = screen[byte_number] | mask;

    } else {

        if (start_offSet != 0) {

            int byte_number = (width / 8) * y + first_full_byte - 1;
            screen[byte_number] = screen[byte_number] | maskStart;
        }

        if (end_offSet != 7) {

            int byte_number = (width / 8) * y + last_full_byte + 1;
            screen[byte_number] = screen[byte_number] | maskEnd;
        }
    }

}

int main() {

    int width, y;
    std::cin >> width >> y;
    char screen[width * y] = {0};

    int x1, x2;
    std::cin >> x1 >> x2;

    drawLine(screen, width, x1, x2, y);
    for (int i = 0; i < width * y; i++) {
        for (int j = 0; j < 8; j++)
            if (((screen[i] >> (7 - j)) & 1) == 0)
                std::cout << "0 ";
            else
                std::cout << "1 ";
        std::cout << "   ";
        if ((i + 1) % width == 0 && i != 0)
            std::cout << '\n';
    }

    return 0;
}