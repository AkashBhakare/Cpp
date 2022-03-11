#pragma once
#include <vector>
#include <stdexcept>
template <typename T = int>
class Stack {
private:
	const size_t default_size{ 5 };
	size_t max_size{ default_size };
	std::vector<T> container{};
public:
	Stack(size_t size);
	void push(T data);
	T peek()const;
	T pop();
	bool is_stack_full() const;
	bool is_stack_empty() const;
};

template <typename T>
Stack<T>::Stack(size_t size)
{
	if (size > 0) {
		this->max_size = size;
	}
	container.reserve(max_size);
}

template <typename T>
inline bool Stack<T>::is_stack_full() const
{
	return container.size() == max_size;
}

template <typename T>
inline bool Stack<T>::is_stack_empty() const
{
	return container.size() == 0;
}

template <typename T>
inline void Stack<T>::push(T data)
{
	if (is_stack_full()) {
		throw std::overflow_error("Stack is full");
	}
	container.push_back(data);
	std::cout << "Pushed : " << data << '\n';
}

template <typename T>
inline T Stack<T>::peek() const
{
	return container.back();
}

template <typename T>
inline T Stack<T>::pop()
{
	if (is_stack_empty()) {
		throw std::underflow_error("Stack is Empty!\n");
	}
	T data = container.back();
	container.pop_back();
	return data;
}
