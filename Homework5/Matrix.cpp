#include "Matrix.h"

void Matrix::allocate(size_t M, size_t N)
{
    matrix = new double*[M];
    for(size_t i=0; i<N;++i)
    {
        matrix[i]= new double[N];
    }
}

void Matrix::destroy()
{
    for(size_t i=0 ; i<N; ++i)
    {
        delete  []matrix[i];
    }

    delete [] matrix;
}
size_t  Matrix::getM()const
{
    return this->M;
}
size_t  Matrix::getN() const
{
    return this->N;
}
void Matrix::copy(const Matrix& other )
{
     allocate(other.getM(), other.getN());
     M=other.getM();
     N=other.getN();
      for(size_t i=0; i<M;++i)
      {
          for(size_t j=0; j<N;++j)
          {
          	this->setElem(i,j,other.getElem(i,j));
          }

      }
 }
void Matrix::setElem(size_t x, size_t y, double elem)
{
	matrix[x][y]=elem;
}
double Matrix::getElem(size_t x, size_t y)const
{
	return matrix[x][y];
}
Matrix::Matrix(size_t M,size_t N)
{
	allocate(M,N);
	this->M=M;
	this->N=N;
	for(size_t i=0;i<M;++i)
	{
		for(size_t j=0; j<N; ++j)
		{
			this->setElem(i,j,0);
		}
	}
}
Matrix::Matrix(size_t M, size_t N , double ** init)
{
		this->M=M;
		this->N=N;
		allocate(M,N);
		for(size_t i=0;i<M;++i)
		{
			for(size_t j=0; j<N; ++j)
			{
				this->setElem(i,j,init[i][j]);
			}
		}
}
Matrix::Matrix(const Matrix& other)
{
	copy(other);
}
Matrix& Matrix::operator =(const Matrix& other)
{
	if(this!=&other){
		destroy();
		copy(other);
	}
	return *this;
}
Matrix::~Matrix()
{
	destroy();
}
void Matrix::print()const
{
	for(size_t i=0; i<M;++i)
	{
		for(size_t j=0; j<N; ++j)
		{
			std::cout<<getElem(i,j)<<"   ";
		}
		std::cout<<std::endl;
	}
	std::cout<<std::endl;
}

void Matrix::init(Simulation& sim)
{
	size_t row = M;
	size_t col = N;
	for(size_t i=0; i< row ; ++i)
	{
		for(size_t j =0 ; j <col; ++j)
		{
			setElem(i,j,sim.liters);
		}
	}
}

