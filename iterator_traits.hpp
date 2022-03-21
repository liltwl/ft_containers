#pragma once

#include <iterator>


namespace ft
{
struct input_iterator_tag  {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public input_iterator_tag         {};
struct bidirectional_iterator_tag : public forward_iterator_tag       {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};
   
template<class Iterator>
struct iterator_traits
{
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    //typedef typename Iterator::const_pointer   	const_pointer;
    typedef typename Iterator::iterator_category iterator_category;
};

template<class T>
struct iterator_traits<T*>
{
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef random_access_iterator_tag iterator_category;
};


template<class Category, class T, class Distance = ptrdiff_t,
         class Pointer = T*, class Reference = T&>
struct iterator
{
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
};

template <class _Iter>
class myiter
{
    public:
    typedef _Iter                                                      iterator_type;
    typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
    typedef typename iterator_traits<iterator_type>::value_type        value_type;
    typedef typename iterator_traits<iterator_type>::difference_type   difference_type;
    typedef typename iterator_traits<iterator_type>::pointer           pointer;
    typedef typename iterator_traits<iterator_type>::reference         reference;

    private:
        iterator_type i;
    public :
        myiter(): i(NULL){}
        myiter(iterator_type it): i(it){}
        template <class Iter>
        myiter (const myiter<Iter>& rev_it): i(rev_it.base()) {}

        iterator_type base() const {return (i);}


        reference operator*() const{return(*i);}
        myiter operator+ (difference_type n) const{return myiter(i + n);}
        template <class iter>
        difference_type operator+(const myiter<iter>& s2) {return i + s2.base();}
        myiter& operator++(){i++;return *this;}
        myiter  operator++(int){
            myiter tmp(*this);
            i++;
            return (tmp);
        }
        myiter& operator+= (difference_type n){
            i += n;
            return *this;
        }
        myiter operator- (difference_type n) const{return i - n;}
        template <class iter>
        difference_type operator-(const myiter<iter>& s2) {return i - s2.base();}
        myiter& operator--(){i--;return *this;}
        myiter  operator--(int){
            myiter tmp(*this);
            i--;
            return (tmp);
        }
        myiter& operator-= (difference_type n){
            i -= n;
            return *this;
        }
        pointer operator->() const{return (i);}
        reference operator[] (difference_type n) const{return *(i + n);}
        template <class Iterator>
        bool operator< (const myiter<Iterator>& lhs){return (i < (lhs.i));}
        template <class Iterator>
        bool operator== (const myiter<Iterator>& lhs){return (i == (lhs.i));}
        template <class Iterator>
        bool operator<= (const myiter<Iterator>& lhs){return (i <= (lhs.i));}
        template <class Iterator>
        bool operator>= (const myiter<Iterator>& lhs){return (i >= (lhs.i));}
        template <class Iterator>
        bool operator> (const myiter<Iterator>& lhs){return (i > (lhs.i));}
        template <class Iterator>
        bool operator!= (const myiter<Iterator>& lhs){return (i != (lhs.i));}

};

template<class Iter>
class reverse_iterator : public iterator<typename iterator_traits<Iter>::iterator_category,
                      typename iterator_traits<Iter>::value_type,
                      typename iterator_traits<Iter>::difference_type,
                      typename iterator_traits<Iter>::pointer,
                      typename iterator_traits<Iter>::reference>
{
    protected :
        Iter prt;
    
    public :
        typedef Iter                                            iterator_type;
        typedef typename iterator_traits<Iter>::difference_type difference_type;
        typedef typename iterator_traits<Iter>::reference       reference;
        typedef typename iterator_traits<Iter>::pointer         pointer;

        reverse_iterator(): prt(NULL){}
        explicit reverse_iterator(iterator_type it): prt(it){}
        template <class _Iter>
        reverse_iterator (const reverse_iterator<_Iter>& rev_it): prt(rev_it.base()) {}

        iterator_type base() const {return (prt);}
        reference operator*() const{return(*prt);}
        reverse_iterator operator+ (difference_type n) const{return (prt - n);}
        reverse_iterator& operator++(){prt--;return *this;}
        reverse_iterator  operator++(int){
            reverse_iterator tmp(*this);
            prt--;
            return (tmp);
        }
        reverse_iterator& operator+= (difference_type n){
            prt -= n;
            return *this;
        }
        reverse_iterator operator- (difference_type n) const{return (prt + n);}
        reverse_iterator& operator--(){prt++;return *this;}
        reverse_iterator  operator--(int){
            reverse_iterator tmp(*this);
            prt++;
            return (tmp);
        }
        reverse_iterator& operator-= (difference_type n){
            prt += n;
            return *this;
        }
        pointer operator->() const{return (prt);}
        reference operator[] (difference_type n) const{return *(prt + n);}
        template <class Iterator>
        bool operator< (const reverse_iterator<Iterator>& lhs){return (prt < lhs.prt);}
};
}
