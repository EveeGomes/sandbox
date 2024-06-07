#ifndef MATRIX_H
#define MATRIX_H

template <class T>
class Matrix
{
private:
   int m_Rows;
   int m_Cols;
   T* m_MatrixPtr;

public:
   Matrix(int Rows, int Cols)
   {
      m_Rows = Rows;
      m_Cols = Cols;

      m_MatrixPtr = new T[m_Rows * m_Cols];
   }

   Matrix(int Size)
   {
      m_Rows = Size;
      m_Cols = Size;

      m_MatrixPtr = new T[m_Rows * m_Cols];
   }

   // Copy constructor
   Matrix(const Matrix& OtherMatrix)
   {
      m_Rows = OtherMatrix.m_Rows;
      m_Cols = OtherMatrix.m_Cols;

      // Deep copy
      // Set the pointer
      m_MatrixPtr = new T[m_Rows * m_Cols];

      // Copy the content from OtherMatrix matrix, to the current object matrix
      for (int i = 0; i < m_Rows * m_Cols; i++)
      {
         m_MatrixPtr[i] = OtherMatrix.m_MatrixPtr[i];
      }
   }

   ~Matrix()
   {
      delete[] m_MatrixPtr;
   }
};

#endif // !MATRIX_H