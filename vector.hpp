#pragma once

#include <memory>
#include "iterator_traits.hpp"
using namespace std;
namespace ft
{
template <class T, class Alloc = std::allocator<T> >
class vector
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
    explicit vector() : arg(NULL), n(0), cap(2)
    {
		arg = allocc.allocate(cap);
        // std::cout << "default vector const called" << std::endl;
    }
    explicit vector (size_type _n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) :  n(_n), cap(n + 1), arg(NULL)
    {
		arg = allocc.allocate(cap);
		for (int i = 0; i < _n ; i++)
			allocc.construct(&arg[i], val);
        // std::cout << "vector const called" << std::endl;
    }

	template <class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : arg(NULL), n(0), cap(0)
	{
		n = last - first;
		cap = n + 1;
		arg = allocc.allocate(cap);
		for (int i = 0; i < n ; i++)
			allocc.construct(&arg[i], *(first++));
	}

	vector (const vector& x) : arg(NULL), n(0), cap(0)
	{
		*this = x;
		// std::cout << "vector copy const called" << std::endl;
	}

    ~vector()
    {
        allocc.deallocate(arg, cap);
        // std::cout << "vector deconst called" << std::endl;
    }

	vector& operator= (const vector& x)
	{
		if (this != &x)
		{
			if (n > 0)
			{
				allocc.deallocate(arg, cap);
				n = 0;
			}
			if (x.n > 0)
			{
				n = x.n;
				cap = n + 1;
				arg = allocc.allocate(cap);
				for (int i = 0; i < n ; i++)
					allocc.construct(&arg[i], x[i]);
			}
			else
				arg = NULL;
		}
		// std::cout << "vector copy operator called" << std::endl;
		return	(*this);
	}


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
		return (reverse_iterator(arg + n));
	}

	reverse_iterator rend()
	{
		return reverse_iterator(arg);
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
		if (cap > _n)
		{
			for (i = n; i < _n ; i++)
			{
				allocc.construct(&arg[i], val);
			}
		}
		else if (cap <= _n && n > 0)
		{
			arg = allocc.allocate(_n + 1);
			for (i = 0; i < _n ; i++)
			{
				if(i < n)
					allocc.construct(&arg[i], tmp[i]);
				else
					allocc.construct(&arg[i], val);
			}
			allocc.deallocate(tmp, cap);
		}
		else
			arg = NULL;
		n = _n;
		cap = n + 1;
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
			if (cap > 0)
				allocc.deallocate(arg, cap);
			arg = allocc.allocate(_n);
			cap = _n;
			for (i = 0; i < n ; i++)
			{
				if(i < n)
					allocc.construct(&arg[i], tmp[i]);
			}
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
	
	reference at(size_type n)
	{
		return (arg[n]);
	}

	const_reference at (size_type n) const
	{
		return (arg[n]);
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
		int i = position - begin();

		for (ss = begin(); ss < end(); ss++)
			if (ss == position)
				break;
		if (ss == end())
		{
			resize(n + 1);
			allocc.construct(arg + n - 1, val);
			return (end() - 1);
		}
		else
		{
			resize(n + 1);
			for (iterator ss = end() - 1; ss > begin() + i; ss--)
			{
				*ss = *(ss - 1);
			}
			arg[i] = val;
		}
		return (begin() + i);
	}

	void insert (iterator position, size_type n, const value_type& val)
	{
		for (int i = 0; i < n; i++)
		{
			position = insert(position, val);
		}
	}

	template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last)
	{
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
		allocc.deallocate(arg, cap);
		n = 0;
		cap = 3;
		arg = allocc.allocate(cap);
		insert(arg, _n, val);
	}

	template <class InputIterator>
	void assign(InputIterator first, InputIterator last)
	{
		allocc.deallocate(arg, cap);
		n = 0;
		cap = 2;
		arg = allocc.allocate(cap);
		iterator tmp;
		for (iterator tmp = first; tmp < last; tmp++)
		{
			push_back(*tmp);
		}
	}

	iterator erase (iterator position)
	{
		int i = position - begin();

		if (position >= begin() && position < end())
		{
			for (iterator ss = end(); ss > position; ss--)
			{
				*ss = *(ss - 1);
			}
			resize(n - 1);
		}
		return (begin() + i);
	}
};
}
