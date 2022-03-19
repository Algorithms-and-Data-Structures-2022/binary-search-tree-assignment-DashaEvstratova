#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* curr = find(key, root_);
    if (curr == nullptr){
      return std::nullopt;
    }
    return curr->value;
  }

  bool BinarySearchTree::Contains(int key) const {
    if (Find(key) == std::nullopt){
      return false;
    }
    return true;
  }

  bool BinarySearchTree::IsEmpty() const {
    return root_ == nullptr;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }
    Node* curr = root_;
    while(curr->left != nullptr){
      curr = curr->left;
    }
    return curr->value;
  }
  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ == nullptr) {
      return std::nullopt;
    }
    Node* curr = root_;
    while(curr->right != nullptr){
      curr = curr->right;
    }
    return curr->value;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node == nullptr){
      Node* newNode = new Node(key, value);
      node = newNode;
    }
    else {
      if (key > node->key) {
        insert(key, value, node->right);
      } else if (key < node->key) {
        insert(key, value, node->left);
      } else if (key = node->key) {
        node->value = value;
      }
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node == nullptr){
        return node;
      }
      if (key < node->key){
        remove(key, node->left);
      }
      else if (key > node->key) {
        remove(key, node->right);
      }else if (node->left != nullptr && node->right != nullptr){
        node->key = find_min(node->right)->key;
        remove(node->key, node->right);}
      else{
        if (node->left != nullptr){
          node = node->left;}
        else if (node->right != nullptr){
          node = node->right;}
        else{
          node = nullptr;}}
      return node;
  }

  void BinarySearchTree::clear(Node* node) {
    if (node!= nullptr) {
      clear(node->left);
      clear(node->right);
    }
    delete node;
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node== nullptr){
      return nullptr;
    }
    if (node->key == key){
      return node;
    }
    if (key<node->key){
      return find(key, node->left);
    }
    if (key>node->key){
      return find(key, node->right);
    }
    return nullptr;
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    while(node->left != nullptr){
      node = node->left;
    }
    return node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    return nullptr;
  }

}  // namespace assignment