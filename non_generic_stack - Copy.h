#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
namespace mylib {

	class Stack_Integers {
	private:
		const size_t default_size{ 5 };
		size_t max_size{ default_size };
		std::vector<int> container{};
	public:
		Stack_Integers(size_t size);
		void push(int data);
		int peek()const;
		int pop();
		bool is_stack_full() const;
		bool is_stack_empty() const;
	};

	class Stack_Double {
	private:
		const size_t default_size{ 5 };
		size_t max_size{ default_size };
		std::vector<double> container{};
	public:
		Stack_Double(size_t size);
		void push(double data);
		double peek()const;
		double pop();
		bool is_stack_full() const;
		bool is_stack_empty() const;
	};

	Stack_Integers::Stack_Integers(size_t size)
	{
		if (size > 0) {
			this->max_size = size;
		}
		container.reserve(max_size);
	}

	inline bool Stack_Integers::is_stack_full() const
	{
		return container.size() == max_size;
	}

	inline bool Stack_Integers::is_stack_empty() const
	{
		return container.size() == 0;
	}

	inline void Stack_Integers::push(int data)
	{
		if (is_stack_full()) {
			throw std::overflow_error("Stack is full");
		}
		container.push_back(data);
		std::cout << "Pushed : " << data << '\n';
	}

	inline int Stack_Integers::peek() const
	{
		return container.back();
	}

	inline int Stack_Integers::pop()
	{
		if (is_stack_empty()) {
			throw std::underflow_error("Stack is Empty!\n");
		}
		int data = container.back();
		container.pop_back();
		return data;
	}




	Stack_Double::Stack_Double(size_t size)
	{
		if (size > 0) {
			this->max_size = size;
		}
		container.reserve(max_size);
	}

	inline bool Stack_Double::is_stack_full() const
	{
		return container.size() == max_size;
	}

	inline bool Stack_Double::is_stack_empty() const
	{
		return container.size() == 0;
	}

	inline void Stack_Double::push(double data)
	{
		if (is_stack_full()) {
			throw std::overflow_error("Stack is full");
		}
		container.push_back(data);
		std::cout << "Pushed : " << data << '\n';
	}

	inline double Stack_Double::peek() const
	{
		return container.back();
	}

	inline double Stack_Double::pop()
	{
		if (is_stack_empty()) {
			throw std::underflow_error("Stack is Empty!\n");
		}
		double data = container.back();
		container.pop_back();
		return data;
	}
}