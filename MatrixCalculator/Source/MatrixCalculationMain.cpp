
//  MatrixCalculationMain.cpp
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


// MatrixCalculation.cpp : Defines the entry point for the console application.
// The following is just some example code to check the Matrix operations out 


#include "Matrix.h"
#include "Determinante.h"

#include <iostream>

#include <fstream>


//

//namespace std 
//{
int main()
{
	int bla;

	// define a 4x4 Matrix using the Determinante Implementation // 
	Det dd(4); 
    
	
	dd.m[0][0] = 0.7f;
	dd.m[0][1] = 0.4529f;
	dd.m[0][2] = 0.2f;
	dd.m[0][3] = 0.5256f;

	dd.m[1][0] = 0.0f;
	dd.m[1][1] = 1.2778f;
	dd.m[1][2] = 4.0f;
	dd.m[1][3] = 0.3f;

	dd.m[2][0] = 0.2930f;
	dd.m[2][1] = 0.0f;
	dd.m[2][2] = 1.3f;
	dd.m[2][3] = 0.1762f;

	dd.m[3][0] = 0.5256f;
	dd.m[3][1] = 0.7f;
	dd.m[3][2] = 0.1762f;
	dd.m[3][3] = 0.2f;


	std::cout << "slow determinat  "  << dd.det() << std::endl; 
	std::cout << "matrix           "  << dd       << std::endl;

	std::cout << "fast determinant "  << dd.determinant() << std::endl; 

	std::cout << "countZerosInColumn 0 :: " << dd.countZerosInColumn(0) << std::endl;
	std::cout << "countZerosInColumn 1 :: " << dd.countZerosInColumn(1) << std::endl;
	std::cout << "countZerosInColumn 2 :: " << dd.countZerosInColumn(2) << std::endl;
	std::cout << "countZerosInColumn 3 :: " << dd.countZerosInColumn(3) << std::endl;

	std::cout << "countZerosInRow 0 :: " << dd.countZerosInRow(0) << std::endl;
	std::cout << "countZerosInRow 1 :: " << dd.countZerosInRow(1) << std::endl;
	std::cout << "countZerosInRow 2 :: " << dd.countZerosInRow(2) << std::endl;
	std::cout << "countZerosInRow 3 :: " << dd.countZerosInRow(3) << std::endl;


	std::cout << dd << std::endl; 

	

	std::cout << dd.sortRow() << std::endl; 
    std::cout << "after row sort " << dd << std::endl; 

	std::cout << dd.sortColumn() << std::endl;
	std::cout << dd << std::endl;

	dd.subtractMultiple(0, 1, 0);
	std::cout << dd << std::endl;

	dd.subtractMultiple(0, 2, 0);
	std::cout << dd << std::endl;

	dd.subtractMultiple(0, 3, 0);
	std::cout << dd << std::endl;


	dd.subtractMultiple(1, 2, 1);
	std::cout << dd << std::endl;

	dd.subtractMultiple(1, 3, 1);
	std::cout << dd << std::endl;


	dd.subtractMultiple(2, 3, 2);
	std::cout << dd << std::endl;

    std::cout << "result " << dd.multiplyDiagonal() << std::endl; 




	std::cin >> bla;


	Mat one(1);
	one.m[0][0] = 7; 
	std::cout << one << std::endl; 
	std::cout << 1 / one << std::endl; 
	std::cout << one / one << std::endl; 




	Mat x(4);

	Det y;
	x.m[0][0] = 1.1701;
	x.m[0][1] = 0.4529;
	x.m[0][2] = 0.2930;
	x.m[0][3] = 0.5256;

	x.m[1][0] = 0.4529;
	x.m[1][1] = 1.2778;
	x.m[1][2] = 0.2288;
	x.m[1][3] = -0.0120;

	x.m[2][0] = 0.2930;
	x.m[2][1] = 0.2288;
	x.m[2][2] = 1.4476;
	x.m[2][3] = 0.1762;

	x.m[3][0] = 0.5256; 
	x.m[3][1] = -0.0120;
	x.m[3][2] = 0.1762;
	x.m[3][3] = 0.9277;






	y.m[0][0] = 3;
	y.m[0][1] = 2;
	y.m[1][0] = 2;
	y.m[1][1] = 7;

	std::cout <<  "x "  << x.testSymmetry() << std::endl; 
	
	std::cout <<  "y "  << y.testSymmetry() << std::endl;

	std::cout << x.cholesky() << std::endl;
	
	std::cout << y.cholesky() << std::endl;

	std::cout << "---invese of x --" << std::endl;

	std::cout << x << std::endl;
	std::cout << 1.0 / x << std::endl;;

	std::cout << x / x;


	std::cin >> bla;


	Mat z(5);
	z.m[0][0] = 2;
	z.m[0][1] = 2;
	z.m[0][2] = 3;
	z.m[0][3] = 4;
	z.m[0][4] = 1;


	z.m[1][0] = 1;
	z.m[1][1] = 4;
	z.m[1][2] = 5;
	z.m[1][3] = 6;
	z.m[1][4] = 1;


	z.m[2][0] = 1;
	z.m[2][1] = 7;
	z.m[2][2] = 8;
	z.m[2][3] = 44;
	z.m[2][4] = 1;


	z.m[3][0] = 11;
	z.m[3][1] = 12;
	z.m[3][2] = 13;
	z.m[3][3] = 14;
	z.m[3][4] = 1;

	z.m[4][0] = 11;
	z.m[4][1] = 12;
	z.m[4][2] = 13;
	z.m[4][3] = 14;
	z.m[4][4] = 2;



	std::cout << z << std::endl;

	std::cin >> bla;

	std::cout << z.subMatrix(0, 0).det() << std::endl;
	std::cout << z.subMatrix(0, 1).det() << std::endl;
	std::cout << z.subMatrix(0, 2).det() << std::endl;

	std::cin >> bla;

	std::cout << "DET" << z.det() << std::endl;

	std::cout << "INV" << 1.0 / z << std::endl;


	std::cin >> bla;


	Mat M(4);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			M.m[i][j] = ((float)rand() - (float)32000) / (float)1000;

		}
	}

	std::cout << "M " << M << std::endl;

	std::cin >> bla;


	std::cout << "INV M " << 1.0 / M << std::endl;

	std::cin >> bla;


	return 0;
}

//}

