#include <initializer_list>
#include <stdexcept>
#include <type_traits>
#include <iostream>

template<typename T>
class Vector {
    static_assert(std::is_move_constructible<T>::value, "T must be MoveConstructible");
    static_assert(std::is_move_assignable<T>::value, "T must be MoveAssignable");
public:
    Vector () : Vector<T>(0) {}
    explicit Vector (const std::size_t);
    Vector (const std::size_t, const T&);
    Vector (const Vector<T> &);
    Vector (Vector<T> &&);
    Vector (const std::initializer_list<T>);
    ~Vector<T> ();
    Vector<T> & operator= (const Vector<T> &);
    Vector<T> & operator= (Vector<T> &&);
    const T operator[] (const std::size_t) const;
    T & operator[] (const std::size_t);
    void push_back (const T&);
    void insert (const std::size_t, const T&);
    void erase (const std::size_t);
    void clear ();
    std::size_t size() const;
    std::size_t capacity() const;
    T * begin();
    T const * begin() const;
    T * end();
    T const * end() const;
    T * find(T);
    T const * find(T) const;
    void reset();
private:
    void swap(Vector<T> &, Vector<T> &);
    void double_space();
    std::size_t _size;
    std::size_t _total_length;
    T * _data;
};

/**
 * Main constructor.
 */
template<typename T> Vector<T>::Vector (const std::size_t size) {
    _size = size;
    _data = new T[size];
    _total_length = size;
    reset();
}


/**
 * Main constructor if default values are given.
 */
template<typename T> Vector<T>::Vector (const std::size_t size, const T& def_val) {
    _size = size;
    _data = new T[size];
    _total_length = size;
    for (int i = 0; i < _size; ++i) {
        _data[i] = def_val;
    }
}



/**
 * Copy constructor.
 */
template<typename T> Vector<T>::Vector (Vector<T> const& src) {
    _size = src._size;
    _total_length = _size;
    _data = new T[_size];
    for (std::size_t i = 0; i < _size; ++i) {
        _data[i] = src._data[i];
    }
}

/**
 * Move constructor.
 */
template<typename T> Vector<T>::Vector (Vector<T> && src) {
    _size = src._size;
    _data = new T[_size];
    _total_length = _size;
    swap(*this, src);

    delete [] src._data;
    src._size = 0;
    src._total_length = 0;
    src._data = nullptr;
}

/**
 * Constructor for initializing with list.
 */
template<typename T> Vector<T>::Vector (std::initializer_list<T> list) {
    _size = list.size();
    _total_length = _size;
    _data = new T[_size];
    int j = 0;
    for (T l : list) {
        _data[j] = l;
        ++j;
    }
}

/**
 * Destructor.
 */
template<typename T> Vector<T>::~Vector<T> () {
    delete [] _data;
}

/**
 * Assignment function, called when copying.
 */
template<typename T> Vector<T> & Vector<T>::operator= (Vector<T> const& src) {
    if (&src == this)
        return *this;

    _size = src._size;
    _total_length = src._size;
    delete [] _data; // Delete existing data
    _data = new T[_size]; // Allocate new space

    for (std::size_t i = 0; i < _size; ++i) {
        _data[i] = src._data[i];
    }
    return *this;
}

/**
 * Assignment function, called when moving (copying and then deleting). 
 */
template<typename T> Vector<T> & Vector<T>::operator= (Vector<T> && src) {
    if (&src == this)
        return *this;
    
    _total_length = src._total_length;
    _size = src._size;
    swap(*this, src);

    src._size = 0;
    src._total_length = 0;
    delete [] src._data;
    src._data = nullptr;

    return *this;
}

/**
 * When [] operator is attached to expression this method will be called, if only read.
 * Returns the value of the actual position, or throws exception if something is wrong.
 */
template<typename T> const T Vector<T>::operator[] (std::size_t i) const {
    if (i >= _size)
        throw std::out_of_range("Index not in list");
    return _data[i];
}

