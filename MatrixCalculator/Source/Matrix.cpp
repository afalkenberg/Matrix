
//  Matrix.cpp
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

#include "Matrix.h"

#include <iostream>
#include <math.h>

Mat::Mat(void)
{
	N = 2;

	m = new float*[N];
	for (int i = 0; i < N; i++) {
		m[i] = new float[N];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = 0.0;
		}
	}
}


Mat::~Mat() {
	//for (int i = 0; i < N; i++)
	//{
	//	delete m[i]; 
	//}
	//delete m; 
}

Mat::Mat(int s) {
	N = s; 
	m = new float*[N];
	for (int i = 0; i < N; i++) {
		m[i] = new float[N]; 
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m[i][j] = 0.0;
		}
	}
};

Mat Mat::copy() {
	Mat x(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			x.m[i][j] = m[i][j];
		}
	}
	return x;
}

Mat  Mat::operator+ (Mat f) {
	Mat x(N);

	for (int i = 0; i < N; i++)  // row left Mat 
	{
		for (int j = 0; j < N; j++)  // column right Mat
		{
			x.m[i][j] = m[i][j] + f.m[i][j];
		}
	}

	return x;
}


Mat  Mat::operator- (Mat f)
{
	Mat x(N);

	for (int i = 0; i < N; i++)  // row left Mat 
	{
		for (int j = 0; j < N; j++)  // column right Mat
		{
			x.m[i][j] = m[i][j] - f.m[i][j];
		}
	}

	return x;
}


Mat Mat::operator* (const float f)
{

	Mat x(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			x.m[i][j] = m[i][j] * f;
		}
	}

	return x;

};


Mat  Mat::operator* (Mat f)
{
	Mat x(N);

	for (int i = 0; i < N; i++)  // row left Mat 
	{
		for (int j = 0; j < N; j++)  // column right Mat
		{
			float hlp = 0.0;
			for (int k = 0; k < N; k++)  // column in left Mat // row in right Mat 
			{
				hlp = hlp + m[i][k] * f.m[k][j];
			}
			x.m[i][j] = hlp;
		}
	}



	return x;
}


Mat operator* (float f, Mat rhs)
{
	Mat x(rhs.N);
	x = rhs * f;
	return x;
}


Mat operator/ (float f, Mat rhs)
{


	Mat x(rhs.N);

	Mat ad(rhs.N); 
	

	if (rhs.N == 1)
	{
		x.m[0][0] = f / rhs.m[0][0]; 
		 
	}

	else
	{
		ad = rhs.adj();

		x = (f / rhs.det()) * ad;

		
	}

	return x;
}



Mat Mat::operator/ (Mat rhs)
{

	Mat x(N);
	Mat lhs(N);

	lhs = copy(); 

	Mat res(N);

	x = 1 / rhs;
	res = lhs * x;

	return res;
}


Mat Mat::subMatrix(int x, int y)
{
	Mat res(N - 1); 

	int cntx = 0; 
	int cnty = 0; 

	for (int i = 0; i < N; i++)
	{

		cnty = 0; 
		if (i != x)
		{
			
			for (int j = 0; j < N; j++)
			{
				if (j != y)
				{
					
					res.m[cntx][cnty] = m[i][j];
					cnty++;
				}

			}
			cntx++;
		}
	}

	return res; 

}


float Mat::det()
{


	if (N == 2)
	{
		float x; 
		x =  m[0][0] * m[1][1] - m[1][0] * m[0][1];

		return x; 
	}
	else
	{

		float res = 0.0; 
		for (int j = 0; j < N; j++)
		{
			Mat S ; 
			S = subMatrix(0, j); 

			float sign = -(2.0 * (j % 2) - 1.0);
			float d = subMatrix(0, j).det(); 

			res = sign * m[0][j] * d + res ;
		}

		return res;

	}

	
}





Mat  Mat::cof()
{
	Mat res(N);
	if (N == 2)
	{
		res.m[0][0] = m[1][1];
		res.m[0][1] = -m[1][0];
		res.m[1][0] = -m[0][1];
		res.m[1][1] = m[0][0];
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				float sign = -(2 * ((i + j) % 2) - 1); 
				
				Mat S;
				S = subMatrix(i, j);
				float d = S.det(); 

				res.m[i][j] = sign * d; 

		
			}
		}


	}


	return res;
}


Mat  Mat::trans()
{
	Mat res(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			res.m[j][i] = m[i][j];
		}
	}

	return res;
}

Mat  Mat::adj()
{
	Mat a(N);
	Mat res(N);
	a = copy();

	res = a.cof().trans();

	return res;
}



bool Mat::testSymmetry()
{

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (m[i][j] != m[j][i])
			{
				return false; 
			}
		}
	}

	return true; 
}


Mat Mat::cholesky()
{


	if (N == 1)
	{
		Mat res(1);
		res.m[0][0] = sqrt(m[0][0]);
		return res; 
	}
	else
	{

		Mat res(N); 

		std::cout << "in Mat" << std::endl;
		std::cout << *this << std::endl; 


		//result matrices L11 .. L22 
		Mat L11(N / 2); 
		Mat L21(N / 2); 
		Mat L22(N / 2); 
		Mat L12(N / 2); // zero matrix 


		// copy of this matrix 
		Mat A11(N / 2); 
		Mat A21(N / 2); 
		Mat A22(N / 2); 
		Mat A22d(N / 2); 

		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				A11.m[i][j] = m[i][j];
				A21.m[i][j] = m[i + N / 2][j];
				A22.m[i][j] = m[i + N / 2][j + N / 2];
			}
		}


		std::cout << "A11" << std::endl;
		std::cout << A11 << std::endl;
		std::cout << "A21" << std::endl;
		std::cout << A21 << std::endl;
		std::cout << "A22" << std::endl;
		std::cout << A22 << std::endl;

		L11  = A11.cholesky(); 
     
		std::cout << "L11" << std::endl;
		std::cout << L11 << std::endl;


		L21  = A21 / L11.trans(); 

		std::cout << "L21 = A21 / L11.trans()" << std::endl;
		std::cout << A21 / L11.trans() << std::endl;


		A22d = A22 - L21 * L21.trans(); 
		
		std::cout << "A22d" << std::endl;
		std::cout << A22d   << std::endl;


		
		L22 = A22d.cholesky(); 



		for (int i = 0; i < N / 2; i++)
		{
			for (int j = 0; j < N / 2; j++)
			{
				res.m[i][j]                  = L11.m[i][j];
				res.m[i + N / 2][j]          = L21.m[i][j];
				res.m[i + N / 2][j + N / 2]  = L22.m[i][j];
			}
		}

		return res; 

	}



}




std::ostream& operator << (std::ostream &os, const Mat &v)
{

	for (int i = 0; i < v.N; i++)
	{
		os << "[" << v.m[i][0] ; 
		for (int j = 1; j < v.N; j++)
		{
			os << " " << v.m[i][j]; 
		}
		os << "] \n";

	}

	return os;
};


