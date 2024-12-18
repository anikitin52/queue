#pragma once
#include <iostream>


template<class T>
class Queue {
private:
    T* buffer;
    int capacity;
    int start;
    int end;

    // Увеличение размера массива
    void resize(int newCapacity) {
        T* newBuffer = new T[newCapacity];
        for (int i = 0; i < size(); ++i) {
            newBuffer[i] = buffer[(start + i) % capacity];
        }
        delete[] buffer;
        buffer = newBuffer;
        start = 0;
        end = size();
        capacity = newCapacity;
    }

public:
    explicit Queue(int initialCapacity = 16) : capacity(initialCapacity + 1), start(0), end(0) {
        buffer = new T[this->capacity];
    }

    ~Queue() {
        delete[] buffer;
    }

    Queue(const Queue& other) : capacity(other.capacity), start(other.start), end(other.end) {
        buffer = new T[other.capacity];
        for (int i = 0; i < other.size(); ++i) {
            buffer[(start + i) % capacity] = other.buffer[(other.start + i) % other.capacity];
        }
    }

    Queue& operator=(const Queue& other) {
        if (this != &other) {
            delete[] buffer;
            capacity = other.capacity;
            start = other.start;
            end = other.end;
            buffer = new T[other.capacity];
            for (int i = 0; i < other.size(); ++i) {
                buffer[(start + i) % capacity] = other.buffer[(other.start + i) % other.capacity];
            }
        }
        return *this;
    }

    bool push(T value) {
        if (isFull()) {
            resize(capacity * 2);  // Увеличиваем размер массива вдвое
        }

        buffer[end] = value;
        end = (end + 1) % capacity;
        return true;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Очередь пуста!");
        }

        T value = buffer[start];
        start = (start + 1) % capacity;
        return value;
    }

    bool isEmpty() const {
        return start == end;
    }

    bool isFull() const {
        return (end + 1) % capacity == start;
    }

    int size() const {
        return (end - start + capacity) % capacity;
    }

    void clear() {
        start = 0;
        end = 0;
    }
};