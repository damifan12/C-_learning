# include <iostream>
using namespace std;
# define eleType int
struct SequentialList {
	eleType* elements;
	int size;
	int capacity;
 };
void initializeList(SequentialList* list, int capacity) {
	list->elements = new eleType[capacity];
	list->size = 0;
	list->capacity = capacity;
}

void destroyList(SequentialList* list) {
	delete[] list->elements;
}


int size(SequentialList* list) {
	return list->size;
}

bool isEmpty(SequentialList* list) {
	return list->size == 0;

}

void insert(SequentialList* list, int index, eleType element) {
	if (index <0 || index> list->size) {
		throw std::invalid_argument("Invalid index");
		}
	if (list->size == list->capacity) {
		int newCapcity = list->capacity * 2;
		eleType* newElements = new eleType[newCapcity];
		for (int i = 0; i < list->size; ++i) {
			newElements[i] = list->elements[i];
			delete[] list->elements;
			list->elements = newElements;
			list->capacity = newCapcity;
		}

		}
	for (int i = list->size; i > index; i--) {
		list->elements[i] = list->elements[i - 1];
		}
		list->elements[index] = element;
		list->size++;

	}

	void deleteElement(SequentialList * list, int index){
		if (index <0 || index>= list->size) {
			throw std::invalid_argument("Invalid index");
		}
		for (int i = index; i < list->size - 1; ++i) {
			list->elements[i] = list->elements[i + 1];

		}
		list->size--;
	}

	int findElement(SequentialList* list, eleType element) {
		for (int i = 0; i < list->size; ++i) {
			if (list->elements[i] = element) {
			return i;
			}
		}
		return -1;
	}

	eleType getElement(SequentialList* list, int index) {
		if (index < 0 || index >= list->size) {
			throw std::invalid_argument("Invalid index");
		}
		return list->elements[index];

	}

	void updateElement(SequentialList *list, int index, eleType value) {
		if (index < 0 || index >= list->size) {
			throw std::invalid_argument("Invalid index");
		}
		list->elements[index] = value;
	}











	int main() {
		SequentialList myList;
		initializeList(&myList, 10);
		for (int i = 0; i < 10; ++i) {
			insert(&myList, i, i * 10);

		}
		cout << "Size:" << size(&myList) << endl;
		cout << "Is empty :" << isEmpty(&myList) << endl;

		for (int i = 0; i < size(&myList); ++i) {
			cout << getElement(&myList, i) << "";

		}
		cout << endl;
		deleteElement(&myList, 5);
		updateElement(&myList, 1, 1314);
		for (int i = 0; i < size(&myList); ++i) {
			cout << getElement(&myList, i) << "";

		}
		int idx = findElement(&myList, 20);
		updateElement(&myList, idx, 520);
		for (int i = 0; i < size(&myList); ++i) {
			cout << getElement(&myList, i) << "";

		}
		destroyList(&myList);
		return 0;
}
