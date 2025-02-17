#include <iostream>

class Matrix {

private:
	int n_size, m_size;
	int** elem;
	void constr_func(Matrix& mat, int n, int m) {
		mat.n_size = n;
		mat.m_size = m;
		mat.elem = new int* [n_size];
		for (int i = 0; i < n_size; i++) {
			mat.elem[i] = new int[m_size];
		}
	}

	void constr_func(Matrix& mat1, const Matrix& mat2) {
		constr_func(mat1, mat2.n_size, mat2.m_size);
	}

	void copy_func(Matrix& mat1, const Matrix& mat2) {
		for (int i = 0; i < mat1.n_size; i++) {
			for (int j = 0; j < mat1.m_size; j++) {
				mat1.elem[i][j] = mat2.elem[i][j];
			}
		}
	}

	void destr_func(Matrix& mat) {
		for (int i = 0; i < mat.n_size; i++) {
			delete[] mat.elem[i];
		}
		delete[] mat.elem;
	}

public:
	//Конструктор
	Matrix(int n, int m) {
		constr_func(*this, n, m);
	}

	//Конструктор копирования
	Matrix(const Matrix& other){
		constr_func(*this, other);
		copy_func(*this, other);
	}

	//Оператор присваивания копирования
	Matrix& operator = (const Matrix& other){
		destr_func(*this);
		constr_func(*this, other);
		copy_func(*this, other);
		return *this;
	}

	//Деструктор
	~Matrix(){
		destr_func(*this);
	}

	//Оператор ввода в поток
	friend std::istream& operator >> (std::istream& in, Matrix& mat);

	//Оператор вывода в поток
	friend std::ostream& operator << (std::ostream& out, Matrix& mat);
};

std::istream& operator >> (std::istream& in, Matrix& mat) {
	for (int i = 0; i < mat.n_size; i++) {
		for (int j = 0; j < mat.m_size; j++) {
			in >> mat.elem[i][j];
		}
	}
	return in;
}

std::ostream& operator << (std::ostream& out, Matrix& mat) {
	for (int i = 0; i < mat.n_size; i++) {
		for (int j = 0; j < mat.m_size; j++) {
			out << mat.elem[i][j] << " ";
		}
		out << std::endl;
	}
	return out;
}

int main()
{
	return 0;
}