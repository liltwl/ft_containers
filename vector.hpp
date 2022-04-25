#pragma once

#include <memory>
#include "iterator_traits.hpp"
using namespace std;
namespace ft
{
template <class T, class Alloc = std::allocator<T> >
class Vector
{
	public :
    typedef T                                        	value_type;
    typedef Alloc 										allocator_type;
    typedef std::size_t 								size_type;
	typedef allocator_traits<allocator_type>         	__alloc_traits;
    typedef value_type&                            	  	reference;
    typedef const value_type&                       	const_reference;
    typedef typename __alloc_traits::pointer        	pointer;
    typedef typename __alloc_traits::const_pointer   	const_pointer;

	typedef ft::myiter<pointer> 	        			iter_traits;
    typedef typename iter_traits::difference_type		difference_type;
    typedef iter_traits		               				iterator;
    typedef ft::myiter<const_pointer>			        const_iterator;
	typedef ft::reverse_iterator<iterator>       		reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>   		const_reverse_iterator;

protected :
    value_type* arg;
    size_type n;
	size_type cap;
    allocator_type allocc;

public :
    explicit Vector() : arg(NULL), n(0), cap(0)
    {
		//arg = allocc.allocate(cap);
        // std::cout << "default Vector const called" << std::endl;
    }
    explicit Vector (size_type _n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) :  n(_n), cap(n), arg(NULL), allocc(alloc)
    {
		arg = allocc.allocate(cap);
		for (int i = 0; i < _n ; i++)
			allocc.construct(&arg[i], val);
        // std::cout << "Vector const called" << std::endl;
    }

	template <class InputIterator>
	Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : arg(NULL), n(0), cap(0), allocc(alloc)
	{
		n = last - first;
		cap = n;
		arg = allocc.allocate(cap);
		for (int i = 0; i < n ; i++)
		{
			allocc.construct(&arg[i], *(first));
			first++;
		}
	}

	Vector (const Vector& x) : arg(NULL), n(0), cap(2)
	{
		allocc = x.allocc;
		arg = allocc.allocate(cap);
		*this = x;
		// std::cout << "Vector copy const called" << std::endl;
	}

    ~Vector()
    {
		if (cap != 0)
        	allocc.deallocate(arg, cap);
        // std::cout << "Vector deconst called" << std::endl;
    }

	Vector& operator= (const Vector& x)
	{
		if (this != &x)
		{
			if (cap > 0)
			{
				allocc.deallocate(arg, cap);
				n = 0;
			}
			if (x.n > 0)
			{
				n = x.n;
				cap = x.cap;
				arg = allocc.allocate(cap);
				for (int i = 0; i < n ; i++)
					allocc.construct(&arg[i], x[i]);
			}
			else
				arg = allocc.allocate(cap);
		}
		// std::cout << "Vector copy operator called" << std::endl;
		return	(*this);
	}

	class outofbounds : public std::exception
        {   public : 
                const char* what() const throw()
				{
					return("index out-of-bounds");
				}
        };

	size_type size() const
	{
		return (n);
	}

	iterator begin()
	{
		return (arg);
	}
	const_iterator begin() const
	{
		return (arg);
	}

	reverse_iterator rbegin()
	{
		return (reverse_iterator(end()));
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}

	iterator end()
	{
		return (arg + n);
	}

	const_iterator end() const
	{
		return (arg + n);
	}

	void resize (size_type _n, value_type val = value_type())
	{
		value_type *tmp;
		size_type i = 0;

		tmp = arg;
		if (_n < cap)
		{
			for (i = n; i < _n ; i++)
			{
				allocc.construct(&arg[i], val);
			}
		}
		else if (_n > 0)
		{
			arg = allocc.allocate(_n);
			for (i = 0; i < _n ; i++)
			{
				if(i < n)
					allocc.construct(&arg[i], tmp[i]);
				else
					allocc.construct(&arg[i], val);
			}
			allocc.deallocate(tmp, cap);
			cap = _n;
		}
		else
			arg = NULL;
		n = _n;
	}

	size_type capacity() const
	{
		return (cap);
	}

	void reserve (size_type _n)
	{
		value_type *tmp;
		int i = 0;
	
		tmp = arg;
		if (_n > cap)
		{
			arg = allocc.allocate(_n);
			for (i = 0; i < n ; i++)
			{
				if(i < n)
					allocc.construct(&arg[i], tmp[i]);
			}
			if (cap > 0)
				allocc.deallocate(tmp, cap);
			cap = _n;
		}
	}

	bool empty() const
	{
		if (n == 0)
			return (1);
		else
			return 0;
	}

	reference operator[] (size_type n)
	{
		return (arg[n]);
	}

	const_reference operator[] (size_type n) const
	{
			return (arg[n]);
	}
	
	reference at(size_type _n)
	{
		if (_n < n && _n >= 0)
			return (arg[_n]);
		throw outofbounds();
	}

