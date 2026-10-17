class ListNode {
public:
    ListNode(int value, ListNode* next = nullptr)
        : value(value), next(next) {}

    int value;
    ListNode* next;
};

class LinkedList {
public:
    LinkedList() {
    }

    int get(int index) {
        if (index < 0) {
            return -1;
        }

        ListNode* current = head;

        for (int i = 0; current != nullptr; i++) {
            if (i == index) {
                return current->value;
            }

            current = current->next;
        }

        return -1;
    }

    void insertHead(int val) {
        head = new ListNode(val, head);

        if (size == 0) {
            tail = head;
        }

        size++;
    }
    
    void insertTail(int val) {
        ListNode* newNode = new ListNode(val, nullptr);
        if (size == 0) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    bool remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }

        ListNode* current = head;
        ListNode* previos = nullptr;

        for (int i = 0; current != nullptr; i++) {
            if (i == index) {
                if (previos == nullptr) {
                    head = current->next;
                } else {
                    previos->next = current->next;
                }

                if (current == tail) {
                    tail = previos;
                }

                delete current;
                size--;
                
                return true;
            }
            previos = current;

            current = current->next;
        }

        return false;
    }

    vector<int> getValues() {
        vector<int> arr;
        ListNode* current = head;

        for (int i = 0; current != nullptr; i++) {
            arr.push_back(current->value);
            current = current->next;
        }

        return arr;
    }

private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int size = 0;
};