#include "stdexcept"
#include <iostream>
#include "Box.h"

namespace my_lib {
	Box::Box() :Box(1, 1, 1) //Delagating constructor
	{
		std::cout << "Address : " << this << std::endl;

		//Box(1, 1, 1); incorrect way to delagate
	}

	Box::Box(int length, int height, int width)
	{
		std::cout << "Address : " << this << std::endl;
		if (this->checkDimensions(length, height, width)) {
			this->length = length;
			this->height = height;
			this->width = width;
		}

	}

	bool Box::checkDimensions(int length, int height, int width) const {
		std::cout << "Address : " << this << std::endl;
		if (!isLengthValid(length)) {
			throw std::invalid_argument("length is invlid\n");
		}
		if (!isHeightValid(height)) {
			throw std::invalid_argument("Height is invlid\n");
		}
		if (!isWidthValid(width)) {
			throw std::invalid_argument("Width is invlid\n");
		}

	}

	bool Box::isHeightValid(int height) const {
		constexpr int min_height{ 1 };
		constexpr int max_height{ 100 };
		return height >= min_height && height <= max_height;
	}

	bool Box::isWidthValid(int height) const {
		constexpr int min_width{ 1 };
		constexpr int max_width{ 50 };
		return height >= min_width && height <= max_width;
	}

	bool Box::isLengthValid(int height) const {
		constexpr int min_length{ 1 };
		constexpr int max_length{ 100 };
		return height >= min_length && height <= max_length;
	}

	int Box::getHeight() const {
		return this->height;
	}

	int Box::getWidth() const
	{
		return width;
	}

	int Box::getLength() const
	{
		std::cout << "Returning tha length of the object stored at address : " << this << std::endl;
		//	this = nullptr;
		return length;
	}

	Box* Box::setLength(int length)
	{
		if (isLengthValid(length)) {
			this->length = length;
		}
		else {
			throw std::invalid_argument("Invalid Length specified!");
		}
		return this;
	}

	Box* Box::setWidth(int width)
	{
		if (isWidthValid(width)) {
			this->width = width;
		}
		else {
			throw std::invalid_argument("Invalid width specified!");
		}
		return this;
	}

	Box* Box::setHeight(int height)
	{
		if (isHeightValid(width)) {
			this->height = height;
		}
		else {
			throw std::invalid_argument("Invalid height specified!");
		}
		return this;
	}



	Box& Box::set_length(int length)
	{
		if (isLengthValid(length)) {
			this->length = length;
		}
		else {
			throw std::invalid_argument("Invalid Length specified!");
		}
		return *this;
	}

	Box& Box::set_width(int width)
	{
		if (isWidthValid(width)) {
			this->width = width;
		}
		else {
			throw std::invalid_argument("Invalid width specified!");
		}
		return *this;
	}

	Box& Box::set_height(int height)
	{
		if (isHeightValid(width)) {
			this->height = height;
		}
		else {
			throw std::invalid_argument("Invalid height specified!");
		}
		return *this;
	}
}
