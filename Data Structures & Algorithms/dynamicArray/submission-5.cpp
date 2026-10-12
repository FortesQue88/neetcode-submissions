class DynamicArray {
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        size = 0;
        arr = new int[capacity];
    }

    int get(int i) {
        return (arr[i]);
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }

        arr[size] = n;
        size++;
    }

    int popback() {
        size--;
        return arr[size];        
    }

    void resize() {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        for (int i = 0; i < size; i++) {
            newArr [i] = arr[i];
        }

        delete[]  arr;
        arr = newArr;
        capacity = newCapacity;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

private:
    int* arr;
    int size;
    int capacity;
};
