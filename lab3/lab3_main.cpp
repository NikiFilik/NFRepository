#include <iostream>

int char_arr_size(const char* array) {
	int i = 0;
	while (array[i] != '\0') {
		i++;
	}
	return i;
}

class MyString
{
private:
	int len;
	char* str;
public:
	//����������� �������
	MyString() {
		len = 1;
		str = new char[len];
		str[0] = '\0';
	}
	
	//������������ �����������
	MyString(const MyString& other) {
		len = other.len;
		str = new char[len];
		for (int i = 0; i < len; i++) {
			str[i] = other.str[i];
		}
	}

	MyString(const char* array) {
		len = char_arr_size(array) + 1;
		str = new char[len];
		for (int i = 0; i < len; i++) {
			str[i] = array[i];
		}
	}
	
	//��������� ������������ ������������
	MyString& operator=(const MyString& other) {
		delete[] str;
		len = other.len;
		str = new char[len];
		for (int i = 0; i < len; i++) {
			str[i] = other.str[i];
		}
		return *this;
	}

	MyString& operator=(const char* array) {
		delete[] str;
		len = char_arr_size(array) + 1;
		str = new char[len];
		for (int i = 0; i < len; i++) {
			str[i] = array[i];
		}
		return *this;
	}

	//����������
	~MyString() {
		delete[] str;
	}

	//�������� ����� � �����
	friend std::istream& operator>>(std::istream& in, MyString& other);

	//�������� ������ � �����
	friend std::ostream& operator<<(std::ostream& out, const MyString& other);

	//��������� +
	MyString operator+(const MyString& other) {
		MyString sum;
		sum.len = len + other.len - 1;
		delete[] sum.str;
		sum.str = new char[sum.len];
		for (int i = 0; i < len - 1; i++) {
			sum.str[i] = str[i];
		}
		for (int i = len - 1; i < sum.len; i++) {
			sum.str[i] = other.str[i - len + 1];
		}
		return sum;
	}

	MyString operator+(const char* array) {
		MyString sum;
		sum.len = len + char_arr_size(array);
		delete[] sum.str;
		sum.str = new char[sum.len];
		for (int i = 0; i < len - 1; i++) {
			sum.str[i] = str[i];
		}
		for (int i = len - 1; i < sum.len; i++) {
			sum.str[i] = array[i - len + 1];
		}
		return sum;
	}

	//O�������� +=
	void operator+=(const MyString other) {
		MyString sum;
		sum.len = len + other.len - 1;
		delete[] sum.str;
		sum.str = new char[sum.len];
		for (int i = 0; i < len - 1; i++) {
			sum.str[i] = str[i];
		}
		for (int i = len - 1; i < sum.len; i++) {
			sum.str[i] = other.str[i - len + 1];
		}
		*this = sum;
	}

	void operator+=(const char* array) {
		MyString sum;
		sum.len = len + char_arr_size(array);
		delete[] sum.str;
		sum.str = new char[sum.len];
		for (int i = 0; i < len - 1; i++) {
			sum.str[i] = str[i];
		}
		for (int i = len - 1; i < sum.len; i++) {
			sum.str[i] = array[i - len + 1];
		}
		*this = sum;
	}
};

//������� ��������� ����� � �����
std::istream& operator>>(std::istream& in, MyString& other) {
	char array[1000];
	in >> array;
	delete[] other.str;
	other.len = char_arr_size(array) + 1;
	other.str = new char[other.len];
	for (int i = 0; i < other.len; i++) {
		other.str[i] = array[i];
	}
	return in;
}
//������� ��������� ������ � �����
std::ostream& operator<<(std::ostream& out, const MyString& other) {
	out << other.str;
	return out;
}

int main()
{
	MyString a = "ABC", b = "XYZ";
	MyString c;
	a += b;
	a = a + "ajfsegf";
	std::cout << a <<std::endl;
	std::cin >> a;
	std::cout << a;
	return 0;
}