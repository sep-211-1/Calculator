#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyArray
{
	T* arr;
	int arr_size;
public:
	MyArray(T* arr, int arr_size) {
		this->arr = arr;
		this->arr_size = arr_size;
	}
	MyArray(int arr_size)
		:MyArray(new T[arr_size], arr_size) {}
	MyArray()
		:MyArray(nullptr, 0) {}
	MyArray(const MyArray& rv) {
		this->arr_size = rv.arr_size;
		this->arr = new T[this->arr_size];
		for (int i = 0; i < this->arr_size; i++)
			this->arr[i] = rv.arr[i];
	}
	~MyArray() {
		delete[]arr;
	}
	void push(T data) {
		T* temp = new T[arr_size + 1];
		for (int i = 0; i < arr_size; i++)
			temp[i] = arr[i];
		if (arr != nullptr)
			delete[]arr;
		temp[arr_size] = data;
		arr = temp;
		arr_size++;
	}
	void pop() {
		if (arr == nullptr) return;
		else if (arr_size == 1) {
			delete[]arr;
			arr = nullptr;
		}
		else {
			T* temp = new T[arr_size - 1];
			for (int i = 0; i < arr_size - 1; i++) {
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
		}
		arr_size--;
	}
	int size() {
		return arr_size;
	}
	T operator[](int index) {
		return arr[index];
	}
	void sort(bool up = true) {
		for (int i = 0; i < arr_size - 1; i++)
			for (int j = i + 1; j < arr_size; j++)
				if (up? (arr[i] > arr[j]):(arr[i] < arr[j]))
					swap(arr[i], arr[j]);
	}
	void reverse() {
		for (int i = 0; i < arr_size / 2; i++)
			swap(arr[i], arr[arr_size - 1 - i]);
	}
	bool empty() {
		return arr == nullptr;
	}
	void clear() {
		delete[]arr;
		arr = nullptr;
		arr_size = 0;
	}
	MyArray<T> operator+(const MyArray& rv) {
		MyArray<T> arr;
		for (int i = 0; i < this->arr_size; i++)
			arr.push(this->arr[i]);

		for (int i = 0; i < rv.arr_size; i++)
			arr.push(rv.arr[i]);
		return arr;
	}

};

