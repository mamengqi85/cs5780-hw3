#include <vector>
#include <map>

#ifndef CS5780HW3_SPARSE_VECTOR_H
#define CS5780HW3_SPARSE_VECTOR_H

class ExceptionOutOfRange {};

template <class T>
class SparseVector
{
 public:
	 typedef std::map<int, T> vector_t;
	 typedef typename vector_t::iterator iter;

	 SparseVector();
	 SparseVector(const int size);

	 int get_size() const { return size; }

     T& operator()(const int i);
	 T operator()(const int i) const;
     SparseVector<T> operator=(const SparseVector<T> &x);
     SparseVector<T> operator+=(SparseVector<T> &x);
     std::vector<T> operator+(const std::vector<T> &x);
     T operator*=(const std::vector<T> &x);
     const SparseVector<T>* operator &();
     //void printMat();

 private:
     int size;
     vector_t data;
};

/*template <class T>
void SparseMatrix<T>::printMat()
{
    row_iter ii;
    col_iter jj;
    for (ii = this->data.begin(); ii != this->data.end(); ii++) {
        for(jj = (*ii).second.begin(); jj != (*ii).second.end(); jj++) {
            std::cout << (*ii).first << ' ';
            std::cout << (*jj).first << ' ';
            std::cout << (*jj).second << std::endl;
        }
    }
	std::cout << std::endl;
}*/

template <class T>
SparseVector<T>::SparseVector()
{
	size = 0;
}

template <class T>
SparseVector<T>::SparseVector(const int size)
{
	this->size = size;
}

template <class T>
T& SparseVector<T>::operator()(const int i)
{
    if (i >= size) {
		throw ExceptionOutOfRange();
		//std::cerr << "& error" << i << " "<< j<< std::endl;
		//abort();
	}
    return data[i];
}

template <class T>
T SparseVector<T>::operator()(const int i) const
{
    if( i>=size ) {
		throw ExceptionOutOfRange();
		//std::cerr<<"() err"<<std::endl;
		//abort();
	}
    return data[i];
}

template <class T>
SparseVector<T> SparseVector<T>::operator=(const SparseVector<T> &x)
{
	data = x.data;
	return *this;
}

/*template <class T>
SparseVector<T> SparseVector<T>::operator+=(SparseVector<T>& x)
{
	if (this->size != x.size) {
		throw ExceptionOutOfRange();
	}

	ii = x.data.begin();
	for (;ii != x.data.end(); ii++) {
		for (jj = (*ii).second.begin(); jj != (*ii).second.end(); jj++) {
			data[(*ii).first][(*jj).first] += (*jj).second;
		}
	}
	return *this;
}*/

template <class T>
std::vector<T> SparseVector<T>::operator+(const std::vector<T> &x){
	std::vector<T> y = x;
    iter i;
    for (i = this->data.begin(); i != this->data.end(); i++) {
        y[i->first()] += i->second();
    }
    return y;
}

template <class T>
T SparseVector<T>::operator*=(const std::vector<T>& x)
{
    T y = 0;
    iter i;
    for (i = this->data.begin(); i != this->data.end(); i++) {
        y += x[i->first()]*i->second();
    }
    return y;
}

template <class T>
const SparseVector<T>* SparseVector<T>::operator&(){
	return this;
}
#endif	/* CS5780HW3_SPAESE_VECTOR_H */
