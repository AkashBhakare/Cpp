// Dynamic_Memory_1_malloc_calloc_realloc.cpp : 
//malloc and calloc and realloc


#include <iostream>
#include <memory>
#include <cstdlib>
#include <iomanip>
#include <cstring>

void malloc_demo1() {

	int* iptr = nullptr;

	/* allocating memory for a single integer*/
	iptr = (int*)malloc(sizeof(int));

	if (iptr == nullptr) {
		std::cerr << "Memory allocation failed!\n";
		std::exit(EXIT_FAILURE);
	}

	//	std::cout << "Address : " << std::showbase << std::hex << reinterpret_cast<unsigned long long>(iptr)  << "\tValue : " << std::dec << *iptr <<"\tInitially" << std::endl;

	std::cout << "Address : " << iptr << "\tValue : " << *iptr << "\tInitially" << std::endl;

	/* Store data into dynamically allocated memory*/
	*iptr = 44;
	std::cout << "Address : " << iptr << "\tValue : " << *iptr << "\tAfter assignment" << std::endl;

	/*release the memory allocated*/
	free(iptr);
	std::cout << "Address : " << iptr << "\tafter releasing" << std::endl;;
	iptr = nullptr; //handle dangling pointer
	std::cout << "Address : " << iptr << "\tafter handling dangling pointer" << std::endl;;
	//Cannot dereference a nullptr
	//std::cout << "\tValue : " << *iptr << "\tafter releasing" << std::endl;
}


/*Memory does not have any type
We can resue the same block to store values of different type
*/
void malloc_demo2() {

	int* iptr = nullptr;

	/* allocating memory large enough single integer*/
	//iptr = (int*)malloc(sizeof(int)); // c style
	iptr = reinterpret_cast<int*>(malloc(sizeof(int))); //cpp style

	if (iptr == nullptr) {
		std::cerr << "Memory allocation failed!\n";
		std::exit(EXIT_FAILURE);
	}

	//	std::cout << "Address : " << std::showbase << std::hex << reinterpret_cast<unsigned long long>(iptr)  << "\tValue : " << std::dec << *iptr <<"\tInitially" << std::endl;

	std::cout << "Address : " << iptr << "\tValue : " << *iptr << "\tInitially using iptr" << std::endl;

	/* Store data into dynamically allocated memory*/
	*iptr = 65;
	std::cout << "Address : " << iptr << "\tValue : " << *iptr << "\tAfter assignment" << std::endl;

	char* cptr = nullptr;
	//cptr = iptr; Error since pointers are pointing to variables of different type

	/*convert int * to char */
	cptr = reinterpret_cast<char*>(iptr);
	std::cout << "Address : " << std::hex << reinterpret_cast<unsigned long long>(cptr) << "\tValue : "
		<< *cptr << "\tInitially using cptr" << std::endl;
	*(cptr + 0) = 'X';
	*(cptr + 1) = 'Y';
	*(cptr + 2) = 'Z';
	*(cptr + 3) = 'Q';
	std::cout << "The characters are as follows : \n";
	for (int i{ 0 }; i < 4; ++i) {
		std::cout << *(cptr + i) << " at address " << std::dec << reinterpret_cast<unsigned long long>(cptr + i) << std::endl;
	}
	std::cout << std::endl;

	float* fptr{ nullptr };
	fptr = reinterpret_cast<float*>(cptr);
	std::cout << "Address : " << fptr << "\tValue : " << *fptr << "\tInitially using fptr" << std::endl;
	*fptr = 66.77f;
	std::cout << "Address : " << fptr << "\tValue : " << *fptr << "\tafter assigning fptr" << std::endl;

	free(fptr); //releseae the memmory

	/*reset all dangling pointers*/
	cptr = nullptr;
	iptr = nullptr;
	fptr = nullptr;
}

void print_array(int* iptr, size_t number_of_elements) {
	for (size_t i{ 0 }; i < number_of_elements; ++i) {
		std::cout << *(iptr + i) << ", ";
	}
	std::cout << std::endl;
}

void store_values(int* iptr, size_t number_of_elements) {
	for (size_t i{ 0 }; i < number_of_elements; ++i) {
		*(iptr + i) = (i + 1) * 10;
	}
	std::cout << std::endl;
}

/* Allocate array dynamically */
void malloc_demo3() {
	size_t number_of_elements;
	std::cout << "How many integers do you want to store ? ";
	std::cin >> number_of_elements;

	int* iptr = reinterpret_cast<int*>(malloc(sizeof(int) * number_of_elements));

	if (iptr == nullptr) {
		std::cerr << "Memory allocation failed!\n";
		std::exit(EXIT_FAILURE);
	}

	std::cout << "The contnets of the array after allocation of memory :" << std::endl;
	print_array(iptr, number_of_elements);
	store_values(iptr, number_of_elements);
	std::cout << "The contnets of the array after storing data :" << std::endl;
	print_array(iptr, number_of_elements);

	/*release the entire block of memory starting from the address stored in iptr*/
	free(iptr);
	iptr = nullptr;

}


