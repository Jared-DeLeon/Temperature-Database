#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <climits>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	// Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
	clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
	Node* cur = source.head;
	Node* prev = cur;
	while (cur) {
		Node* newNode = new Node(cur->data.id, cur->data.year, cur->data.month, cur->data.temperature);
		if (cur == source.head) {
			head = newNode;
		}
		else {
			prev->next = newNode;
			if (cur == source.tail) {
				tail = newNode;
			}
		}
		prev = newNode;
		cur = cur->next;
	}
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if (&source != this) {
		clear();
		Node* cur = source.head;
		Node* prev = cur;
		while (cur) {
			Node* newNode = new Node(cur->data.id, cur->data.year, cur->data.month, cur->data.temperature);
			if (cur == source.head) {
				head = newNode;
			}
			else {
				prev->next = newNode;
				if (cur == source.tail) {
					tail = newNode;
				}
			}
			prev = newNode;
			cur = cur->next;
		}
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function
	// cout << "Start: " << location << year << " " << month << " " << temperature << endl;
	Node* newNode = new Node(location, year, month, temperature);
	if (head==nullptr) { //empty list
		head = newNode;
		tail = newNode;
	}
	else {
		Node* cur = head;
		Node* prev = head;
		while (cur!=nullptr && cur->data < newNode->data) {
			prev = cur;
			cur = cur->next;
		}
		// exit loop either because came to end of list
		//  OR cur is greater than the newNode
		if (cur==head && prev==head) { // new head
			newNode->next = cur;
			head = newNode;
		}
		else { // add to middle or new tail
			newNode->next = cur;
			prev->next = newNode;
			if (prev==tail) { // new tail
				tail = newNode;
			}
		}
	}
}

string LinkedList::getAVG(std::string ID, int beginYear, int endYear){//finds average
    double average = 0;
    int sizeOfAverage = 0;
    ostringstream oss;
    
    Node* temp = head;
    while(temp != nullptr){//go throguh each node
        if(ID == temp->data.id && temp->data.year <= endYear && temp->data.year >= beginYear){
            //if ID matches and year is inside the range of years then add to average
            average += temp->data.temperature;//add temperature to average
            sizeOfAverage++;//increase number of things added to average
        }
        temp = temp->next;
    }
    
    if(sizeOfAverage == 0){//if you have added nothing to average
        oss << "unknown";//nothing matches
    }else{
        average = average/(sizeOfAverage);//divide average by the size of average
        oss << average;
    }
    return oss.str();//return the oss stream
}

string LinkedList::getMODE(std::string ID, int beginYear, int endYear){
    ostringstream oss;
    vector<int> potentialModes(101);//make a vector from -50 to 50
    
    Node* temp = head;
    while(temp != nullptr){
        if(ID == temp->data.id && temp->data.year <= endYear && temp->data.year>= beginYear){
            potentialModes.at(50+(int)round(temp->data.temperature))++;//for every correct node
            //add 1 to the index correleating to the temp
        }
        temp = temp->next;
    }
    
    int indexOfMode;
    int max = INT_MIN;
    for(int i=0; i < potentialModes.size(); i++){
        if(max <= potentialModes.at(i)){//find index with the most increments
            indexOfMode = i;
            max = potentialModes.at(i);
        }
    }
    if(max == 0){
        oss << "unknown";//if they are all 0 return unkown
    }else{
        oss << indexOfMode-50;//index of mode -50 is the temperature
    }
    return oss.str();
    
}

void LinkedList::clear() {
	// Implement this function
	Node* cur = head;
	while (cur) {
		Node* del = cur;
		cur = cur->next;
		delete del;
	}
	head = nullptr;
	tail = nullptr;
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return head;
}

string LinkedList::print() const {
	stringstream ss;
	// Implement this function
	Node* cur = head;
	while (cur) {
		ss << cur->data.id << " " << cur->data.year << " " << cur->data.month << " " << cur->data.temperature << endl;
		cur = cur->next;
	}

	return ss.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
