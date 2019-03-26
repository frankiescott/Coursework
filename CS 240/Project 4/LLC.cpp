#include <string>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

template <class T> struct Node {
	T data;
	Node<T>* next;
};
	
template <class T> class LLC {
	public:
		LLC();
		LLC(const LLC<T> &source);
		~LLC();
		bool insert(const T &s);
		void head(int n); 
		template <typename U> friend ostream& operator<<(ostream &os, const LLC<U> &list);
		int len();
		bool contains(const T &s);
		T tail();
		T pop();
		T peek();
		void clear();
		bool remove(const T &s);
		bool join(LLC other);
		LLC<T>& operator+=(const int &n);
		LLC<T>& operator=(const LLC<T> &source);
		LLC<T> operator+(const LLC<T> &rightlist);
		void shuffle();
	private:
		Node<T> *first;
		Node<T> *last;
		int size;
};

template<typename T> 
LLC<T>::LLC() {
	this->first = nullptr; //empty list
	this->last = nullptr;
	this->size = 0;
}

template<typename T> 
LLC<T>::~LLC() {
	Node<T> *cur = this->first;
	while (cur) {
		Node<T> *tmp = cur;
		cur = cur->next;
		delete tmp; //clear out heap data
	}
}

template<typename T> 
void LLC<T>::clear() {
	Node<T> *cur = this->first;
	while (cur) {
		Node<T> *tmp = cur;
		cur = cur->next;
		delete tmp; //clear out heap data
	}
}

template<typename T> 
LLC<T>::LLC(const LLC<T> &source) {
	this->size = 0;
	this->first = nullptr;
	this->last = nullptr; //assume list to copy from is empty
	
	Node<T> *cur = source.first; //check to see if it has data
	while (cur) { //if it does, call insert method to append data
		this->insert(cur->data);
		cur = cur->next;
	}
}

template<typename T> 
int LLC<T>::len() { return this->size; }

template<typename T> 
bool LLC<T>::insert(const T &s) {
	Node<T> *n = new Node<T>();
	n->data = s;
	n->next = nullptr;
	
	if (this->size == 0) {
		this->first = n;
		this->last = n;
		this->size++;
		return true;
	}
	else {
		this->last->next = n;
		this->last = n;
		this->size++;
		return true;
	}
	return false;
}

template<typename T> 
bool LLC<T>::contains(const T &s) {
	Node<T> *n = this->first;
	while (n) {
		if (n->data == s)
			return true;
		n = n->next;
	}
	return false;
}

template<typename T> 
T LLC<T>::tail() {
	if (this->last != nullptr) {
		T data = this->last->data;
		return data;
	}
}

template<typename T> void LLC<T>::head(int pos) {
	string output = "[";
	Node<T> *n = this->first;
	for (int i = 0; i < pos; ++i) {
		if (n == nullptr)
			break;
		else {
			//are we at the end of the list or at the end of the loop
			//prints [1, 2, 3] instead of [1, 2, 3, ]
			//also allows the user to pass an argument > list size and it will print the entire list
			if (n->next == nullptr || i + 1 == pos) {
				output = output + n->data;
				break;
			}
			else {
				output = output + n->data + ", ";
				n = n->next;
			}
		}
	}
	output = output + "]";
	cout << output;
}

template<typename T> 
bool LLC<T>::remove(const T &s) {
	bool flag = false; //first assume deletion was unsuccessful
	Node<T> **n = &first; //double pointer for current and prev pointers
	while (*n) {
		if ((*n)->next == this->last && (*n)->next->data == s) { //is the next pointer the last in the list and are we removing it?
			this->last = *n; //update last pointer
		}
		if ((*n)->data == s) {
			Node<T> *temp = (*n)->next;
			delete *n;
			this->size--;
			*n = temp;
			flag = true; //as soon as a removal occurs, flip the flag to true
		}
		else {
			n = &(*n)->next;
		}
	}
	return flag; //return true or false depending on whether or not a removal occured
}