/* Allocate array dynamically */
void calloc_demo() {
	size_t number_of_elements;
	std::cout << "How many integers do you want to store ? ";
	std::cin >> number_of_elements;

	//allocate memory for number_of_element blocks each of size sizeof(int) and initialize each block to 0
	int* iptr = reinterpret_cast<int*>(calloc(number_of_elements, sizeof(int)));

	if (iptr == nullptr) {
		std::cerr << "Memory allocation failed!\n";
		std::exit(EXIT_FAILURE);
	}

	std::cout << "The contnets of the array after allocation of memory :" << std::endl;
	print_array(iptr, number_of_elements);
	store_values(iptr, number_of_elements);
	std::cout << "The contnets of the array after storing data :" << std::endl;
	print_array(iptr, number_of_elements);

	/*release the entire block of memory starting from the address stored in iptr*/
	free(iptr);
	iptr = nullptr;

}

void realloc_demo() {
	size_t number_of_elements{};
	std::cout << "How many integers do you want to store ? ";
	std::cin >> number_of_elements;

	int* ptr = reinterpret_cast<int*>(malloc(sizeof(int) * number_of_elements));

	if (ptr == nullptr) {
		std::cerr << "Insufficient memory!";
		std::exit(EXIT_FAILURE);
	}
	std::cout << "Memory has been successfully allocated at address "
		<< std::hex << std::showbase
		<< reinterpret_cast<unsigned long long>(ptr)
		<< std::dec << std::noshowbase << std::endl;

	store_values(ptr, number_of_elements);
	print_array(ptr, number_of_elements);

	std::cout << "How many more integers do you want to store ? ";
	size_t additional_elements;
	std::cin >> additional_elements;

	unsigned int new_size = number_of_elements + additional_elements;

	//ptr = reinterpret_cast<int*>(malloc(sizeof(int) * new_size));

	ptr = reinterpret_cast<int*>(realloc(ptr, sizeof(int) * new_size));
	if (ptr == nullptr) {
		std::cerr << "Insufficient memory!";
		std::exit(EXIT_FAILURE);
	}

	std::cout << "Memory has been successfully allocated at address "
		<< std::hex << std::showbase
		<< reinterpret_cast<unsigned long long>(ptr)
		<< std::dec << std::noshowbase << std::endl;

	print_array(ptr, new_size);

	free(ptr);
	ptr = nullptr; //handle dangling pointer

}


struct Product {
	char name[1000];
	float price;
	float weight;

	Product() { //ctor default
		memset(name, '\0', 1000); //Sets the first num bytes of the block of memory pointed by name(pointer) to the specified value
		price = 0.0f;
		weight = 0.0f;
	}

	//parameterized ctor
	Product(const char* _name, float _price, float _weight) { //ctor
		strcpy_s(name, _name);
		price = _price;
		weight = _weight;
	}

	void print_product() {
		std::cout << "Name : " << name << "\t"
			<< "Price : " << price << "\t"
			<< "Weight :" << weight << std::endl;
	}

	~Product() { //dtor
		memset(name, '\0', 1000); //Sets the first num bytes of the block of memory pointed by name(pointer) to the specified value
		price = 0.0f;
		weight = 0.0f;
	}
};

void drawback_std_mem_fun() {
	//automatic memory mgmt for objects
	{
		Product p1;
		p1.print_product();

		/*Ctor can be used ot initialized the object*/
		Product p2("Marker Pen", 125.0F, 30.5);
		p2.print_product();
	}

	//dynamic memory management for objects
	{
		Product* product_ptr = nullptr;
		/*Allocates memory large enough to accomodate the product
		 But does not create product object
		 We can force the block of memory to be treated as Product object */
		product_ptr = reinterpret_cast<Product*>(malloc(sizeof(Product)));

		product_ptr->print_product();

		strcpy_s(product_ptr->name, "Pen");
		product_ptr->price = 55.50F;
		product_ptr->weight = 45.0F;
		product_ptr->print_product();

		/*Releases the memory block pointed to by the pointer argument. Now the memory can be resuled for athoer allocation
		Doenot clear the memory. Pervious data remains as garbage
		Destructor is not called even if the memory was holding a object
		*/
		free(product_ptr);
		product_ptr = nullptr;
	}
}

int main()
{
	malloc_demo1();
	malloc_demo2();
	malloc_demo3();
	calloc_demo();
	realloc_demo();

	drawback_std_mem_fun();
}