	const_reference at (size_type _n) const
	{
		if (_n < n && _n >= 0)
			return (arg[_n]);
		throw outofbounds();
	}

	reference front()
	{
		return (arg[0]);
	}

	const_reference front() const
	{
		return (arg[0]);
	}

	reference back()
	{
		return (arg[n- 1]);
	}

	const_reference back() const
	{
		return (arg[n - 1]);
	}

	iterator insert(iterator position, const value_type& val)
	{
		iterator ss;

		for (ss = begin(); ss < end(); ss++)
			if (ss == position)
				break;
		int i = ss - begin();
		if (position == end())
		{
			if (cap <= n)
				reserve(n * 2);
			// else
			resize(n + 1);
			allocc.construct(arg + n - 1, val);
			return (end() - 1);
		}
		else
		{
			if (cap <= n)
				reserve(n * 2);
			resize(n + 1);
			for (ss = end() - 1; ss > begin() + i; ss--)
			{
				*ss = *(ss - 1);
			}
			arg[i] = val;
		}
		return (begin() + i);
	}


	void insert (iterator position, size_type _n, const value_type& val)
	{
		int j = position - begin();
		if (_n > cap)
			reserve(_n + cap);
		position = begin() + j;
		for (int i = 0; i < _n; i++)
		{
			position = insert(position, val);
		}
	}

	template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last)
	{
		int j = position - begin();
		if (last - first > cap)
			reserve((last - first )+ cap);
		position = begin() + j;
		for (InputIterator tmp = first; tmp < last; tmp++)
		{
			position = insert(position, *tmp);
		}
	}

	void pop_back()
	{
		resize(n - 1);
	}

	void push_back (const value_type& val)
	{
		insert(end(), val);
	}

	void assign (size_type _n, const value_type& val)
	{
		// if (cap > 0)
		// 	allocc.deallocate(arg, cap);
		// n = 0;
		// cap = 0;
		clear();
		if (cap < _n)
			reserve(_n);
		//arg = allocc.allocate(cap);
		insert(begin(), _n, val);
	}

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last)
	{
		// allocc.deallocate(arg, cap);
		// n = 0;
		clear();
		if (cap < last - first)
			reserve(last - first);
		// cap = 1;
		// arg = allocc.allocate(cap);
		// InputIterator tmp;
		// for (InputIterator tmp = first; tmp < last; tmp++)
		// {
		// 	push_back(*tmp);
		// }
		insert(begin() ,first, last);
	}

	iterator erase (iterator position)
	{
		int i = position - begin();
		if (position >= begin() && position < end())
		{
			for (iterator ss = position; ss < end()- 1; ss++)
			{
				*ss = *(ss + 1);
			}
			resize(n - 1);
		}
		else
			return (position);
		return (begin() + i);
	}

	iterator erase (iterator first, iterator last)
	{
		iterator tmp = first;
		int i = last - first;
	
		for (int j= 0; j < i; j++)
		{
			tmp = erase(tmp);
		}
		return (tmp);
	}

	void swap (Vector& x)
	{
		// Vector<T> tmp;
		value_type *tmp;
		size_type i;
		size_type j;

		tmp = x.arg;
		i = x.cap;
		j = x.n;
		x.arg = arg;
		x.n = n;
		x.cap = cap;
		arg = tmp;
		n = j;
		cap = i;
	}

	void clear()
	{
		//allocc.deallocate(arg, cap);
		n = 0;
		//arg = allocc.allocate(cap);
	}

	template <class T1>
	bool operator== (const Vector<T1>& lhs)
	{
		if(size() != lhs.size())
			return (0);
		for (int i = 0; i < size(); i++)
		{
			if (this->at(i)!= lhs[i])
				return (0);
		}
		return (1);
	}

	template <class T1>
	bool operator!= (const Vector<T1>& lhs)
	{
		return !(*this == lhs);
	}

	template <class T1>
	bool operator< (const Vector<T1>& lhs)
	{
		int n1 = 0;

		n1 = (size() < lhs.size()?size():lhs.size());
		for (int i = 0; i < n1; i++)
		{
			if (this->at(i) != lhs[i])
				return (this->at(i) < lhs[i]);
		}
		return (size() < lhs.size());
	}

	template <class T1>
	bool operator<= (const Vector<T1>& lhs)
	{
		return (*this < lhs) || *this==lhs;
	}

	template <class T1>
	bool operator> (const Vector<T1>& lhs)
	{
		return (!(*this < lhs))&&!(*this == lhs);
	}

	template <class T1>
	bool operator>= (const Vector<T1>& lhs)
	{
		return !(*this < lhs);
	}

	size_type max_size() const
	{
		return (allocc.max_size());
	}
	allocator_type get_allocator() const
	{
		return allocc;
	}
};

	template <class T>
		void swap(ft::Vector<T>& lhs, ft::Vector<T>& rh)
		{
			lhs.swap(rh);
		};
}
