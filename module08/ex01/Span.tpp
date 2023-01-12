//==== constructors =====================================================================

Span::Span(void)
{
   _spanVector.reserve(0);
}

Span::Span(unsigned int N)
{
    _spanVector.reserve(N);
}

Span::Span(const Span &other)
{
    _spanVector.reserve(other._spanVector.capacity());
    _spanVector = other._spanVector;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _spanVector.clear();
        _spanVector.reserve(other._spanVector.capacity());
        _spanVector = other._spanVector;
    }
    return (*this);
}

Span::~Span(void)
{
    _spanVector.clear();
}

//==== member functions =================================================================

void    Span::addNumber(int n)
{
    if (_spanVector.size() == _spanVector.capacity())
        throw SpanIsFullException();
    else
    {
        _spanVector.push_back(n);
        std::cout << GREEN << "Integer {";
        std::cout << WHITE << n;
        std::cout << GREEN << "} added to span." << RESET << std::endl;
    }
}

void    Span::addRange(vecIt begin, vecIt end)
{
    if (end < begin)
        return ;
    if (static_cast<unsigned int>(std::distance(begin, end)) > _spanVector.capacity() - _spanVector.size())
        throw NotEnoughSpaceException();
    _spanVector.insert(_spanVector.end(), begin, end);

    std::stringstream msg;
    vecIt   tmp = begin;
    if (std::distance(begin, end) > 5)
    {
        while (tmp < end)
        {
            msg << *tmp;
            msg << ", ";
            tmp++;
            if (tmp - begin == 5)
                break ;
        }
        msg << "... ";
    }
    else
    {
        while (tmp < end)
        {
            msg << *tmp;
            if (tmp + 1 != end)
                msg << ", ";
            tmp++;
        }
    }
    std::cout << GREEN << std::distance(begin, end) << " integers added to span {";
    std::cout << WHITE << msg.str();
    std::cout << GREEN << "}." << RESET << std::endl;
}

unsigned int Span::shortestSpan(void)
{
    if (_spanVector.size() < 2)
    {
        throw NotEnoughElementsException();
        return (-1);
    }
    std::vector<int>    sortedVec(_spanVector);
    std::sort(sortedVec.begin(), sortedVec.end());

    unsigned int min_dist = -1;
    int first = 0;
    int second = 0;
    for (std::vector<int>::iterator it = sortedVec.begin(); it + 1 != sortedVec.end(); ++it)
    {
        if (static_cast<unsigned int>(*(it + 1) - *it) < min_dist)
        {
            min_dist = static_cast<unsigned int>(*(it + 1) - *it);
            first = *it;
            second = *(it + 1);
        }
    }
    std::cout << BLUE << "The shortest span is ";
    std::cout << WHITE << min_dist;
    std::cout << BLUE << " (= " << second << " - " << first << ")." << RESET << std::endl;
    return (min_dist);
}

unsigned int Span::longestSpan(void)
{
    if (_spanVector.size() < 2)
    {
        throw NotEnoughElementsException();
        return (-1);
    }
    std::vector<int>    sortedVec(_spanVector);
    std::sort(sortedVec.begin(), sortedVec.end());

    std::vector<int>::iterator b = sortedVec.begin();
    std::vector<int>::iterator e = sortedVec.end();
    unsigned int max_dist = static_cast<unsigned int>(*(e - 1) - *b);

    std::cout << PINK << "The longest span is ";
    std::cout << WHITE << max_dist;
    std::cout << PINK << " (= " << *(e - 1) << " - " << *b << ")." << RESET << std::endl;
    return (max_dist);
}

//==== Exception what() functions =======================================================

const char  *Span::SpanIsFullException::what() const throw()
{
    return ("\33[1;31mEXCEPTION: Can't add new element (span already full)!\33[0;m");
}

const char  *Span::NotEnoughElementsException::what() const throw()
{
    return ("\33[1;31mEXCEPTION: Not enough elements for a span!\33[0;m");
}

const char  *Span::NotEnoughSpaceException::what() const throw()
{
    return ("\33[1;31mEXCEPTION: Not enough space in span to add new elements!\33[0;m");
}
