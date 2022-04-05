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

namespace ft{
    template <class K, class T,class Compare = less<K>, class Alloc = allocator<ft::pair<K,T> > >
    class BST {
         public :
            typedef ft::pair<K, T>        value_type;
            typedef Alloc 						allocator_type;
            typedef allocator_traits< allocator<BST> >         	__alloc_traits;
            typedef typename __alloc_traits::difference_type		difference_type;
            typedef typename allocator_traits<Alloc>::pointer        	pointer;
            typedef typename __alloc_traits::pointer     P;
            typedef ft::mapiter<P, pointer>			        iterator;

        public:
            value_type *m_pair;
            BST *left, *right, *parent;
            allocator_type allocc;
            Compare     c;
        public :

            BST(): m_pair(NULL), left(NULL), right(NULL), parent(NULL) {}
            BST(K first,T second,
                const allocator_type& alloc = allocator_type()) 
                : m_pair(nullptr), left(nullptr), right(nullptr), parent(NULL), allocc(alloc)
            {
                m_pair = allocc.allocate(1);
                allocc.construct(m_pair, first, second);
            }

            BST(value_type &pair,
                const allocator_type& alloc = allocator_type())
                : m_pair(nullptr), left(nullptr), right(nullptr), parent(NULL), allocc(alloc)
            {
                m_pair = allocc.allocate(1);
                allocc.construct(m_pair, pair);
            }
            ~BST()
            {
                allocc.deallocate(m_pair, 1);
            }
            BST *find(K key)
            {
                BST *root = this;
                while (root)
                {
                    if (root->m_pair->first == key)
                        return (root);
                    if (root->m_pair->first <= key)
                        root = root->left;
                    else
                        root = root->right;
                }
                return (NULL);
            }

            BST*   insert(BST* root, value_type &pair)
            {
                if (root->find(pair->first))
                    return (NULL);
                if (!root) {
                    return new BST(pair);
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
                if (root->find(first))
                    return (NULL);
                if (!root) {
                    return new BST(first, second);
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

            BST*    deleteNode(BST* root, int key)
            {
                BST     *temp;
                if (root == NULL)
                    return root;

                if (key < root->key)
                    root->left = deleteNode(root->left, key);
                else if (key > root->key)
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
                    temp = minValueNode(root->right);

                    root->key = temp->key;

                    root->right = deleteNode(root->right, temp->key);
                }
                return root;
            }

            BST *getnextnode(BST *key)
            {
                BST *tmp = NULL;

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
            iterator begin()
            {
                return (this);
            }
    };
}