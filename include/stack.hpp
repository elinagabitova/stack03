#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class stack
{
public:
	stack();
	~stack();
	stack(stack<T> const &copy);
	stack<T>& operator = (stack<T> const &other);
	size_t count() const;
	void push(T const &);
	T pop();
	void print_array();
	void print_last();
	void swap();
private:
	T* array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack() : count_(0), array_size_(0), array_(nullptr)
{}

template <typename T>
stack<T>::stack(stack<T> const &copy)
{
	array_size_ = copy.array_size_;
	count_ = copy.count_;
	array_ = new T[array_size_];

	for (int i = 0; i < array_size_; i++)
	{
		array_[i] = copy.array_[i];
	}
}

template <typename T>
stack<T>& stack<T>::operator=(stack<T> const &other)
{
	if (this != &other)
	{
		delete[] array_;
		array_size_ = other.array_size_;
		array_ = new T[array_size_];
		for (int i = 0; i < array_size_; i++)
		{
			array_[i] = other.array_[i];
		}
	}
	return *this;
}


template <typename T>
stack<T>::~stack()
{
	delete[] array_;
}

template <typename T>
size_t stack<T>::count() const
{
	return count_;
}

template <typename T>
void stack<T>::push(T const &value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	else if (count_ + 1 >= array_size_)
	{
		array_size_ = array_size_ * 2;
		swap();
	}
	array_[count_++] = value;
}

template <typename T>
T stack<T>::pop()
{
	if (count_ == 0)
		throw std::logic_error("Stack is empty! Try again!\n");
	else
	{
		T temp = array_[--count_];

		return temp;
	}
}

template <typename T>
void stack<T>::print_array()
{
	if (count_ == 0)
		std::cout << "Stack is empty! Try again!\n";
	else
		for (unsigned int i = 0; i < count_; i++)
		{
			std::cout << array_[i] << "\t";
		}
}

template <typename T>
void stack<T>::print_last()
{
	if (count_ == 0)
	{
		std::cout << "Stack is empty! Try again!\n";
	}
		
	else
	{
		std::cout << array_[--count_];
	}
}


template <typename T>
void stack<T>::swap()
{
	T* temp = new T[array_size_];
	std::copy(array_, array_ + count_, temp);

	delete[] array_;

	array_ = temp;
}
