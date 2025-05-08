#ifndef VECTOR_H
#define VECTOR_H

#include <bits/stdc++.h>
using namespace std;
template <typename T>
class Vector
{
private:
    int size;
    int capacity;
    T *vector;
    void resize(int new_capacity)
    {
        capacity = new_capacity;
        T *new_vector = new T[capacity];
        for (int i = 0; i < size; i++)
            new_vector[i] = vector[i];
        delete[] vector;
        vector = new_vector;
    }
    void swap(T &a, T &b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

public:
    Vector() : size(0), capacity(1)
    {
        vector = new T[capacity]{};
    }
    Vector(int size) : size(size), capacity(size + 10)
    {
        vector = new T[capacity]{};
    }
    Vector(T value, int size) : size(size), capacity(size + 10)
    {
        vector = new T[capacity]{};

        for (int i = 0; i < capacity; i++)
            vector[i] = value;
    }
    ~Vector()
    {
        delete[] vector;
        vector = nullptr;
    }
    Vector(const Vector<T> &object) // Copy constructor
    {
        size = object.size;
        capacity = object.capacity;
        vector = new T[capacity]{};
        for (int i = 0; i < size; i++)
        {
            vector[i] = object.vector[i];
        }
    }
    Vector<T> &operator=(const Vector<T> &object) // Assignment Opertator
    {
        if (this != &object)
        {
            delete[] vector;
            size = object.size;
            capacity = object.capacity;
            vector = new T[capacity];
            for (int i = 0; i < size; ++i)
            {
                vector[i] = object.vector[i];
            }
        }
        return *this;
    }
    bool operator==(const Vector &object) const
    {
        if (size != object.size)
            return false;

        for (int i = 0; i < size; ++i)
        {
            if (vector[i] != object.vector[i])
                return false;
        }
        return true;
    }
    bool operator!=(const Vector &object) const
    {
        return !(*this == object);
    }
    T &operator[](int idx)
    {
        if (idx < 0 || idx >= size)
            throw out_of_range("Index out of range");

        return vector[idx];
    }
    const T &operator[](int idx) const
    {
        if (idx < 0 || idx >= size)
            throw out_of_range("Index out of range");

        return vector[idx];
    }
    void insert(int index, T value)
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range.");

        if (size == capacity)
            resize(capacity * 2);
        for (int i = size; i > index; i--)
            vector[i] = vector[i - 1];

        vector[index] = value;
        ++size;
    }
    void PushBack(T value)
    {
        if (size == capacity)
            resize(capacity * 2);

        vector[size++] = value;
    }
    void PushFront(T value)
    {
        if (size == capacity)
            resize(capacity * 2);

        for (int i = size; i > 0; --i)
            vector[i] = vector[i - 1];

        vector[0] = value;
        ++size;
    }
    T PopBack()
    {
        if (size == 0)
            throw out_of_range("Vector is empty.");

        return vector[size--];
    }
    void delete_at(int index)
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range.");

        for (int i = index; i < size - 1; i++)
            vector[i] = vector[i + 1];
        --size;
    }
    T Front_element() const
    {
        if (size == 0)
            throw out_of_range("Vector is empty.");

        return vector[0];
    }
    T Back_element() const
    {
        if (size == 0)
            throw out_of_range("Vector is empty.");

        return vector[size - 1];
    }
    T &getElement(int index) const
    {
        if (index < 0 || index >= size)
            throw out_of_range("Index out of range.");

        return vector[index];
    }
    int getSize() const
    {
        return size;
    }
    int getCapacity() const
    {
        return capacity;
    }
    void reverse(int start = 0, int end = 0)
    {
        if (size == 0)
            throw runtime_error("Vector is empty.\n");
        if (end == 0)
            end = size - 1;
        for (int i = start, j = end; i < j; ++i, --j)
            swap(vector[i], vector[j]);
    }
    T find(T value)
    {
        for (int i = 0; i < size; ++i)
            if (vector[i] == value)
                return i;
        return -1;
    }
    bool isempty()
    {
        return size == 0;
    }
    void sort()
    {
        if (size == 0)
            throw runtime_error("Vector is empty.\n");

        for (int i = 0; i < (size - 1); ++i)
        {
            for (int j = 0; j < (size - i - 1); ++j)
            {
                if (vector[j] > vector[j + 1])
                    swap(vector[j], vector[j + 1]);
            }
        }
    }
    void display() const
    {
        for (int i = 0; i < size; ++i)
            cout << vector[i] << ' ';
        cout << '\n';
    }
    void clear()
    {
        delete[] vector;
        size = 0, capacity = 1;
        vector = new T[1];
    }
};
#endif