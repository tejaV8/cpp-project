#include <iostream>

using namespace std;

struct node
{
  int data;
  struct node *left, *right;
};

struct node *root = NULL, *New_node, *cur, *parent;

void create()
{
  New_node = new node();
  cout << "Enter data: ";
  cin >> New_node->data;
  New_node->left = NULL;
  New_node->right = NULL;
}

void insert()
{
  create();
  if (root == NULL)
  {
    root = New_node;
    cout << "Node " << New_node->data << " inserted." << endl;
    return;
  }
  else
  {
    cur = root;
    while (cur != NULL)
    {
      if (New_node->data < cur->data)
      {
        if (cur->left != NULL)
        {
          cur = cur->left;
        }
        else
        {
          cur->left = New_node;
          cout << "Node " << New_node->data << " inserted." << endl;
          return;
        }
      }
      else if (New_node->data > cur->data)
      {
        if (cur->right != NULL)
        {
          cur = cur->right;
        }
        else
        {
          cur->right = New_node;
          cout << "Node " << New_node->data << " inserted." << endl;
          return;
        }
      }
      else
      {
        // Duplicate node logic
        cout << "Duplicate node " << New_node->data << " not inserted." << endl;
        delete New_node;
        return;
      }
    }
  }
}

void deleteNode(int ele)
{
  if (root == NULL)
  {
    cout << "Tree is empty." << endl;
    return;
  }
  else
  {
    cur = root;
    parent = NULL;

    while (cur != NULL && cur->data != ele)
    {
      parent = cur;

      if (ele < cur->data)
      {
        cur = cur->left;
      }
      else
      {
        cur = cur->right;
      }
    }

    if (cur == NULL)
    {
      cout << "Element not found." << endl;
      return;
    }
    else
    {
      // Deletion of Leaf Node
      if (cur->left == NULL && cur->right == NULL)
      {
        if (cur == root)
        {
          root = NULL;
        }
        else if (parent->left == cur)
        {
          parent->left = NULL;
        }
        else
        {
          parent->right = NULL;
        }
        cout << "Node " << ele << " deleted." << endl;
        delete cur;
      }

      // Deletion of Node with one child - right
      else if (cur->left == NULL && cur->right != NULL)
      {
        if (cur == root)
        {
          root = cur->right;
        }
        else if (parent->left == cur)
        {
          parent->left = cur->right;
        }
        else
        {
          parent->right = cur->right;
        }
        cout << "Node " << ele << " deleted." << endl;
        delete cur;
      }

      // Deletion of Node with one child - left
      else if (cur->left != NULL && cur->right == NULL)
      {
        if (cur == root)
        {
          root = cur->left;
        }
        else if (parent->left == cur)
        {
          parent->left = cur->left;
        }
        else
        {
          parent->right = cur->left;
        }
        cout << "Node " << ele << " deleted." << endl;
        delete cur;
      }

      // Deletion of Node with 2 childs using Inorder Successor
      else if (cur->left && cur->right)
      {
        struct node *IS = cur->right, *IP = NULL;

        while (IS->left != NULL)
        {
          IP = IS;
          IS = IS->left;
        }
        cur->data = IS->data;

        if (IP == NULL)
        {
          cur->right = IS->right;
        }
        else
        {
          IP->left = IS->right;
        }
        cout << "Node " << ele << " deleted." << endl;
        delete IS;
      }
    }
  }
}

void inOrderTraversal(struct node *cur)
{
  if (cur != NULL)
  {
    inOrderTraversal(cur->left);
    cout << cur->data << "->";
    inOrderTraversal(cur->right);
  }
}

void preOrderTraversal(struct node *cur)
{
  if (cur != NULL)
  {
    cout << cur->data << "->";
    preOrderTraversal(cur->left);
    preOrderTraversal(cur->right);
  }
}

void postOrderTraversal(struct node *cur)
{
  if (cur != NULL)
  {
    postOrderTraversal(cur->left);
    postOrderTraversal(cur->right);
    cout << cur->data << "->";
  }
}

void search(int ele)
{
  if (root == NULL)
  {
    cout << "Tree is empty." << endl;
  }
  else
  {
    cur = root;
    while (cur != NULL)
    {
      if (ele < cur->data)
      {
        cur = cur->left;
      }
      else if (ele > cur->data)
      {
        cur = cur->right;
      }
      else
      {
        cout << "Element Found in tree." << endl;
        return;
      }
    }
    cout << "Element not Found in tree." << endl;
  }
}

int main()
{
  int choice, val;

  cout << "---Binary Search Tree Menu---" << endl;

  cout << "\n1. Insert\n2. Delete\n3. InOrder Traversal\n4. PreOrder Traversal\n5. PostOrder Traversal\n6. Search\n7. Exit\n";

  while (true)
  {
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      insert();
      break;
    case 2:
      cout << "Enter value to delete: ";
      cin >> val;
      deleteNode(val);
      break;
    case 3:
      cout << "InOrder Traversal: ";
      inOrderTraversal(root);
      cout << endl;
      break;
    case 4:
      cout << "PreOrder Traversal: ";
      preOrderTraversal(root);
      cout << endl;
      break;
    case 5:
      cout << "PostOrder Traversal: ";
      postOrderTraversal(root);
      cout << endl;
      break;
    case 6:
      cout << "Enter value to search: ";
      cin >> val;
      search(val);
      break;
    case 7:
      cout << "Exiting..." << endl;
      return 0;
    default:
      cout << "Invalid choice.\n";
    }
  }
  return 0;
}