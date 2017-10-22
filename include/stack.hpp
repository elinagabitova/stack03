#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <utility>

template <typename T>
class stack
{
public:
	stack() /*basic*/;
	~stack() noexcept;
	stack(stack<T> const &) /*basic*/;
	stack<T>& operator = (stack<T> const &) noexcept;
	size_t count() const noexcept;
	
	void swap(stack<T> &) noexcept;
	void push(T const &) /*basic*/;
	bool empty() const noexcept;
	void pop() /*strong*/;
	T top() /*strong*/;
	
	std::ostream& print(std::ostream&) const;		
	friend std::ostream& operator << (std::ostream&, stack<T> &) noexcept;
	
private:
	T* array_;
	size_t array_size_;
	size_t count_;
};

template <typename T> 
stack<T>::stack() : count_(0), array_size_(0), array_(nullptr)
{}
	
template <typename T>
stack<T>::stack(stack<T> const& copy) 
{
	array_size_ = copy.array_size_;
	count_ = copy.count_;
	array_ = new T[array_size_];

	std::copy(copy.array_, copy.array_ + copy.array_size_, array_);
}

template <typename T>
stack<T>& stack<T>::operator=(stack<T> const& other) noexcept
{
	if (this != &other)
	{
		stack<T> temp(other);
		swap(temp);
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
void stack<T>::swap(stack<T>& other) noexcept
{
	std::swap(array_, other.array_);
    	std::swap(array_size_, other.array_size_);
	std::swap(count_, other.count_);
}

template <typename T>
void stack<T>::push(T const& value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	else if (count_ + 1 >= array_size_)
	{
		array_size_ = array_size_ * 2;
		T* temp = new T[array_size_];
		
		std::copy(array_, array_ + count_, temp);

		delete[] array_;
		array_ = temp;
	}
	array_[count_++] = value;
}

template <typename T>
void stack<T>::pop()
{
	if (count_ == 0)
		std::cout << "Stack is empty! Try again!\n";
	else
		count_ --;
}

template <typename T>
T stack<T>::top() 
{
	T temp = array_[count_--];

	return temp;
}

template <typename T>
bool stack<T>::empty() const noexcept
{
	return (count_ == 0); 
}

template <typename T>
std::ostream& stack<T>::print(std::ostream& os) const
{ 
	if (count_ == 0)
		os << "Stack is empty! Try again!\n";
	else
		for (unsigned int i = 0; i < count_; i++)
		{
			os << array_[i] << "\t";
		}
	return os;
}

template <typename T>
std::ostream& operator << (std::ostream& os, stack<T>& obj) noexcept
{
	return obj.os(os);
}
