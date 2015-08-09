#include <iostream>
#include "Matrix.h"
#include "City.h"
void initF(double** matrix , size_t row , size_t col)
{
	for(size_t i = 0 ; i < row ; ++i)
	{
		for(size_t j=0; j<col; ++j)
		{
			std::cin>> matrix[i][j];
		}
	}
}
int main()
{
	double** init;
	init= new double*[4];
	for(size_t i=0; i<4;++i)
	{
		init[i]= new double[5];

	}

	size_t M,N,C;
	std::cin>>M>>N>>C;
	initF(init,4,5);
	Matrix matrix(M,N,init);
	Matrix mat(M,N);
	City city(matrix,mat,C);
	city.simulation();
	return 0;
}
