#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Tnode {
  string word;
  int count;
  Tnode *left;
  Tnode *right;
};

// add nodes to a tree of word counts
Tnode add_node(const string &s, const int n);

// write out the tree, in alphabetical order
void print_tree(Tnode *root, map<string, int> &words);

// made possible by putting the word counts in a sorted map
void mapify_tree(Tnode *node, map<string, int> &words);

int main() {
  Tnode root = add_node("Class", 1);
  Tnode left_child = add_node("Abstract Class", 2);
  Tnode right_child = add_node("Concrete Class", 3);

  root.left = &left_child;
  root.right = &right_child;

  map<string, int> words;
  print_tree(&root, words);
}

Tnode add_node(const string &s, const int n) {
  return {s, n, nullptr, nullptr};
}

void print_tree(Tnode *root, map<string, int> &words) {
  mapify_tree(root, words);
  for (const auto &x : words)
    cout << x.first << '\t' << x.second << '\n';
}

void mapify_tree(Tnode *node, map<string, int> &words) {
  auto q = words.find(node->word);
  if (q == words.end()) {
    words.insert(make_pair(node->word, node->count));
  }
  if (node->left != nullptr)
    mapify_tree(node->left, words);
  if (node->right != nullptr)
    mapify_tree(node->right, words);
}
