#include <iostream>
#include <vector>

class Matrix {
private:
    int m_rows;
    int m_cols;
    std::vector<std::vector<double>> m_data;

public:
    Matrix();
    Matrix(int p_rows, int p_cols);
    Matrix(int p_rows, int p_cols, std::vector<std::vector<double>> p_data);

    // Assignment Operator
    Matrix& operator=(const Matrix& p_other);

    // Element Access
    double& operator()(int p_row, int p_col);
    const double& operator()(int p_row, int p_col) const;

    // Matrix Operations
    Matrix operator+(const Matrix& p_other) const;
    Matrix operator-(const Matrix& p_other) const;
    Matrix operator*(const Matrix& p_other) const;
    
    Matrix transpose() const;

    // Utility Functions
    int get_rows() const;
    int get_cols() const;
    std::vector<std::vector<double>> get_data() const;

    void print();  
};
