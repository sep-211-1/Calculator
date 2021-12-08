#pragma once
template <typename T>
class MyQueue
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
	Node<T>* head;
	Node<T>* tail;
	int queue_size;
public:
	MyQueue() {
		head = tail = nullptr;
		queue_size = 0;
	}
	bool empty() {
		return head == nullptr;
	}
	void push_back(T data){
		if (empty()) {
			head = tail = new Node<T>(data);
		}
		else {
			tail->pNext = new Node<T>(data);
			tail = tail->pNext;
		}
		queue_size++;
	}
	void pop_front() {
		if (empty()) return;
		else if (tail == head) {
			delete head;
			head = tail = nullptr;
		}
		else {
			Node<T>* temp = head;
			head = head->pNext;
			delete temp;
		}
		queue_size--;
	}
	T front() {
		return head->data;
	}
	T back() {
		return tail->data;
	}
	int size() {
		return queue_size;
	}
	void clear() {
		while (!empty())
			pop_front();
	}
	~MyQueue() {
		clear();
	}
};

