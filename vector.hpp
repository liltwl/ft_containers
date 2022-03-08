#pragma once

#include <memory>


template <class T, class Alloc = std::allocator<T> >
class vector
{

    typedef T                                        	value_type;
    typedef Alloc 										allocator_type;
    typedef std::size_t 								size_type;

    typedef value_type&                            	  	reference;
    typedef const value_type&                       	const_reference;
    typedef typename allocator_type::difference_type	difference_type;
    typedef typename allocator_type::pointer         	pointer;
    typedef typename allocator_type::const_pointer   	const_pointer;
    typedef pointer                                  	iterator;

private:
    value_type* arg;
    size_type n;
    allocator_type allocc;

	iterator			begin;
	iterator			end;

public:
    explicit vector() : arg(NULL), n(0), begin(0), end(0)
    {
        std::cout << "default vector const called" << std::endl;
    }
    explicit vector (size_type _n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : arg(NULL), n(_n), begin(0), end(0)
    {
        arg = allocc.allocate(n + 1);
		begin = arg;
		int i = 0;
		for (int i = 0; i < _n ; i++)
			arg[i] = val;
		end = &arg[i];
        std::cout << "vector const called" << std::endl;
    }

	// template <class InputIterator>
	// vector (iterator first, iterator last, const allocator_type& alloc = allocator_type())
	// {
	// 	;
	// }

	vector (const vector& x) : arg(NULL), n(0), begin(0), end(0)
	{
		if (x.n > 0)
		{
			n = x.n;
			arg = allocc.allocate(n + 1);
			begin = arg;
			int i = 0;
        	for (i = 0; i < n ; i++)
            	arg[i] = x.arg[i];
			end = &arg[i];
		}
		std::cout << "vector copy const called" << std::endl;
	}

    ~vector()
    {
        allocc.deallocate(arg, n + 1);
        std::cout << "vector deconst called" << std::endl;
    }

	vector& operator= (const vector& x)
	{
		if (this != &x)
		{
			if (n > 0)
			{
				allocc.deallocate(arg, n + 1);
				n = 0;
			}
			if (x.n > 0)
			{
				n = x.n;
				arg = allocc.allocate(n + 1);
				begin = arg;
				int i = 0;
				for (i = 0; i < n ; i++)
					arg[i] = x.arg[i];
				end = &arg[i];
			}
			else
				arg = NULL;
		}
		std::cout << "vector copy operator called" << std::endl;
		return	(*this);
	}


	size_type size() const
	{
		iterator tmp;
		size_type i = 0;
	
		tmp = begin;
		while (tmp && tmp != end)
		{
			tmp++;
			i++;
		}
		return (i);
	}
};

