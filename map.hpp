#pragma once

#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include "pair.hpp"
#include <stack>
#include <iterator>
#include <string>
#include "iterator_traits.hpp"
#define PRINTLN(x) std::cout << x <<std::endl;
namespace ft{
    template <class K, class T,class Compare = less<K>, class Alloc = allocator<ft::pair<K,T> > >
    class BST {
         public :
            typedef ft::pair<K, T>                              value_type;
            typedef Alloc 						                    allocator_type;
            typedef Compare                                             key_compare;
            typedef allocator_traits<allocator<BST> >         	    __alloc_traits;
            typedef typename __alloc_traits::difference_type		difference_type;
            typedef typename allocator_traits<Alloc>::pointer        	pointer;
            typedef typename allocator_traits<Alloc>::size_type                    size_type;
            typedef typename __alloc_traits::pointer             P;
            typedef ft::mapiter<P, pointer>			            iterator;

        public:
            value_type *m_pair;
            BST *left, *right, *parent;
            allocator_type allocc;
            Compare     c;
        public :

            BST(const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()): m_pair(NULL), left(NULL), right(NULL), parent(NULL), allocc(alloc), c(comp) {}
            BST(K first,T second, const key_compare& comp= key_compare(),
                const allocator_type& alloc= allocator_type()) 
                : m_pair(NULL), left(NULL), right(NULL), parent(NULL), allocc(alloc), c(comp)
            {
                m_pair = allocc.allocate(1);
                allocc.construct(m_pair, first, second);
            }

            BST(value_type &pair, const key_compare& comp= key_compare(),
                const allocator_type& alloc= allocator_type())
                : m_pair(NULL), left(NULL), right(NULL), parent(NULL), allocc(alloc), c(comp)
            {
                m_pair = allocc.allocate(1);
                allocc.construct(m_pair, pair);
            }

            BST(BST& other): m_pair(NULL), left(NULL), right(NULL), parent(NULL), allocc(other.allocc), c(other.c)
            {
                BST* tmp;
                tmp = treecopy(&other);
                m_pair = tmp->m_pair;
                left = tmp->left;
                right = tmp->right;
            }
            
            ~BST()
            {
                allocc.deallocate(m_pair, 1);
            }

            BST *find(K key)
            {
                BST *root = this;
                while (root->parent != NULL)
                {
                    root = root->parent;
                }
                while (root)
                {
                    if (root->m_pair->first == key)
                        return (root);
                    if (key < root->m_pair->first)
                        root = root->left;
                    else
                        root = root->right;
                }
                cout <<  "Dwed" << endl;
                return (NULL);
            }

            BST*   insert(BST* root, value_type &pair)
            {
                if (root->find(pair.first)!= NULL)
                    return (NULL);
                if (!root) {
                    return new BST(pair, c, allocc);
                }
                if (c(root->m_pair->first, pair.first)){
                    root->right = insert(root->right, pair);
                    root->right->parent = root;
                }
                else {
                    root->left = insert(root->left, pair);
                    root->left->parent = root;
                }
                return root;
            }

            BST*   insert(BST* root, K first,T second)
            {
                if (root->find(first) != NULL)
                    return (NULL);
                if (!root) {
                    return new BST(first, second, c, allocc);
                }
                if (c(root->m_pair->first, first)){
                    root->right = insert(root->right, first, second);
                }
                else {
                    root->left = insert(root->left, first, second);
                }
            
                return root;
            }

            BST*    maxkey(BST* root)
            {
                BST *current = this;

                while (current && current->right != NULL)
                    current = current->right;
                return current;
            }

            BST*    minkey(BST* root)
            {
                BST *current = this;

                while (current && current->left != NULL)
                    current = current->left;
                return current;
            }

            BST*    deleteNode(BST* root, K key)
            {
                BST     *temp;
                if (root == NULL)
                    return root;

                if (key < root->m_pair->first)
                    root->left = deleteNode(root->left, key);
                else if (key > root->m_pair->first)
                    root->right = deleteNode(root->right, key);
                else 
                {
                    if (root->left == NULL)
                    {
                        temp = root->right;
                        delete root;
                        return temp;
                    } else if (root->right == NULL) 
                    {
                        temp = root->left;
                        delete (root);
                        return temp;
                    }
                    temp = minkey(root->right);

                    root->m_pair = temp->m_pair;

                    root->right = deleteNode(root->right, temp->m_pair->first);
                }
                return root;
            }

            BST *getnextnode(BST *key)
            {
                BST *tmp = NULL;

                if (key == NULL)
                    return NULL;
                BST *root = key;
                while (root->parent != NULL)
                {
                    root = root->parent;
                }
                while (root != NULL) 
                {
                    if (root->m_pair->first > key->m_pair->first)
                    {
                        tmp = root;
                        root = root->left;
                    }
                    else
                        root = root->right;
                }
                return (tmp);
            }

            BST *getprevnode(BST *key)
            {
                BST *tmp = NULL;

                BST *root = key;
                while (root->parent != NULL)
                {
                    root = root->parent;
                }
                while (root != NULL) 
                {
                    if (root->m_pair->first < key->m_pair->first)
                    {
                    tmp = root;
                    root = root->right;
                    }
                    else
                    root = root->left;
                }
                return (tmp);
            }

            BST *treecopy(BST *key)
            {
                if (key == NULL)
                    return (NULL);
                BST *tmp = new BST(*key->m_pair, key->c, key->allocc);
                if (key->right)
                {
                    tmp->right = treecopy(key->right);
                    tmp->right->parent = tmp;
                }
                if (key->left)
                {
                    tmp->left = treecopy(key->left);
                    tmp->left->parent = tmp;
                }
                return (tmp);
            }

            size_type size(BST* key)
            {
                size_type i = 0;

                if (key != NULL)
                    i++;
                if (key->right != NULL)
                    i += size(key->right);
                if (key->left != NULL)
                    i += size(key->left);
                return i;
            }

            iterator begin()
            {
                return (this);
            }
            iterator end()
            {
                return (maxkey(this));
            }
    };



    template <class K, class T,class Compare = less<K>, class Alloc = allocator<ft::pair<const K,T> > >
    class map{
        public :
            typedef K                                                   key_type;
            typedef T                                                   mapped_type;
            typedef pair<const key_type, mapped_type>                   value_type;
            typedef Compare                                             key_compare;
            typedef Alloc                                               allocator_type;
            typedef value_type&                                         reference;
            typedef const value_type&                                   const_reference;

            typedef BST<key_type, mapped_type, Compare, allocator_type>   __base;

            typedef allocator_traits<allocator_type>         	         alloc_traits;
            typedef typename alloc_traits::pointer                      pointer;
            typedef typename alloc_traits::const_pointer                const_pointer;
            typedef typename alloc_traits::size_type                    size_type;
            typedef typename alloc_traits::difference_type              difference_type;

            typedef ft::mapiter<typename __base::P, pointer>	        iterator;
            typedef ft::mapiter<typename __base::P, const_pointer>	    const_iterator;
            typedef ft::reverse_iterator<iterator>       		        reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>   		        const_reverse_iterator;
        private :
            size_type   n;
            __base     tree;

            allocator_type allocc;
            Compare     c;
        public :

            map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()) : n(0), c(comp), allocc(alloc), tree(c, allocc) {}

            template <class InputIterator>
            map (InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()): n(0), c(comp), allocc(alloc), tree(c, allocc)
            {
                insert (first, last);
            }

            map (const map& x) : tree(x.tree)
            {
                
            }
    };
}