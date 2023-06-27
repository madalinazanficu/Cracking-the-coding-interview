/**
 * LabSD 4
 * Queue.h
 * Purpose: Skeleton code for the queue.
 *
 * @author Gabriel Bercaru
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <assert.h>
#include <vector>

template <typename T, int N>
class Queue {
private:
    int head;
    int tail;
    int numElements;
    T queueArray[N];

public:
    // Constructor
    Queue() {
        // TODO: initializations
        head = 0;
        tail = 0;
        numElements = 0;
    }

    // Destructor
    ~Queue() {
        // TODO: delete previously allocated stuff (if any)
    }

    /**
     * Add a new element in the queue.
     * 
     * @param element Value of the element to be added in the queue.
     */
    void enqueue(T element) {

        // TODO: TASK 2
        if (numElements == N) {
                return;
        }

        if (tail >= N) {
            tail = 0;
        }
        queueArray[tail] = element;
        tail++;
        numElements++;
    }

    /**
     * Removes and returns an element from the queue.
     *
     * @return Value of the elmement removed from the queue.
     */
    T dequeue() {

        if (numElements != 0) {
                T aux = queueArray[head];
                
                head++;
                if (head >= N) {
                    head = 0;
                }
                numElements--;
                return aux;
        }
        return 0;
        
    }

    /**
     * Returns an element from the queue, without removing it.
     *
     * @return Value of the first element stored in the queue (queue front).
     */
    T front() {

        if (numElements != 0) {
                return queueArray[head];
        }
        return 0;
    }

    /**
     * Checks if the queue contains any elements.
     *
     * @return True if the queue contains no elements, False otherwise.
     */
    bool isEmpty() {

        if (numElements == 0) {
            return true;
        }
        return false;
    }

    /**
     * Returns the number of elements currently stored in the queue.
     *
     * @return The number of elements stored in the queue.
     */
    int size() {
        return numElements;
    }

    template <typename U, int M>
    friend std::ostream& operator<<(std::ostream& os, Queue<U, M>& queue);
};

template <typename T, int N>
std::ostream& operator<<(std::ostream& os, Queue<T, N>& queue) {
    os << "Front to rear: ";
    std::vector<T> aux;
    while (!queue.isEmpty()) {
        aux.push_back(queue.dequeue());
    }
    for (unsigned int i = 0; i < aux.size(); i++) {
        os << aux[i] << " ";
        queue.enqueue(aux[i]);
    }

    return os;
}

#endif // __QUEUE_H__