/**
 * When [] operator is attached to expression this method will be called, if write.
 * Returns the reference of the actual position, or throws exception if something is wrong.
 */
template<typename T>
T & Vector<T>::operator[] (const std::size_t i) {
    if (i >= _size)
        throw std::out_of_range("Index not in list");
    return _data[i];
}

/**
 * Adds element last in list
 */
template <typename T>
void Vector<T>::push_back (const T& elem) {
    if (_total_length == _size) {
        double_space();
    }
    _data[_size] = elem;
    ++_size;
}

/**
 * Adds element to given place in list.
 */
template <typename T>
void Vector<T>::insert (std::size_t index, const T& elem) {
    if (index == _size) {
        push_back(elem);
        return;
    }
    if (index > _size)
        throw std::out_of_range("Index not in list");

    if (_size == _total_length)
        double_space();
    // Start from end and move every element one step
    for (int i = _size; i > index; --i) {
        _data[i] = _data[i-1];
    }
    _data[index] = elem;
    ++_size;
}

/**
 * Removes element from list.
 */
template <typename T>
void Vector<T>::erase (std::size_t index) {
    if (index >= _size)
        throw std::out_of_range("Index not in list");

    // Start from index and move every element after to the place before
    for (int i = index; i < _size - 1; ++i) {
        _data[i] = _data[i+1];
    }

    --_size;
}


/**
 * Removes element from list.
 */
template <typename T> void Vector<T>::clear () {
    _size = 0;
}

/**
* Returns a RandomAccessIterator to the first element
* of the range.
*/
template <typename T> T * Vector<T>::begin() {
    return &_data[0];
}


/**
* Returns a RandomAccessIterator to the first element
* of the range.
*/
template <typename T> T const * Vector<T>::begin() const {
    return &_data[0];
}

/**
* Returns a RandomAccessIterator to the first element
* of the range.
*/
template <typename T> T * Vector<T>::end() {
    if (_size == 0)
        return &_data[0];

    return &_data[_size];
}

/**
* Returns a RandomAccessIterator to the first element
* of the range.
*/
template <typename T> T const * Vector<T>::end() const {
    if (_size == 0)
        return &_data[0];

    return &_data[_size];
}

/**
* Returns a RandomAccessIterator to the first element
* of the range.
*/
template <typename T> T * Vector<T>::find(T val) {
    for (int i = 0; i < _size; ++i) {
        if (_data[i] == val) {
            return &_data[i];
        }
    }
    return end();
}

/**
* Returns a RandomAccessIterator to the first element
* of the range.
*/
template <typename T> T const * Vector<T>::find(T val) const {
    for (int i = 0; i < _size; ++i) {
        if (_data[i] == val) {
            return &_data[i];
        }
    }
    return end();
}

/**
 * Swaps all element from right to left.
 */
template<typename T> void Vector<T>::swap(Vector<T> & dest, Vector<T> & src) {
    T * temp = dest._data;
    dest._data = src._data;
    src._data = temp;
}

/**
 * Returns the size of the current list.
 */
template<typename T> std::size_t Vector<T>::size () const {
    return _size;
}

/**
 * Returns the number of elements that can potentially
 * be stored in the container without having
 * to reallocate the underlying storage.
 */
template<typename T> std::size_t Vector<T>::capacity () const {
    return _total_length;
}

/**
 * Resets the list, ie sets all the elements to {}.
 */
template<typename T> void Vector<T>::reset () {
    for (std::size_t i = 0; i < _size; ++i) {
        _data[i] = { };
    }
}

/**
 * Doubles the size of the _data array.
 */
template<typename T> void Vector<T>::double_space () {
    if (_total_length < 10)
        _total_length = 10;
    else
        _total_length *= 2;

    T * new_data = new T[_total_length];
    // Kopiera över gamla data till nya
    for (int i = 0; i < _size; ++i) {
        new_data[i] = _data[i];
    }
    std::swap(_data, new_data);
    delete [] new_data;
}