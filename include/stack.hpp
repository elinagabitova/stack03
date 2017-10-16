#include <iostream>
#include <stdexcept>
#include <algorithm>

template <typename T>
class stack
{
public:
	stack() noexcept;
	~stack() noexcept;
	stack(stack<T> const &copy) noexcept;
	stack<T>& operator = (stack<T> const &other) noexcept;
	size_t count() const noexcept;
	void push(T const &) noexcept;
	T pop() noexcept;
	T top() noexcept;
	void print_array() noexcept;
	void print_last() noexcept;
	bool empty() noexcept;
	void swap() noexcept;
private:
	T* array_;
	size_t array_size_;
	size_t count_;
};

template <typename T>
stack<T>::stack() noexcept : count_(0), array_size_(0), array_(nullptr)
{}

template <typename T>
stack<T>::stack(stack<T> const &copy) noexcept
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
stack<T>& stack<T>::operator=(stack<T> const &other) noexcept
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
stack<T>::~stack() noexcept
{
	delete[] array_;
}

template <typename T>
size_t stack<T>::count() const noexcept
{
	return count_;
}

template <typename T>
void stack<T>::push(T const &value) noexcept
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
T stack<T>::pop() noexcept
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
T stack<T>::top() noexcept 
{
	T temp = array_[count_];

	return temp;
}

template <typename T>
void stack<T>::print_array() noexcept
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
void stack<T>::print_last() noexcept
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
bool stack<T>::empty() noexcept
{
	(count_ == 0) ? return true : return false;
		
}

template <typename T>
void stack<T>::swap() noexcept
{
	T* temp = new T[array_size_];
	std::copy(array_, array_ + count_, temp);

	delete[] array_;

	array_ = temp;
}
