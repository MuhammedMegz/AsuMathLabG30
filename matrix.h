//=================================
// include guard
#ifndef __MATRIX_H_INCLUDED__
#define __MATRIX_H_INCLUDED__

//=================================
// included dependencies
#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;


class CMatrix {
	int nR , nC ;
	double ** values ;
	string name;

public :
	// constructors and destructors
	CMatrix () ;
	CMatrix (int nR , int nC) ;
	void reset ();
	~CMatrix () ;
	CMatrix(string s);
	CMatrix(double d);
	CMatrix(const CMatrix& m);
	//functions
	void copy(const CMatrix& m);
	void copy(double d);
	void copy(string s);
	void addColumn(CMatrix& m);
	void addRow(CMatrix& m);
	void setSubMatrix(int iR, int iC, CMatrix& m);
	void add(const CMatrix& m);
	void sub(const CMatrix& m);
	void mul(const CMatrix& m);
	void set_name(string n);
	string get_name();
	void PrintMatrix();
	void transpose(const CMatrix &m);
	void dotSlash(int num);
	CMatrix getCofactor(int r, int c);
	double getDeterminant();
	CMatrix getInverse();
	CMatrix getAdjoint(const CMatrix &m);

	//operators
	CMatrix operator=(const CMatrix& m);
	CMatrix operator=(double d);
	void operator+=(const CMatrix& m);
	CMatrix operator+(const CMatrix& m);
	void operator-=(const CMatrix& m);
	CMatrix operator-(const CMatrix& m);
	void operator*=(const CMatrix& m);
	CMatrix operator*(const CMatrix& m);
	CMatrix operator/(const CMatrix& m);
	void operator/=(const CMatrix& m);
    
    // Trigonometric functions (sin ,cos ,tan ,sinh ,cosh ,tanh ,sin^-1 ,cos^-1 ,tan^-1 ,sinh^-1 ,cosh^-1 ,tanh^-1);
    static CMatrix sin(CMatrix &M);  //sin
    static CMatrix cos(CMatrix &M);  //cos
    static CMatrix tan(CMatrix &M);  //tan
    static CMatrix sinInv(CMatrix &M);  //asin2
    static CMatrix cosInv(CMatrix &M);  //acos2
    static CMatrix tanInv(CMatrix &M);  //atan2
    static CMatrix cosh(CMatrix &M);    //cosh
    static CMatrix sinh(CMatrix &M);    //sinh
    static CMatrix tanh(CMatrix &M);    //tanh
    static CMatrix coshInv(CMatrix &M);   //acosh
    static CMatrix sinhInv(CMatrix &M);   //asinh
    static CMatrix tanhInv(CMatrix &M);   //atanh
    
};
#endif
