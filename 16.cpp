#include <iostream>
#include <string>


bool check_lenghts(std::string str)
{
    int ch_cons = 0;
    int len = 0, cnt = 0;
    // trebuie sa numaram cate caractere consecutive avem
    for (int i = 0; i < str.length(); i++) {
        ch_cons++;
        
        // daca ajungem la final sau daca caracterele nu sunt identice
        if (i == str.length() - 1 || str[i] != str[i + 1]) {
            cnt = 0;
            while(ch_cons != 0) {
                cnt++;
                ch_cons = ch_cons / 10;
            }
            // 1 - lungimea caracterului + cnt - lungimea stringului format de nr de caractere identice
            len = len + 1 + cnt;
        }
    }
    if (str.length() < len) {
        return true;
    }
    return false;
}



int main() {
    std::string str;
    std::string new_str;
    std::cin >> str;
    if (check_lenghts(str)) {
        std::cout << "Lungimea sirului ar deveni mai mare dupa compersie \n";
        std::cout << str << std::endl;
        return 0;
    }

    // Creearea stringului
    int ch_cons = 0;
    for (int i = 0; i < str.length(); i++) {
        ch_cons++;
        
        if (i == str.length() - 1 || str[i] != str[i + 1]) {

            // formez sirul => push_back merge doar pr caractere
            new_str.push_back(str[i]);

            // to string => from int to string
            std::string number;
            number = std::to_string(ch_cons);

            // append merge doar pentru stringuri
            new_str.append(number);
            ch_cons = 0;
        }
    }

    std::cout << "Sirul dupa compresie \n";
    std::cout << new_str << std::endl;

    return 0;
}