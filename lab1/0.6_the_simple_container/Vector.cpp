#include <iostream>
#include <cstdlib>

class Vector {
public:
  std::size_t size;
  unsigned int *array;
  Vector (std::size_t i) {
    this->size = i;
    array = new unsigned int[i];
    std::cout << "default-constructor " << this->size << std::endl;
  }
   Vector (Vector const& src) {
    this->size = src.size;
    this->array = new unsigned int[this->size];
    for(int i = 0; i < this->size; i++) {
      this->array[i] = src.array[i];
    }

     std::cout << "copy-constructor " << this->size << std::endl;
   }
   Vector (Vector&& src) {
    this->size = src.size;
    this->array = new unsigned int[this->size];
    for(int i = 0; i < this->size; i++) {
      this->array[i] = src.array[i];
    }
   }


  ~Vector () {
    delete[] this->array;
   // delete[] this->array;
    std::cout << "destructor" << std::endl;
  }

   unsigned int operator[] (std::size_t index) const {
     std::cout << "the assignment operator" << std::endl;
     return *(array + index);
   }
  unsigned int& operator[] (std::size_t index) {
     std::cout << "the assignment operator" << std::endl;
     return *(array + index);
   }
};
int main() {
  Vector v(7);
  v[1] = 5;
  std::cout << "testprint" << v[1] << std::endl;
  Vector a(v);
  std::cout << a[1];


  return 0;
}
/*
swap(T & a, T & b){
  T tmp = a;
  a = b;
  a = tmp;
}
*/

