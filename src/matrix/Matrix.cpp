#include "Matrix.h"

Matrix::Matrix() : m_rows(0), m_cols(0) {}

Matrix::Matrix(int p_rows, int p_cols) : m_rows(p_rows), m_cols(p_cols) {
    m_data.resize(p_rows);
    for (int i = 0; i < p_rows; ++i) {
        m_data[i].resize(p_cols);
    }
}

Matrix::Matrix(int p_rows, int p_cols, std::vector<std::vector<double>> p_data) 
    : m_rows(p_rows), m_cols(p_cols), m_data(p_data) {}

// Assignment Operator
Matrix& Matrix::operator=(const Matrix& p_other) {
    if (this == &p_other) {
        return *this;
    }

    m_rows = p_other.get_rows();
    m_cols = p_other.get_cols();
    m_data = p_other.get_data();

    return *this;
}

// Element Access
double& Matrix::operator()(int p_row, int p_col) {
    return m_data[p_row][p_col];
}

const double& Matrix::operator()(int p_row, int p_col) const {
    return m_data[p_row][p_col];
}

// Matrix Operations
Matrix Matrix::operator+(const Matrix& p_other) const {
    if (m_rows != p_other.get_rows() || m_cols != p_other.get_cols()) {
        throw std::invalid_argument("Matrices must be of the same size to add them.");  
    }

    Matrix result(m_rows, m_cols);
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            result(row, col) = m_data[row][col] + p_other(row, col);
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& p_other) const {
    if (m_rows != p_other.get_rows() || m_cols != p_other.get_cols()) {
        throw std::invalid_argument("Matrices must be of the same size to subtract them.");  
    }

    Matrix result(m_rows, m_cols);
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            result(row, col) = m_data[row][col] - p_other(row, col);
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& p_other) const {
    if (m_cols != p_other.get_rows()) {
        throw std::invalid_argument("Matrices must have compatible dimensions for multiplication.");
    }

    Matrix result(m_rows, p_other.get_cols());
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < p_other.get_cols(); ++col) {
            result(row, col) = 0;
            for (int k = 0; k < m_cols; ++k) {
                result(row, col) += m_data[row][k] * p_other(k, col);
            }
        }
    }

    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(m_cols, m_rows);
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            result(col, row) = m_data[row][col];
        }
    }

    return result;
}

/**
 * @brief Perform element-wise multiplication (dot product) of two matrices.
 * @param p_other Matrix to multiply with.
 * @return Resulting matrix after element-wise multiplication.
 * @throws std::invalid_argument if matrices are not of the same size.
 */
Matrix Matrix::dot_product(const Matrix& p_other) const {
    if (m_rows != p_other.get_rows() || m_cols != p_other.get_cols()) {
        throw std::invalid_argument("Matrices must be of the same size for element-wise multiplication.");
    }

    Matrix result(m_rows, m_cols);
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            result(row, col) = m_data[row][col] * p_other(row, col);
        }
    }

    return result;
}

// Utility Functions
int Matrix::get_rows() const {
    return m_rows;
}

int Matrix::get_cols() const {
    return m_cols;
}


std::vector<std::vector<double>> Matrix::get_data() const {
    return m_data;
}

/**
 * @brief Print the matrix to the console.
 */
void Matrix::print() {
    for (int row = 0; row < m_rows; ++row) {
        for (int col = 0; col < m_cols; ++col) {
            std::cout << m_data[row][col] << " ";
        }
        std::cout << std::endl;
    }
}  