#include <queue>
#include <string>


struct animal {
    std::string name;
    int age;

    // constructor
    animal(std::string name, int age) {

        this->name = name;
        this->age = age;
    }
    

    // copy-constructor
    animal(const animal &other) {
        this->name = other.name;
        this->age = other.age;
    }
};


template <typename T, int NMAX>
class Animal_shelter {

    private:
        std::queue <T> dogs;
        std::queue <T> cats;
        int time = 0;


    public:

        void enqueue(std::string type, std::string name) {

            animal new_animal = animal(name, time);
            time++;
            
            if (type == "cat") {
                cats.push(new_animal);
            } else {
                dogs.push(new_animal);
            }

        }

        std::string dequeueCat() {

            if (cats.size() == 0) {
                std::cout << "No more cats!\n";
                return "No more cats!\n";
            }

            animal oldest_cat = cats.front();
            cats.pop();
            
            std::cout << oldest_cat.age <<std:: endl;
            return oldest_cat.name;
        }

        std::string dequeueDog() {

            if (dogs.size() == 0) {
                std::cout << "No more dogs!\n";
                return "No more dogs!\n";
            }

            animal oldest_dog = dogs.front();
            dogs.pop();
            std::cout << oldest_dog.age <<std:: endl;

            return oldest_dog.name;
        }

        std::string dequeueAny() {
            
            if (dogs.size() == 0 && cats.size() == 0) {
                return "No more dogs or cats!\n";
            }
            if (dogs.size() == 0 && cats.size() != 0) {

                std::cout << "There were only cats\n";
                animal oldest_cat = cats.front();
                cats.pop();
                return oldest_cat.name;
            }
            if (cats.size() == 0 && dogs.size() != 0) {

                std::cout << "There were only dogs";
                animal oldest_dog = dogs.front();
                dogs.pop();
                return oldest_dog.name;
            }
            
            animal oldest_dog = dogs.front();
            animal oldest_cat = cats.front();


            if (oldest_dog.age < oldest_cat.age) {
                dogs.pop();
                std::cout << oldest_dog.age <<std:: endl;
                return oldest_dog.name;
            } else {
                cats.pop();
                std::cout << oldest_cat.age <<std:: endl;
                return oldest_cat.name;
            }
        }


};