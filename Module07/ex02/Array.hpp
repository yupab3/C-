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
	T& operator[](unsigned int n) const;

	unsigned int	size() const;
private:
	T*				elements_;
	unsigned int	size_;
};

template <typename T>
Array<T>::Array(): elements_(NULL), size_(0){}

template <typename T>
Array<T>::Array(unsigned int n): elements_(new T[n]), size_(n){
	if (size_ == 0){
		delete[] elements_;
		elements_ = NULL;
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& _copy){
	if (this->size_ != 0){
		delete[] elements_;
	}
	size_ = _copy.size();
	elements_ = new T[size_];
	for (unsigned int i = 0; i < size_; i++){
		elements_[i] = _copy[i];
	}
	return *this;
}

template <typename T>
Array<T>::Array(const Array<T>& _copy){
	if (this != &_copy){
		return *this;
	}
	*this = _copy;
	return *this;
}

template <typename T>
Array<T>::~Array(){
	if (this->size_ != 0){
		delete[] elements_;
	}
}

template <typename T>
T& Array<T>::operator[](unsigned int n) const{
	return elements_[n];
}

template <typename T>
unsigned int	Array<T>::size() const{
	return size_;
}

#endif