template<typename T> 
LLC<T>& LLC<T>::operator+=(const int &n) {
	if (this->size != 0) { //make sure list is not empty
		for (int i = 0; i < n; ++i) { //keep swapping values with n as terminator
			this->last->next = this->first;
			this->last = this->first;
			this->first = this->first->next;
			this->last->next = nullptr;
		}
		return *this;
	}
}

template<typename T> 
LLC<T>& LLC<T>::operator=(const LLC<T> &source) {
	if (this != &source) { //prevent self copy
		Node<T> *cur = this->first;
		while (cur) {
			Node<T> *tmp = cur;
			cur = cur->next;
			delete tmp; //clear out heap data
		}
		this->first = nullptr; //reset non-heap data
		this->last = nullptr;
		this->size = 0;
		cur = source.first; //check to see if source has data
		while (cur) {
			this->insert(cur->data); //insert will assign non-heap data from source
			cur = cur->next;
		}
		return *this;
	}
}

template<typename T> 
bool LLC<T>::join(LLC<T> other) {
	bool joined = false; //assume nothing was joined
	Node<T> *cur = other.first;
	while (cur) {
		joined = true; //switch the flag since a node was found to join
		this->insert(cur->data); //append via insert method
		cur = cur->next;
	}
	return joined; //return true or false if a list was joined or not
}

template<typename T> 
void LLC<T>::shuffle() {
	if (this->size > 1) { //cannot shuffle empty list or list with 1 element
		int randnum, counter;
		int loop = rand() % 100 + 1000; //random number between 30 and 100 to drive loop
		for (int i = 0; i < loop; i++) {
			randnum = rand() % (this->size - 1) + 1; //random number between 1 and size of list
			Node<T> *cur = this->first;
			Node<T> *prev = nullptr;
			//iterate over list n times and take that node and swap it with the first node
			//do this x times (controlled by loop variable)
			for (int c = 0; (c < randnum) && cur; ++c) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == this->last && this->size > 2) { //swapping first and last elements in a list with more than 2 elements
				cur->next = this->first->next;
				this->first->next = nullptr;
				prev->next = this->first;
				this->last = this->first;
				this->first = cur;
			}
			else if (this->size == 2) { //swapping first and last elements in a list with 2 elements
				randnum = rand() % 2; //decide whether to swap or not for a random shuffle
				if (randnum == 0) {
					Node<T> *tmp = this->last;
					this->last = this->first;
					this->first = tmp;
					this->last->next = nullptr;
					this->first->next = this->last;
				}
			}
			else { //standard swap in the middle of list
				Node<T> *tmp = cur->next;
				prev->next = this->first;
				cur->next = this->first->next;
				this->first->next = tmp;
				this->first = cur;
			}
		}
	}
}

template<typename T> 
LLC<T> LLC<T>::operator+(const LLC<T> &rightlist) {
	LLC<T> list = LLC(); //create new list
	Node<T> *cur = this->first; //append data from left hand list to new list
	while (cur) {
		list.insert(cur->data);
		cur = cur->next;
	}
	cur = rightlist.first; //append data from right hand list to new list
	while (cur) {
		list.insert(cur->data);
		cur = cur->next;
	}
	return list; //return the new list
}

template<typename T> 
ostream& operator<<(ostream &os, const LLC<T> &list) {
	string output = "[";
	Node<T> *n = list.first;
	while (n) {
		if (n->next == nullptr) {
			output = output + n->data.suit;
			break;
		}
		else {
			output = output + n->data.suit + ", ";
			n = n->next;
		}
	}
	output = output + "]";
	os << output;
}

template<typename T>
T LLC<T>::pop() {
	Node<T> *n = this->first;
	if (n) {
		T data = n->data;
		Node<T> *tmp = n;
		this->first = n->next;
		delete tmp;
		this->size--;
		return data;
	}
}

template<typename T>
T LLC<T>::peek() {
	Node<T> *n = this->first;
	if (n) {
		Node<T> *tmp = n;
		T data = n->data;
		return data;
	}
}
		
	
