#include <iostream>
#include <cstdlib>
#include <stdexcept>

template<class T> class Vector {
public:
  std::size_t length;
  std::size_t allocatedmemory;
  T *array;
  const int standardincrease = 100;

  void checkfunction () {
    static_assert(std::is_move_constructible<T>(), "is not moveConstructible");
    static_assert(std::is_move_assignable<T>(), "is not moveAssignable");
  }
  explicit Vector<T>(const std::size_t i) {
    checkfunction();
    this->length = i;
    this->allocatedmemory = this->length + standardincrease;
    array = new T[this->allocatedmemory];
    for(int j = 0; j < this->length; j++) {
        array[j] = T();
  }
}

  Vector<T>(std::size_t i, T value) {
    checkfunction();
    this->length = i;
    this->allocatedmemory = this->length + standardincrease;
    array = new T[this->allocatedmemory];
    for(int j = 0; j < this->length; j++) {
      array[j] = value;
    }
  }

  //  std::cout << "default-constructor " << this->length << std::endl
  Vector<T>() {
    checkfunction();
    this->length = 0;
    this->allocatedmemory = 0;
    this->array = new T[0];
  }
  Vector<T>(std::initializer_list<T> a) {
    checkfunction();
    this->length = a.size();
    this->allocatedmemory = this->length + standardincrease;
    const T * iterator = a.begin();
    this->array = new T[this->allocatedmemory];
    for(int i = 0; i < a.size(); i++) {
        this->array[i] = iterator[i];
    }
    
  //  std::cout << "iterator constructor " << this->array[0] << std::endl;
  }
  Vector<T>(Vector const& src) {
    checkfunction();
    this->length = src.length;
    this->allocatedmemory = this->length + standardincrease;
    this->array = new T[this->allocatedmemory];
    for(int i = 0; i < this->length; i++) {
      this->array[i] = src.array[i];
    }

   //  std::cout << "copy-constructor " << this->length << std::endl;
   }
  Vector<T>(Vector&& src) {
    checkfunction();
    delete[] array;
    this->length = src.length;
    this->allocatedmemory = this->length;
    this->array = src.array;
    src.length = 0;
    src.array = new T[0];
    
    //std::cout << "move-constructor " << this->length << std::endl;
   }

   void push_back(const T& elem) {
    if(this->allocatedmemory == 0) {
      delete [] this->array;
      this->array = new T[standardincrease];
      this->allocatedmemory = standardincrease;
    }
    if(this->allocatedmemory == this->length) {
      this->allocatedmemory += standardincrease;
      T * temparr = new T[this->allocatedmemory];
      for(int i = 0; i < this->length; i++) {
        temparr[i] = this->array[i];
      }
      delete[] this->array;
      this->array = new T[this->length + standardincrease];
      this->array = temparr;
      delete[] temparr;
    }
    this->array[length] = elem;
    this->length++;
   }

   void insert(std::size_t index, const T& elem) {
    if(index > this->length)
      throw std::out_of_range("Out of range");
    if(index == this->length)
      push_back(elem);
    else {
      this->push_back(this->array[this->length-1]);
      for(int i = this->length-1; i > index; i--) {
        this->array[i] = this->array[i-1];
      }
      this->array[index] = elem;
    }
    
   }
   void clear() {
    delete [] this->array;
    this->array = new T[this->allocatedmemory];
    this->length = 0;
    }

   void erase(std::size_t index) {
    if(index >= this->length || index < 0)
      throw std::out_of_range("Out of range");
    for(size_t i = index; i < this->length-1; i++) {
      this->array[i] = this->array[i+1];
    }
    this->length--;
  }

  ~Vector<T> () {
    delete[] this->array;
   // std::cout << "destructor" << std::endl;
  }
 T const * begin() const {
    return this->array;
  }
 T const * end() const {
     return &this->array[this->length];
  }
  
  T const * find(const T& a) const {
    for(int i = 0; i < this->length; i++) {
      if(this->array[i] == a) {
        return &this->array[i];
      }
    }
    return this->end();
  }
 
 T * begin() {
    return this->array;
  }
 T * end() {
     return &this->array[this->length];
  }
  T * find(T const& a) {
    for(int i = 0; i < this->length; i++) {
      if(this->array[i] == a) {
        return &this->array[i];
      }
    }
    return this->end();
  }

  std::size_t size() {
      return this->length;
  }
  std::size_t size() const {
      return this->length;
  }
  std::size_t capacity() {
    return this->allocatedmemory;
  }
  std::size_t capacity() const {
    return this->allocatedmemory;
  }
  
    Vector<T> & operator=(Vector<T> const& src){
        if(this != &src) {  // direct check for self-assignment
            if (this->length != src.length) {
                delete[] this->array;
                this->array = nullptr; // this->array = 0;
                this->array = src.length ? new T[src.length] : nullptr;
                this->length = src.length;
            }
            std::copy(src.array, src.array + this->length, this->array);
        }
      //  std::cout << "move assign operator" << std::endl;
        return *this;
    }
    
    Vector<T>& operator=(Vector<T>&& src) {
        // Swapping
        if(this != &src) {
            delete[] array;
            std::swap(this->array, src.array);
            std::swap(this->length, src.length);
            src.length = 0;
            src.array = new T[0];
        //  std::cout << "copy assignment" << std::endl;  
        }
        return *this;
    }
   T const & operator[] (std::size_t index) const {
       if(index >= this->length)
        throw std::out_of_range ("Out of range");
     //std::cout << "the assignment operator" << std::endl;
     return *(array + index);
   }
   T& operator[] (std::size_t index) {
      if(index >= this->length)
        throw std::out_of_range ("Out of range");
    // std::cout << "the assignment operator" << std::endl;
     return *(array + index);
   }

   // Assigns (unsigned int){} to each element in the container.
   void reset() {
    for(int i = 0; i < this->length; i++) {
      this->array[i] = { };
    }
   }
};
