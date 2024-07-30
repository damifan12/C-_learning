#include<iostream>
#include <stdexcept>
using namespace std;

#define eleType int

struct ListNode {
	eleType data;
	ListNode* next;

	ListNode(eleType x) : data(x), next(NULL){}

};

class LinkedList {
private:
	ListNode* head;
	int size;

public:
	LinkedList() : head(NULL), size(0) {}
	~LinkedList();
	void insert(int i, eleType value);
	void remove(int i);
	ListNode* find(eleType value);
	ListNode* get(int i);
	void update(int i, eleType value);
	void print();
	eleType sum();
	void append(eleType v);
	void ascInsert(eleType v);
};



LinkedList::~LinkedList() {
	ListNode *curr = head;
	while (curr != NULL) {
		ListNode* tmp = curr;
		curr = curr->next;
		delete tmp;

	}
}


void LinkedList::insert(int i, eleType value) {
	if (i<0 || i>size) {
		throw std::out_of_range("Invalid position");
	}
	ListNode *newNode = new ListNode(value);
	if (i == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		ListNode* curr = head;
		for (int j = 0; j < i - 1; j++) {
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next = newNode;
	}
	++size;
}


void LinkedList::remove(int i) {
	if (i<0 || i>size) {
		throw std::out_of_range("Invalid position");
	}
	if (i == 0) {
		ListNode* temp = head;
		head = head->next;
		delete temp;

	}
	else {
		ListNode* curr = head;
		for (int j = 0; j < i - 1; j++) {
			curr = curr->next;
		}
		ListNode* temp = curr->next;
		curr->next = temp->next;
		delete temp;
	}
	--size;
}



ListNode* LinkedList::find(eleType value) {
	ListNode* curr = head;
	while (curr && curr->data != value) {
		curr = curr->next;

	}
	return curr;

}


ListNode* LinkedList::get(int i) {
	if (i < 0 || i >= size) {
		throw std::out_of_range("Invalid position");
	}
	ListNode* curr = head;
	for (int j = 0; j < i; ++j) {
		curr = curr->next;
	}
	return curr;
}

void LinkedList::update(int i, eleType value) {
	get(i)->data = value;

}
void LinkedList::print() {
	ListNode* curr = head;
	while (curr) {
		cout << curr->data << "";
		curr = curr->next;
	}
	cout << endl;
}

eleType LinkedList::sum() {
	ListNode* curr = head;
	eleType ret = 0;
	while (curr != NULL) {
	
		ret +=curr->data;
		curr = curr->next;
		

	}
	return ret;

}

void LinkedList::append(eleType v) {
	insert(size, v);
}

void LinkedList::ascInsert(eleType v) {
	if (size == 0) {
		insert(0, v);
		return;
	}
	ListNode* curr = head;
	for (int i = 0; i < size; ++i) {
		if (v <= curr->data) {
			insert(i, v);
			return;
		}
		curr = curr->next;
	}
	insert(size, v);
	

}

int main() {
	int n,x;
	LinkedList l;
	while (cin >> n >> x) {
		if (!n && !x) {
			break;
		}
		
		while (n--) {
			int v;
			cin >> v;
			l.append(v);
			
		}
		l.ascInsert(x);
		l.print();

	}


	

	return 0;
}