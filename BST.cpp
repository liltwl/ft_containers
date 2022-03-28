#include <iostream>
#include <memory>
#include <stack>
#include <vector>
#include "vector.hpp"
#include "stack.hpp"
#include <stack>
#include <map>
#include <string>

using namespace std;

typedef struct node {
  int key;
  struct node *left, *right,*parent;
}                t_node;

struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = temp->parent = NULL;
  return temp;
}
 
struct node *insert(struct node *node, int key) {
  if (node == NULL) 
    return newNode(key);

  if (key < node->key)
  {
    node->left = insert(node->left, key);
  }
  else
  {
    node->right = insert(node->right, key);
  }
  return node;
}

void sort(struct node *node) {
  if (node == NULL) 
    return ;
  if (node->left != NULL)
    sort(node->left);
  cout << node->key << endl;
  if (node->right != NULL)
    sort(node->right);
}

struct node *minValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->left != NULL)
    current = current->left;
  return current;
}
struct node *getnextnode(struct node *node, t_node *key)
{
  t_node *tmp = NULL;

  while (node != NULL) 
  {
    if (node->key > key->key)
    {
      tmp = node;
      node = node->left;
    }
    else
      node = node->right;
  }
  return (tmp);
}


struct node *maxValueNode(struct node *node) {
  struct node *current = node;

  while (current && current->right != NULL)
    current = current->right;
  return current;
}

struct node *deleteNode(struct node *root, int key) {
  if (root == NULL)
    return root;

  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValueNode(root->right);

    root->key = temp->key;

    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

int main()
{
    t_node *n = NULL;
    int k = 1 << 2;
    // for (int i = 0; i < 5; i++)
    // {
    //   cin >> k;
    //   n = insert(n, k, n);
    // }
    //for ()
    n = insert(n, 30);
    insert(n, 20);
    insert(n, 40);
    insert(n, 70);
    insert(n, 60);
    insert(n, 80);
    cout << "*************" << endl;
    t_node *tmp = minValueNode(n);
    int i = 0;
    while(tmp != NULL)
    {
      cout << tmp->key << " " << i << endl;
      i++;
      tmp = getnextnode(n,tmp);
    }
    //sort(n);
}