#include <iostream>
#include <vector>
#include <string>

std::vector <std::string> merge (std::vector <std::string> words, std::vector <std::string> more) {
    std::vector<std::string> sentence(0);
    for (auto word : words) {
        sentence.push_back(word);
    }
    for (auto word : more) {
        sentence.push_back(word);
    }
    return sentence;
}

int main() {
    int length1, length2;
    std::cin >> length1 >> length2;
    
    std::vector <std::string> words(length1);
    std::vector <std::string> more(length2);

    for (int i = 0; i < length1; ++i) {
        std::cin>> words.at(i);
    }

     for (int i = 0; i < length2; ++i) {
        std::cin>> more.at(i);
    }
    
    std::vector <std::string> sentence = merge(words, more);
    std::cout << sentence.size() << std::endl;
    for (int i = 0; i < sentence.size(); ++i) {
        std::cout<< sentence.at(i)<< " ";
    }
    std::cout<<std::endl;
}