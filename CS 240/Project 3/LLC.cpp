#include <string>
#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

#include "LLC.h"

LLC::LLC() {
	this->first = nullptr; //empty list
	this->last = nullptr;
	this->size = 0;
}

LLC::~LLC() {
	Node *cur = this->first;
	while (cur) {
		Node *tmp = cur;
		cur = cur->next;
		delete tmp; //clear out heap data
	}
}

LLC::LLC(const LLC &source) {
	this->size = 0;
	this->first = nullptr;
	this->last = nullptr; //assume list to copy from is empty
	
	Node *cur = source.first; //check to see if it has data
	while (cur) { //if it does, call insert method to append data
		this->insert(cur->data);
		cur = cur->next;
	}
}

int LLC::len() { return this->size; }

bool LLC::insert(const string &s) {
	Node *n = new Node();
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

bool LLC::contains(const string &s) {
	Node *n = this->first;
	while (n) {
		if (n->data == s)
			return true;
		n = n->next;
	}
	return false;
}

string LLC::tail() {
	if (this->last != nullptr) {
		string data = this->last->data;
		return data;
	}
}

void LLC::head(int pos) {
	string output = "[";
	Node *n = this->first;
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

bool LLC::remove(const string &s) {
	bool flag = false; //first assume deletion was unsuccessful
	Node **n = &first; //double pointer for current and prev pointers
	while (*n) {
		if ((*n)->next == this->last && (*n)->next->data == s) { //is the next pointer the last in the list and are we removing it?
			this->last = *n; //update last pointer
		}
		if ((*n)->data == s) {
			Node *temp = (*n)->next;
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

LLC& LLC::operator+=(const int &n) {
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

LLC& LLC::operator=(const LLC &source) {
	if (this != &source) { //prevent self copy
		Node *cur = this->first;
		while (cur) {
			Node *tmp = cur;
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

bool LLC::join(LLC other) {
	bool joined = false; //assume nothing was joined
	Node *cur = other.first;
	while (cur) {
		joined = true; //switch the flag since a node was found to join
		this->insert(cur->data); //append via insert method
		cur = cur->next;
	}
	return joined; //return true or false if a list was joined or not
}

void LLC::shuffle() {
	srand(time(NULL));
	if (this->size > 1) { //cannot shuffle empty list or list with 1 element
		int randnum, counter;
		int loop = rand() % 30 + 20; //random number between 20 and 30 to drive loop
		for (int i = 0; i < loop; i++) {
			randnum = rand() % (this->size - 1) + 1; //random number between 1 and size of list
			Node *cur = this->first;
			Node *prev = nullptr;
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
					Node *tmp = this->last;
					this->last = this->first;
					this->first = tmp;
					this->last->next = nullptr;
					this->first->next = this->last;
				}
			}
			else { //standard swap in the middle of list
				Node *tmp = cur->next;
				prev->next = this->first;
				cur->next = this->first->next;
				this->first->next = tmp;
				this->first = cur;
			}
		}
	}
}

LLC LLC::operator+(const LLC &rightlist) {
	LLC list = LLC(); //create new list
	Node *cur = this->first; //append data from left hand list to new list
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

ostream& operator<<(ostream &os, const LLC &list) {
	string output = "[";
	Node *n = list.first;
	while (n) {
		if (n->next == nullptr) {
			output = output + n->data;
			break;
		}
		else {
			output = output + n->data + ", ";
			n = n->next;
		}
	}
	output = output + "]";
	os << output;
}
	
