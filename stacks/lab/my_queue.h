#ifndef _MY_QUEUE_H__
#define _MY_QUEUE_H__

#include <assert.h>
#include <vector>

template <typename T, int N>
class Queue {

    private:
        int head;
        int tail;
        int num_elements;
        T queueArray[N];

    public:

        // Constructor
        Queue() {

            head = 0;
            tail = 0;
            num_elements = 0;
        }
        
        // Destructor
        ~Queue() {

        }

        void enqueue(T element) {

            if (num_elements == N) {
                return;
            }

            if (tail >= N) {
                tail = 0;
            }
            queueArray[tail] = element;
            tail++;
            num_elements++;
        }

        T dequeue() {

            if (num_elements != 0) {
                T aux = queueArray[head];
                head = (head + 1) % N;
                num_elements--;
                return aux;
            }
            return 0;
        }

        T front() {

            if (num_elements != 0) {
                return queueArray[head];
            }
            return 0;
        }

        bool isEmpty() {

            if (num_elements == 0) {
                return true;
            }
            return false;
        }

        int size() {
            return num_elements;
        }
        template <typename U, int M>
        friend std::ostream & operator<<(std::ostream &os, Queue <U, M> &queue); 

};
// template <typename T, int N>
// std::ostream & operator << (std::ostream &os, Queue <T, N> &queue) {
    
//     os << "Front to back: ";
//     std::vector <T> aux;

//     while (!queue.isEmpty()) {
//         aux.push_back(queue.dequeue());
//     }
//     for (int i = aux.size() - 1; i >= 0; i--) {
//         os << aux[i] << " ";
//         queue.enqueue(aux[i]);
//     }
//     return os;
// }


#endif // _MY_QUEUE_H__