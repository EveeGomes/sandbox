#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

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
      (*this) = OtherMatrix; // calling the assignment operator since it has the same implementation as the below:
      
      //m_Rows = OtherMatrix.m_Rows;
      //m_Cols = OtherMatrix.m_Cols;

      //// Deep copy
      //// Set the pointer
      //m_MatrixPtr = new T[m_Rows * m_Cols];

      //// Copy the content from OtherMatrix matrix, to the current object matrix
      //for (int i = 0; i < m_Rows * m_Cols; i++)
      //{
      //   m_MatrixPtr[i] = OtherMatrix.m_MatrixPtr[i];
      //}
   }

   ~Matrix()
   {
      delete[] m_MatrixPtr;
   }

   Matrix& operator= (const Matrix& OtherMatrix)
   {
      if (this)
      {
         this->~Matrix();
      }
      
      m_Rows = OtherMatrix.m_Rows;
      m_Cols = OtherMatrix.m_Cols;

      m_MatrixPtr = new T[m_Rows * m_Cols];

      for (int i = 0; i < m_Rows * m_Cols; i++)
      {
         m_MatrixPtr[i] = OtherMatrix.m_MatrixPtr[i];
      }
      return *this;
   }

   /** Friend functions */
   template <typename U>
   friend std::istream& operator>> (std::istream& is, Matrix<U>& MatrixObj);

   template <typename U>
   friend std::ostream& operator<< (std::ostream& os, const Matrix<U>& MatrixObj);

   template <typename U>
   friend std::ifstream& operator>> (std::ifstream& ifs, Matrix<U>& MatrixObj);

   template <typename U>
   friend std::ofstream& operator<< (std::ofstream& ofs, const Matrix<U>& MatrixObj);
};

template <typename T>
std::istream& operator>> (std::istream& is, Matrix<T>& MatrixObj)
{
   for (int i = 0; i < MatrixObj.m_Rows * MatrixObj.m_Cols; i++) // as a friend it can have access to private members
   {
      is >> MatrixObj.m_MatrixPtr[i];
   }

   return is;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const Matrix<T>& MatrixObj)
{
   for (int i = 0; i < MatrixObj.m_Rows; i++)
   {
      for (int j = 0; j < MatrixObj.m_Cols; j++)
      {
         os << MatrixObj.m_MatrixPtr[i * MatrixObj.m_Cols + j] << " "; // incorrect: m_MatrixPtr[i][j] // he used [i * MatrixObj.m_Cols + j] ?????? -> becausae m_MatrixPtr is allocated as a single-dimensional array, not a two-dimensional array!!!!
                                                                       // so, to access the elements we need to convert the two-dimensional indices (i and j) into a single-dimensional index!!!!
      }
      os << " \n";
   }

   return os;
}

template <typename T>
std::ifstream& operator>> (std::ifstream& ifs, Matrix<T>& MatrixObj)
{
   for (int i = 0; i < MatrixObj.m_Rows * MatrixObj.m_Cols; i++)
   {
      ifs >> MatrixObj.m_MatrixPtr[i];
   }
   return ifs;
}

template <typename T>
std::ofstream& operator<< (std::ofstream& ofs, const Matrix<T>& MatrixObj)
{
   for (int i = 0; i < MatrixObj.m_Rows; i++)
   {
      for (int j = 0; j < MatrixObj.m_Cols; j++)
      {
         ofs << MatrixObj.m_MatrixPtr[i * MatrixObj.m_Rows + j] << " ";
      }
      ofs << "\n";
   }
   return ofs;
}

#endif // !MATRIX_H