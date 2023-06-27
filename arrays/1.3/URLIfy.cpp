#include <iostream>
#include <string>

void replace_string(std::string & str, int truelength)
{
    int spaces = 0;
    // Numar spatiile
    for (int i = 0; i < truelength; i++)
        if(str[i] == ' ')
            spaces++;

    //calculez valoarea finala
    int index = truelength + spaces * 2;

    //rescriu sirul de la coada spre cap, inlocuind spatiile
    for (int i = truelength + spaces * 2 - 1; i >= 0; i--) {
        if (str[truelength - 1] == ' ') {
            str[index] = '0';
            str[index - 1] = '2';
            str[index - 2] = '%';
            index = index - 3;
        } else {
            str[index] = str[truelength - 1];
            index--;
        }
        truelength--;
    }
}

int main(){
    
    std::string my_string = "Mama are multe mere       ";
    int true_len = 19;
    replace_string(my_string, true_len);
    std::cout << my_string;
    return 0;
}