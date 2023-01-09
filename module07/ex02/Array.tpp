
//==== constructors =====================================================================

template <typename T>
Array<T>::Array(void) : _n(0), _arrT(new T[0]) {}

template <typename T>
Array<T>::Array(unsigned int n) : _n(n), _arrT(new T[n]) {}

template <typename T>
Array<T>::Array(const Array &other) : _n(other._n)
{
	_arrT = new T[_n];
	for (unsigned int i = 0; i < _n; i++)
		_arrT[i] = other._arrT[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		_n = other._n;
		delete [] _arrT;
		_arrT = new T[_n];
		for (unsigned int i = 0; i < _n; i++)
			_arrT[i] = other._arrT[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] _arrT;
}

//======================================================================================

template <typename T>
T	&Array<T>::operator[](unsigned int index) const
{
	if (index > _n)
		throw OutOfBoundsException();
	return (*(_arrT + index));
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_n);
}

//==== Exception what() functions =======================================================

template <typename T>
const char	*Array<T>::OutOfBoundsException::what() const throw()
{
	return ("\33[1;31mEXCEPTION: index is out of bounds!\33[0;m");
}