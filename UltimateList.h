#ifndef _ULTIMATELIST_H_
#define _ULTIMATELIST_H_

#include <iostream>

using namespace std;

template <typename T>struct ListElement {
	T value;
	ListElement* next;
	ListElement(T t) : value(t), next(nullptr)  {}
};

template <typename T>class List {
protected:
	ListElement<T>* head;
	unsigned short size;
public:
	List() : head(nullptr), size(0) {};
	~List() {
		size = 0;
		ListElement<T>* ptr = head;
		ListElement<T>* prev = nullptr;
		while (ptr != nullptr)
		{
			prev = ptr;
			ptr = ptr->next;
			delete prev;
		}
	}
	void addElement(T t) {
		if (!head) {
			head = new ListElement<T>(t);
		}
		else
		{
			ListElement<T>* ptr = head;
			while (ptr->next != nullptr)
			{
				ptr = ptr->next;
			}
			ptr->next = new ListElement<T>(t);
		}
		size++;
	}

	void addElementSorted(T t) {
		if (!head) {
			head = new ListElement<T>(t);
		}
		else
		{
			ListElement<T>* ptr = head;
			ListElement<T>* prev = head;
			while (ptr->next != nullptr && ptr->value < t)		//stop if act is bigger or next is nullptr
			{
				prev = ptr;
				ptr = ptr->next;
			}

			ListElement<T>* ptr2 = new ListElement<T>(t);
			if (prev == head)
			{
				ptr2->next = ptr;
				head = ptr2;
			}
			else if (ptr->value > t)
			{
				prev->next = ptr2;
				ptr2->next = ptr;
			}
			else if (ptr->next == nullptr)
			{
				ptr->next = ptr2;
			}
		}
		size++;
	}

	void printElements() {
		ListElement<T>* ptr = head;
		while (ptr != nullptr)
		{
			cout << ptr->value << endl;
			ptr = ptr->next;
		}
	}

	void reverseList() {
		ListElement<T> *current, *prev, *next;
		current = head;
		prev = nullptr;
		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}

	class iterator {
		List<T>* _L;
		ListElement<T> *element;
		unsigned short int curr;
	public:
		iterator(List<T>* L, unsigned short i) : _L(L), element(nullptr), curr(i) {
			ListElement<T>* ptr = _L->head;
			int n = 0;
			while (n <= _L->size && n != curr)
			{
				ptr = ptr->next;
				n++;
			}
			element = ptr;
		}

		ListElement<T>& operator*() {
			return *element;
		}

		iterator& operator++() {
			if (curr <= _L->size)
			{
				element = element->next;
				curr++;
			}
			return *this;
		}

		iterator operator++(int) {
			iterator i(*this, this->curr + 1);
			return i;
		}

		int operator !=(const iterator& i) {
			int ret = !(this->element == i.element && this->_L == i._L);
			return ret;
		}

	};
	iterator begin() { return iterator(this, 0); }
	iterator end() { return iterator(this, size); }
};

//***************************
//Example of usage below!
//***************************

//int main(int argc, char* argv[]) {
//	
//	{
//		List<int> L;
//		L.addElementSorted(4);
//		L.addElementSorted(2);
//		L.addElementSorted(1);
//		L.addElementSorted(3);
//		L.addElementSorted(5);
//		L.addElementSorted(0);
//		L.addElementSorted(8);
//		L.addElementSorted(7);
//		L.addElementSorted(6);
//		L.addElementSorted(9);
//		L.addElementSorted(10);
//		for (auto &node : L) {
//			cout << node.value << endl;
//		}
//		//L.printElements();
//		L.reverseList();
//		//L.printElements();
//		for (auto &node : L) {
//			cout << node.value << endl;
//		}
//	}
//	system("PAUSE");
//	return 0;
//}

#endif	//_ULTIMATELIST_H_