#pragma once

//  Determinante.h
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

//    The Determinant is a better implementation of the Determinat
//    calculation. (By the way the e at the end comes from the german spelling)



#include "Matrix.h"


class Det : public Mat

{

public:

	Det(); 
	Det(int x); 
	~Det(); 

	float determinant();
	int   countZerosInColumn(int c); 
	int   countZerosInRow(int c); 
	void  switchRows(int a, int b);
	void  switchColumns(int a, int b); 
	int   sortRow(); 
	int   sortColumn(); 
	void  subtractMultiple(int a, int b, int el); 
	float multiplyDiagonal(); 


};
