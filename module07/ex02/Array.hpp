#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <string>
# include <ctime>

template <typename T>
class Array
{
	private:
		unsigned int _n;
		T*			_arrT;

	public:
		Array(void);							// Default constructor
		Array(unsigned int n);					// Parameterized constructor
		Array(const Array &other);				// Copy constructor
		Array &operator=(const Array &other);	// Copy assignment operator
		~Array(void);							// Destructor

	public:
		T				&operator[](unsigned int index) const;
		unsigned int	size(void) const;

	public:
		class OutOfBoundsException : public std::exception
		{
			const char	*what() const throw();
		};	
};

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

#endif