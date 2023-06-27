#pragma once

template <typename T>
struct Node {

    T data;
    Node <T> *next;

    // Constructor
    Node(T data) {
        this->data = data;
        this->next = nullptr;
    }

};

template <typename T>
class LinkedList {

    private:
        Node <T> *head;
        int num_elements;
    
    public:

    // Constructor 1
    LinkedList() {

        this->head = NULL;
        num_elements = 0;
    }

    // Constructor 2
    LinkedList(Node <T> *head) {

        this->head = head;
        num_elements = 0;

        while(head != nullptr) {
            num_elements++;
            head = head->next;
        }
        
    }
    // Destructor
    ~LinkedList() {

        Node <T> *fast, *slow;
        slow = this->head;

        if (num_elements != 0) {
            fast = this->head->next;

            while(fast != nullptr) {
                delete slow;
                slow = fast;
                fast = fast->next;
            }
            delete slow;
            num_elements = 0;
            this->head = nullptr;
        }
    }
    // Add nth pos
    void add_nth_node(int poz, T data) {

        if (poz < 0) {
            return;
        }
        if (poz > num_elements) {
            poz = num_elements;
        }
        // adaug pe prima pozitie
        if (poz == 0) {

            Node <T> *new_node = new Node <T> (data);
            new_node->next = this->head;
            this->head = new_node;

        } else {

            Node <T> *new_node = new Node <T> (data);
            Node <T> *curr = this->head;

            int cnt = 0;

            while(cnt != poz - 1) {
                cnt++;
                curr = curr->next;
            }

            new_node->next = curr->next;
            curr->next = new_node;
        }
        num_elements++;
    }
    // Rmw nth pos
    void rmw_nth_node(int poz) {

        if (poz < 0) {
            return;
        }
        if (poz >= num_elements - 1) {
            poz = num_elements - 1;
        }
        if (poz == 0) {

            Node <T> *rmw = this->head;
            this->head = rmw->next;
            delete rmw;
            
        } else {

            Node <T> *rmw;
            Node <T> *curr = this->head;

            int cnt = 0;
            // - 1 merg inaintea elem pe care vreau sa il sterg
            while(cnt != poz - 1) {
                cnt++;
                curr = curr->next;
            }

            rmw = curr->next;
            curr->next = rmw->next;
            delete rmw;
            
        }
        num_elements--;
    }
    // Check if there are elements
        bool is_empty() {
            if (this->num_elements == 0)
                return true;
            else
                return false;
        }

        // Get the size
        int size() {
            return this->num_elements;
        }

        // Getters
        Node<T> *getHead() {
            return this->head;
        }

        Node<T> *getTail() {
            if (this->num_elements <= 1)
                return this->head;
            Node<T> *curr = this->head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            return curr;
        }

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, LinkedList<U>& list);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, LinkedList<T>& list) {
    Node<T> *it = list.getHead();

    if (list.size() > 0) {
        os << "[ ";
        while (it->next != nullptr) {
            os << it->data << " -> ";
            it = it->next;
        }

        os << it->data;
        os << " ]";
    } else {
        os << "[]";
    }

    return os;
}




