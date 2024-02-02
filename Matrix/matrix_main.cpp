#include <iostream>

class Matrix {
private:
	int n_size, m_size;
	int** elem;
public:
	//Конструктор
	Matrix(int n, int m) {
		n_size = n;
		m_size = m;
		elem = new int* [n];
		for (int i = 0; i < n; i++) {
			elem[i] = new int[m];
		}
	}

	//Конструктор копирования Matrix B = A;
	Matrix(const Matrix& other) {
		n_size = other.n_size;
		m_size = other.m_size;
		elem = new int* [n_size];
		for (int i = 0; i < n_size; i++) {
			elem[i] = new int[m_size];
		}

		for (int i = 0; i < n_size; i++) {
			for (int j = 0; j < m_size; j++) {
				elem[i][j] = other.elem[i][j];
			}
		}
	}

	//Оператор присваивания копированием
	Matrix& operator=(const Matrix& other) {
		for (int i = 0; i < n_size; i++) {
			delete[] elem[i];
		}
		delete[] elem;

		n_size = other.n_size;
		m_size = other.m_size;
		elem = new int* [n_size];
		for (int i = 0; i < n_size; i++) {
			elem[i] = new int[m_size];
		}

		for (int i = 0; i < n_size; i++) {
			for (int j = 0; j < m_size; j++) {
				elem[i][j] = other.elem[i][j];
			}
		}
		return *this;
	}

	//Деструктор
	~Matrix(){
		for (int i = 0; i < n_size; i++) {
			delete[] elem[i];
		}
		delete[] elem;
	}
};

int main()
{

	return 0;
}