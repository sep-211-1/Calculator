#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyStack
{
	template <typename T>
	class Node {
	public:
		T data;
		Node<T>* pNext;
		Node(T data, Node<T>* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	Node<T>* pTop;
	int stack_size;
public:
	MyStack() {
		pTop = nullptr;
		stack_size = 0;
	}
	void push(T data) {
		pTop = new Node<T>(data, pTop);
		stack_size++;
	}
	void pop() {
		if (pTop == nullptr) return;
		else {
			Node<T>* temp = pTop->pNext;
			delete pTop;
			pTop = temp;
			stack_size--;
		}
	}
	bool empty() {
		return pTop == nullptr;
	}
	void clear() {
		while (!empty()) {
			pop();
		}
	}
	T top() {
		return pTop->data;
	}
	~MyStack() {
		clear();
	}
};

