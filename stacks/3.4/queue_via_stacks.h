#include <stack>
#include <vector>
// better than O(n) for remove operation
// implemented a queue using 2 stacks

template <typename T>
class My_Queue {

    private:
    std::stack <T> st_add, st_remove;

    public:

    // Constructor
    My_Queue() {

    }

    // Destructor
    ~My_Queue() {
        while(size() > 0) {
            pop();
        }

    }

    // push - in the st_add
    void push(T element) {
        st_add.push(element);
    }


    // moving elements from the st_add to st_remove when st_remove remain empty
    // to make the pop operation directly on st_remove
    void move() {

        if (st_remove.size() == 0) {

            while(!st_add.empty()) {
                T to_move = st_add.top();
                st_add.pop();
                st_remove.push(to_move);
            }
        }
    }

    // pop - from the st_remove
    void pop() {

        move();
        st_remove.pop();
    }

    T peek() {

        move();
        return st_remove.top();
    
    }
    int size() {

        return st_add.size() + st_remove.size();
    }

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, My_Queue<U>& queue);

};

template <typename T>
std::ostream &operator<<(std::ostream &os, My_Queue <T> &queue) {

    queue.move();
    std::cout << "Bottom to top\n";

    std::vector <int> vect;
    while(queue.size() != 0) {
        vect.push_back(queue.peek());
        queue.pop();
    }

    for (int i = vect.size() - 1; i >= 0; i--) {
        os << vect[i] << " ";
        queue.push(vect[i]);
    }
    os << "\n";
    return os;
}