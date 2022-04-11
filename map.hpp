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
            typedef ft::pair<K, T>                                  value_type;
            typedef Alloc 						                    allocator_type;
            typedef Compare                                         key_compare;
            typedef allocator_traits<allocator<BST> >         	    __alloc_traits;
            typedef typename __alloc_traits::difference_type		difference_type;
            typedef typename allocator_traits<Alloc>::pointer       pointer;
            typedef typename allocator_traits<Alloc>::size_type     size_type;
            typedef typename __alloc_traits::pointer                P;
            typedef ft::mapiter<P, pointer>			                iterator;

        public:
            value_type *m_pair;
            BST *left, *right, *parent;
            allocator_type allocc;
            Compare     c;
        public :

            BST(const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type()): m_pair(NULL), left(NULL), right(NULL), parent(NULL), allocc(alloc), c(comp) {
                  m_pair = allocc.allocate(1);
              }
            BST(K first,T second, const key_compare& comp= key_compare(),
                const allocator_type& alloc= allocator_type()) 
                : m_pair(NULL), left(NULL), right(NULL), parent(NULL), allocc(alloc), c(comp)
            {
                m_pair = allocc.allocate(1);
                allocc.construct(m_pair, first, second);
            }

            BST(const value_type &pair, const key_compare& comp= key_compare(),
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

            BST& operator= (BST& x)
            {  
                BST* tmp;
                clear(this);
                tmp = treecopy(&x);
                m_pair = tmp->m_pair;
                left = tmp->left;
                right = tmp->right;
                return (*this);
            }
            BST *find(K key, BST* tmp)
            {
                BST *root = tmp;
				if (tmp == NULL)
					return NULL;
                while (root->parent != NULL)
                {
                    root = root->parent;
                }
                root = root->right;
                while (root)
                {
                    if (root->m_pair->first == key)
                        return (root);
                    if (key < root->m_pair->first)
                        root = root->left;
                    else
                        root = root->right;
				}
                return (NULL);
            }

            BST*   insert(BST* root, const value_type &pair)
            {
                if (find(pair.first, root)!= NULL)
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
                if (find(first, root) != NULL)
                    return (NULL);
                if (!root) {
                    return new BST(first, second, c, allocc);
                }
                if (root->m_pair->first < first){
                    root->right = insert(root->right, first, second);
                    root->right->parent = root;
                }
                else {
                    root->left = insert(root->left, first, second);
                    root->left->parent = root;
                }
            
                return root;
            }

            BST*    maxkey(BST* root)
            {
                BST *current = root;

                
                if (current)
                while (current->parent  != NULL)
                {
                    current = current->parent;
                }
                current = current->right;
                while (current && current->right != NULL)
                {
                    current = current->right;
                }
                return current;
            }

            BST*    minkey(BST* root)
            {
                BST *current = root;
                
                if (current)
                while (current->parent != NULL)
                {
                    current = current->parent;
                }
                current = current->right;
                while (current && current->left != NULL)
                {
                    current = current->left;
                }
                return current;
            }

            BST*    mink(BST* root)
            {
                BST *current = root;

                while (current && current->left != NULL)
                {
                    current = current->left;
                }
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
                    temp = mink(root->right);

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
                root = root->right;
                while (root != NULL) 
                {
                    if (!c(root->m_pair->first, key->m_pair->first))
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
                root = root->right;
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

                if (key != NULL && key->m_pair != NULL)
                    i++;
                if (key->right != NULL)
                    i += size(key->right);
                if (key->left != NULL)
                    i += size(key->left);
                return i;
            }

            void clear(BST * root)
            {
                if (root == NULL || root->parent == NULL)
                    return ;
                if (root->left != NULL)
                    clear(root->left);
                if (root->right != NULL)
                    clear(root->right);
                delete root;
            }
            iterator begin(BST* root)
            {
                return (minkey(root));
            }
            iterator end(BST* root)
            {
                while (root->parent != NULL)
                {
                    root = root->parent;
                }
                return (root);
            }
    };



    template <class K, class T,class Compare = less<K>, class Alloc = allocator<ft::pair<K,T> > >
    class map{
        public :
            typedef K                                                   key_type;
            typedef T                                                   mapped_type;
            typedef ft::pair<key_type, mapped_type>                   value_type;
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

            typedef typename __base::iterator               	        iterator;
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
              const allocator_type& alloc = allocator_type()) : n(0), c(comp), allocc(alloc), tree(c, allocc) {
                   
              }

            template <class InputIterator>
            map (InputIterator first, InputIterator last,
                const key_compare& comp = key_compare(),
                const allocator_type& alloc = allocator_type()): n(0), c(comp), allocc(alloc), tree(c, allocc)
            {
                insert (first, last);
				n = tree.size(tree);
            }

            map (const map& x) : tree(x.tree)
            {
                n = tree.size(tree);
            }

			~map(){}

			map& operator= (const map& x)
            {
                tree = x.tree;
                n = tree.size(tree);
                return *this;
            }

            bool empty() const
            {
                if (n == 0)
                    return true;
                return false;
            }

            size_type size() const
            {
                return n;
            }

            iterator begin()
            {
                return tree.minkey(tree.right);
            }

            iterator end()
            {
                return &tree;
            }
            

            mapped_type& operator[] (const key_type& k)
            {
                __base *tmp = tree.find(k, tree.right);
                if (tmp == NULL)
                {
                    tree.right = tree.insert(tree.right, k, mapped_type());
                    tree.right->parent = &tree;
                    tmp = tree.find(k, tree.right);
                }
                return (tmp->m_pair->second);
            }

            pair<iterator,bool> 
            insert (const value_type& val)
            {
                if ((tree.right = tree.insert(tree.right, val)) == NULL)
                {
                    return (ft::make_pair<iterator,bool>(NULL, false));
                }
                tree.right->parent = &tree;
                n++;
                iterator it = tree.find(val.first, &tree);
                return (ft::make_pair<iterator,bool>(it, true));
            }

            iterator insert (iterator position, const value_type& val)
            {
                tree.right =tree.insert(&tree.find(position->first), val);
                tree.right->parent = &tree;
                n++;
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    tree.right = tree.insert(tree, first->first, first->second);
                    n++;
                    tree.right->parent = &tree;
                    first++;
                }
            }

    };
}