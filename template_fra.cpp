#include <iostream>

template<typename T, typename U>
bool subsequence(T target_begin, T target_end, U spy_begin, U spy_end) {
	if(spy_begin == spy_end) {
		return false;
	}
	if(target_begin == target_end) {
		return false;
	}
	for(;spy_begin != spy_end; ++spy_begin) {
		if(*target_begin == *spy_begin) {
			++target_begin;
			if(target_begin == target_end) {
				return true;
			}
		}
	}
	return false;
}

template<typename T>
struct Nod {
	T data;
	Nod* next;
	Nod(T data):data(data),next(nullptr) {}
	~Nod() {
		Nod* current = this;
		Nod* next_kill = this->next;
		while(current!=nullptr) {
			delete current;
			current=next_kill;
			next_kill=next_kill->next;
		}
	}
};

/*
* Assumes that T implements =,> 
*/
template<typename T> 
void insert(Nod<T> * & p, T data) {
	if(p == nullptr) {
		p = new Nod<T>(data);
	} else {
		if (p->data > data) {
			Nod<T> * tmp = new Nod<T>(data);
			tmp->next = p;
			p = tmp;
		} else {
			insert(p->next, data);
		}
	}

}
