#include <iostream>
#include <string>


// str waterbottle
// str1   erbottlewat
// str1 + str1 => erbottle/waterbottle/wat
bool is_rotating(std::string str, std::string str1) {

    if (str.length() != str1.length()) {
        return false;
    }
    std::string s1s1 = str1 + str1;
    // using find => find the substring str in the s1s1 
    if (s1s1.find(str)) {
        return true;
    }
    return false;
}

int main() {
    std::string str;
    std::string str1;

    std::cin >> str >> str1;
    std::cout << is_rotating(str, str1) <<std::endl;

    return 0;
}