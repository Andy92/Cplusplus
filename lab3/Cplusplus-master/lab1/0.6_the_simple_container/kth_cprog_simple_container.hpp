#include <iostream>
#include <cstdlib>
#include <stdexcept>

template<typename T> class Vector {
public:
  std::size_t length;
  T *array;
 Vector<T>(std::size_t i) {
    this->length = i;
    array = new unsigned int[i];
    for(int j = 0; j < this->length; j++) {
        array[j] = 0;
    }
  //  std::cout << "default-constructor " << this->length << std::endl;
  }
  Vector<T>(std::initializer_list<T> a) {
    const unsigned int * iterator = a.begin();
    this->array = new unsigned int[a.size()];
    for(int i = 0; i < a.size(); i++) {
        this->array[i] = iterator[i];
    }
    this->length = a.size();
  //  std::cout << "iterator constructor " << this->array[0] << std::endl;
  }
   Vector<T>(Vector const& src) {
    this->length = src.length;
    this->array = new unsigned int[this->length];
    for(int i = 0; i < this->length; i++) {
      this->array[i] = src.array[i];
    }

   //  std::cout << "copy-constructor " << this->length << std::endl;
   }
   Vector<T>(Vector&& src) {
    delete[] array;
    this->length = src.length;
    this->array = src.array;
    src.length = 0;
    src.array = new unsigned int[0];
    
    //std::cout << "move-constructor " << this->length << std::endl;
   }




   
  virtual ~Vector<T> () {
    delete[] this->array;
   // std::cout << "destructor" << std::endl;
  }
  
  std::size_t size() {
      return this->length;
  }
  
  std::size_t size() const {
      return this->length;
  }
  void size_init(size_t i) {
      this->length = i;
  }
    Vector<T>& operator=(Vector<T> const& src){
        if(this != &src) {  // direct check for self-assignment
            if (this->length != src.length) {
                delete[] this->array;
                this->array = nullptr; // this->array = 0;
                this->array = src.length ? new unsigned int[src.length] : nullptr;
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
            src.array = new unsigned int[0];
        //  std::cout << "copy assignment" << std::endl;  
        }
        return *this;
    }
   unsigned int operator[] (std::size_t index) const {
       if(index >= this->length)
        throw std::out_of_range ("Out of range");
     //std::cout << "the assignment operator" << std::endl;
     return *(array + index);
   }
  unsigned int& operator[] (std::size_t index) {
      if(index >= this->length)
        throw std::out_of_range ("Out of range");
    // std::cout << "the assignment operator" << std::endl;
     return *(array + index);
   }

   // Assigns (unsigned int){} to each element in the container.
   void reset() {
    for(int i = 0; i < this->length; i++) {
      this->array[i] = (unsigned int){0};
    }
   }
};