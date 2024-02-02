#include <iostream>

class MyString
{
	int len;
	char* str;
public:
	//Конструктор
	MyString(int l) {
		len = l;
		str = new char [len];
	}

	//Конструктор копирования
	MyString(const MyString& other) {
		len = other.len;
		str = new char [len];
	}

	//Оператор присваивания копированием
	MyString& operator=(const MyString& other) {
		len = other.len;
		delete[] str;
		str = new char [len];
		return *this;
	}
	/*
	//Оператор +
	MyString& operator+(const MyString& other) {
		len += other.len;
	}
	*/
	//Деструктор
	~MyString() {
		delete[] str;
	}
};

int main()
{
	MyString a(5);
	return 0;
}