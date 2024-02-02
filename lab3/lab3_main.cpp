#include <iostream>

class MyString
{
	int len;
	char* str;
public:
	//�����������
	MyString(int l) {
		len = l;
		str = new char [len];
	}

	//����������� �����������
	MyString(const MyString& other) {
		len = other.len;
		str = new char [len];
	}

	//�������� ������������ ������������
	MyString& operator=(const MyString& other) {
		len = other.len;
		delete[] str;
		str = new char [len];
		return *this;
	}
	/*
	//�������� +
	MyString& operator+(const MyString& other) {
		len += other.len;
	}
	*/
	//����������
	~MyString() {
		delete[] str;
	}
};

int main()
{
	MyString a(5);
	return 0;
}