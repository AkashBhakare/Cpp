#pragma once
#include <string>
#include <iostream>
namespace mylib {
	class Student
	{
		friend std::ostream& operator << (std::ostream& out, const Student& ref);
		friend std::ofstream& operator << (std::ofstream& out, const Student& ref);
		friend std::istream& operator >> (std::istream& in, Student& ref);
		friend std::ifstream& operator>>(std::ifstream& fin, Student& ref);
		friend std::fstream& operator>>(std::fstream& fin, Student& ref);
		friend std::fstream& operator << (std::fstream& out, const Student& ref);

	private:
		static const size_t max_name_length{ 32 };
		char name[max_name_length];
		size_t rollno;
		float percentage;
	public:
		Student(std::string name, size_t rollno, float percentage);
		Student() = default;
	};


}

