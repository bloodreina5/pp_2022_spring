// Copyright 2022 Podovinnikov Artyom
#ifndef MODULES_TASK_1_PODOVINNIKOV_A_CRS_MATRIX_MULTIPLICATION_SPARSEMATRIX_H_
#define MODULES_TASK_1_PODOVINNIKOV_A_CRS_MATRIX_MULTIPLICATION_SPARSEMATRIX_H_

#include <complex>
#include <vector>

class SparseMatrix {
 public:
  explicit SparseMatrix(int _size = 0);
  SparseMatrix(const SparseMatrix& a);
  SparseMatrix(const std::vector<std::complex<double>>& a, int _size);
  ~SparseMatrix() = default;
  SparseMatrix& operator=(const SparseMatrix& a);
  SparseMatrix operator*(const SparseMatrix& a);
  std::vector<std::complex<double>> getValues() const;
  std::vector<int> getCols() const;
  std::vector<int> getPointers() const;
  int getSize() const;
  void setSize(const int size);
  void setValues(const std::vector<std::complex<double>>& val);
  void setCols(const std::vector<int>& col);
  void setPointers(const std::vector<int>& pointers);
  std::vector<std::complex<double>> getDenseMatrix() const;
  SparseMatrix transposition() const;

 private:
  int size;
  std::vector<std::complex<double>> values;
  std::vector<int> cols, pointers;
};

SparseMatrix generateRandomSparseMatrix(const int size,
                                        const int nonZeroElementsInEveryRow);
std::vector<std::complex<double>> stupidDenseMultiplication(
    const std::vector<std::complex<double>>& a,
    const std::vector<std::complex<double>>& b, const int size);
#endif  // MODULES_TASK_1_PODOVINNIKOV_A_CRS_MATRIX_MULTIPLICATION_SPARSEMATRIX_H_