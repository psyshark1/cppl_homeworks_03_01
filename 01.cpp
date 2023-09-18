#include <iostream>

class smart_array
{
public:
	smart_array(const int& len);
	~smart_array();
	void add_element(const int& number);
	int get_element(const int& number);
private:
	int* arr{ nullptr };
	int arr_length{ 0 };
	void delete_arr();
};

int main(int argc, char** argv)
{
	try {
		smart_array arr(2);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	std::system("pause");
	return 0;
}


smart_array::smart_array(const int& len)
{
	if (len < 1) { throw std::exception("Некорректный размер элемента массива!"); }
	arr_length = len;
	this->arr = new int[arr_length] {0};
}

void smart_array::add_element(const int& number)
{
	if (number < 1) { throw std::exception("Некорректный размер элемента массива!"); }
	if (number <= arr_length) { throw std::exception("Такой элемент массива уже существует!"); }
	delete_arr();
	this->arr = new int[number] {0};
}

int smart_array::get_element(const int& number)
{
	if (number < 1 && number > arr_length) { throw std::exception("Некорректный размер элемента массива!"); }
	return arr[number];
}

void smart_array::delete_arr()
{
	if (arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
	}
}

smart_array::~smart_array()
{
	delete_arr();
}