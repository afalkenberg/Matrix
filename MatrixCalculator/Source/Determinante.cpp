
#include "Determinante.h"

//  Determinante.cpp
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


// the following algorithm implements the determinate in an iterative process // 
// by trying to generate a triangular matrix with lower triangle being all 0 // 
// the result is then the multiplication of all the vertical elements (+ or -) // 

// The following rules are applied until it works: 
// 1. if one row or one colum is all 0 then return 0 
// 2. sort the columns such that the column with the most 0 is to the left of the matrix. 
// 3. sort the rows such that the row with the most 0 is on the bottom 


Det::Det(void)
{
	N = 2; 
}


Det::Det(int x) : Mat(x)
{

	

}


Det::~Det()
{

}

float Det::determinant()
{
	
	int n = sortRow();
	
	n = n + sortColumn();

	for (int i = 0; i < N - 1; i++) 
	{

		for (int j = i + 1; j < N; j++)
		{
			subtractMultiple(i, j, i);
		}

	}


	float res; 
	res = multiplyDiagonal();
	if ((n / 2) * 2 == n)
	{
		return res; 
	}
	else
	{
		return -res;
	}
}




int Det::countZerosInRow(int c)
{
	int r = 0; 
	for (int i = 0; i < N; i++)
	{
		if (m[c][i] == 0.0)
		{
			r++; 
		}
	}
	return r; 
}


int Det::countZerosInColumn(int c)
{
	int r = 0;
	for (int i = 0; i < N; i++)
	{
		if (m[i][c] == 0.0)
		{
			r++;
		}
	}
	return r;
}


void Det::switchColumns(int a, int b)
{

	for (int i = 0; i < N; i++)
	{
		float h = m[i][a]; 
		m[i][a] = m[i][b]; 
		m[i][b] = h; 

	}

	
}

void Det::switchRows(int a, int b)
{

	for (int i = 0; i < N; i++)
	{
		float h = m[a][i];
		m[a][i] = m[b][i];
		m[b][i] = h;

	}

	
}


// bring 0 to the bottom result is the number of row switches 
int Det::sortRow()
{

	int vz = 0; 

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (countZerosInRow(i) > countZerosInRow(j))
			{
				switchRows(i, j);
				vz++; 
			
			}
		}
	}


	return vz; 
}




// bring 0 to the left result is numbe of column switches 
int Det::sortColumn()
{
	int vz = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (countZerosInColumn(i) < countZerosInColumn(j))
			{
				switchColumns(i, j);
				vz++;

			}
		}
	}


	return vz;
 
}



// now subtract row n from row m such that the element el becomes 0 in row m 


void Det::subtractMultiple(int a, int b, int el)
{


	float mplier =   m[b][el] / m[a][el];

	
	for (int i = 0; i < N; i++)
	{
		float h;
		h= m[a][i] * mplier;
		m[b][i] = m[b][i] - h; 
		
	}

}


float Det::multiplyDiagonal()
{
	float res; 
	res = m[0][0]; 
	for (int i = 1; i < N; i++)
	{
		res = res * m[i][i]; 
	}
	return res; 
}


