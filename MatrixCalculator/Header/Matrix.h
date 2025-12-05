#pragma once

//  Matrix.h
//  Created by Andreas Falkenberg on 10/1/18.
//  Copyright (c) 2018 Andreas Falkenberg. All rights reserved.
//
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.

//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

/* The Matrix Calculation Classes perform some matrix algoithms. 
   Besides elementwise operations like + and - also the following are implemented: 

   Matrix multiplication with a float
   Matrix multiplication with another Matrix
   Matrix Inversion 1/M or M/N 
   Determinant
   adj
   cof
   trans
   submatrix 
   Symmetrie Test 
   Cholesky Decomposition
*/

#include <iostream>

class Mat
{

public:
	
	int   N = 2; 

	float** m; //  [2][2];

	 
	Mat();
	~Mat(); 

	Mat(int s);

	Mat copy();

	Mat operator* (float f);   // M * 1.2
	friend Mat operator* (float f, Mat rhs);  // 1.2 * M 

	Mat operator* (Mat f);   // M * M 
	Mat operator+ (Mat f);   // M + M 
	Mat operator- (Mat f);   // M - M 

	friend Mat operator/ (float f, Mat rhs);   // 1.2 / M which is Mat inversion 


	Mat operator/ (Mat f);    // M / M         // need Mat inversion first 


	float det();   // determinante 
	Mat  adj();
	Mat  cof();
	Mat  trans();
	Mat  subMatrix(int i, int j); // select a N-1 matrix without the provided row and columns 

	// cholesky decomposition
	bool testSymmetry(); 
	Mat  cholesky();  

	friend std::ostream& operator<< (std::ostream &os, const Mat &v);



};

