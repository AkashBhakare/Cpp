#pragma once

template <typename T>
class Queue {
private:
	std::vector<T> container;
public:
	Queue(const T&& ref) :container({ std::move(ref) }) {

	}
	void push(T data) {

	}
	T peek()const {
		return container.front();
	}
	T pop() {

	}

};

template <typename T>
class MyStack {
private:
	std::vector<T> container;
public:
	MyStack() {
		container.resize(10);
	}
	void push(T data) {

	}
	T peek()const {
		return container.front();
	}
	T pop() {

	}

};