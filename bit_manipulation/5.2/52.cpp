#include <iostream>
#include <string>

std::string printBinary(double a) {
    
    // the number should be something like => 0.87
    if (a >= 1 || a <= 0) {
        return "ERROR";
    }
    
    std::string binary;
    binary.append("0.");

    while (a > 0) {

        // setting a limit on length
        if (binary.length() >= 32) {
            return "ERROR";
        }
        // multiply by 2, in order to extract the bits after the comma
        double r = a * 2; 

        if (r >= 1) {
            binary.append("1");

            // to get to the next digit after the comma
            a = r - 1;
        } else {
            binary.append("0");
            a = r;
        }

    }
    return binary;

}

int main() {
    double a;
    std::cin >> a;
    std::string binary = printBinary(a);
    std::cout << binary << '\n';
    return 0;
}