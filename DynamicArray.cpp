#include <iostream>
#include <string>
using namespace std;

const int INITIAL_CAPACITY = 2;
const int GROWTH_FACTOR = 2;

template <class T>
class dynamicArray
{
    T *array;
    int capacity = INITIAL_CAPACITY;
    int _size;

public:
    dynamicArray()
    {
        array = new T[capacity];
        _size = 0;
    }

    ~dynamicArray()
    {
        delete[] array;
    }

    void deleteAt(int pos)
    {
        assert(0 <= pos && pos < _size);
        _size--;
        for (int i = pos; i < _size; i++)
        {
            array[i] = array[i + 1];
        }
    }

    void insertAt(int element, int pos)
    {
        assert(0 <= pos && pos < _size);
        if (_size == capacity)
        {
            resize();
        }
        for (int i = _size; i > pos; i--)
        {
            array[i] = array[i - 1];
        }
        _size++;
        array[pos] = element;
    }

    void append(T element)
    {
        insertAt(element, _size);
    }

    int size()
    {
        return _size;
    }

    void resize()
    {
        capacity *= GROWTH_FACTOR;
        T *temp = new T[capacity];
        copy(array, array + _size, temp);
        delete[] array;
        array = temp;
    }

    T get(int pos)
    {
        return array[pos];
    }

    void pretty_print()
    {
        cout << "[";
        for (int i = 0; i < _size - 1; i++)
        {
            cout << array[i] << " ";
        }
        if (_size)
        {
            cout << array[_size - 1];
        }
        cout << "]\n";
    }
};
