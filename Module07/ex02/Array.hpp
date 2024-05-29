#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{
public:
	Array();
	Array(unsigned int n);
	Array& operator=(const Array& n);
	Array(const Array<T>& n);
	~Array();
	T& operator[](unsigned int n);
	const T& operator[](unsigned int n) const;

	unsigned int	size() const;
private:
	T*				elements_;
	unsigned int	size_;
};

template <typename T>
Array<T>::Array(): elements_(new T[0]), size_(0){}

template <typename T>
Array<T>::Array(unsigned int n): elements_(new T[n]), size_(n){}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& _copy){
	delete[] elements_;
	size_ = _copy.size();
	elements_ = new T[size_];
	for (unsigned int i = 0; i < size_; i++){
		elements_[i] = _copy[i];
	}
	return *this;
}

template <typename T>
Array<T>::Array(const Array<T>& _copy): elements_(new T[0]), size_(0){
	*this = _copy;
}

template <typename T>
Array<T>::~Array(){
	delete[] elements_;
}

template <typename T>
T& Array<T>::operator[](unsigned int n){
	if (n >= this->size_){
		throw	std::range_error("index error");
	}
	return elements_[n];
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const{
	if (n >= this->size_){
		throw	std::range_error("index error");
	}
	return elements_[n];
}

template <typename T>
unsigned int	Array<T>::size() const{
	return size_;
}

#endif
