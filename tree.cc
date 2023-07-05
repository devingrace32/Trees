//definition of tree.hh file. A simple recursive data structure to hold keys and values.
#include "tree.hh"
#include <string>
#include <assert.h>

//////////////////////////////////////////////////////////////////////////////
// create_tree allocates space for a new tree node and fills it with the given
// data parameters. By default, the tree is a leaf, so its children point to
// nullptr, but you may override with actual pointers to other nodes.
tree_ptr_t create_tree(const key_t& key,
                       const value_t& value,
                       tree_ptr_t left,
                       tree_ptr_t right){
         tree_ptr_t tree_ptr_ = new Tree();
	 tree_ptr_ -> key_ = key;
	 tree_ptr_ -> value_ = value;
	 tree_ptr_ ->left_ = left;
	 tree_ptr_ -> right_ = right;
	 return tree_ptr_;
}


//////////////////////////////////////////////////////////////////////////////
// Deallocate all space consumed by this tree and its children.
void destroy_tree(tree_ptr_t tree){
	if(tree){ //if tree exists recursively delete tree
		destroy_tree(tree->left_);
		destroy_tree(tree->right_);
		delete tree;
	}
	

}
bool inTree(tree_ptr_t, key_t);  //helper function to see if a key is in a tree
bool inTree(tree_ptr_t tree, key_t key){
	if(tree->key_ == key)
		return true;
	if(tree ->left_){
		if(inTree(tree->left_, key))
			return inTree(tree->left_, key);
	}
	if(tree ->right_){
		if(inTree(tree->right_, key))
			return inTree(tree->right_, key);
	}
	return false;
}
//////////////////////////////////////////////////////////////////////////////
// path_to: return a string representing the path taken from a given tree root
// to a given key in the tree. For each left child taken along the path, the
// string contains an 'L' character, and 'R' for a right child, in order.
// So for example for the following tree (only keys depicted, values omitted):
/*
            126
           /   \
          /     \
        -5       12
        / \     /
      12   6    3
          /
         9
*/
// path_to(tree, 9) will return "LRL", path_to(tree, 3) will return "R", and
// path_to(126) will return "".
// If the key isn't found in the tree, path_to should abort the program using an
// assert() call.
//
// If multiple matches to key exist in the tree, return the path to the
// leftmost match. For the tree above, path_to(tree, 12) returns "LL".
std::string path_to(tree_ptr_t tree, key_t key){
	std::string path = "";
	if(inTree(tree, key)){
		while(tree){
			if(tree -> left_ && inTree(tree ->left_, key)){
				tree = tree ->left_;
				path = path + "L";
			}
			else if(tree ->right_ && inTree(tree ->right_, key)){
				tree = tree ->right_;
				path = path + "R";
			}
			else if(tree -> key_ == key){
				return path;
			}
		}
		return path;
	}
	else
		assert(false);
}


//////////////////////////////////////////////////////////////////////////////
// node_at: Follow a path from a given root node and return the node that is
// at the end of the path. For example, for the root of the tree above,
// node_at("LR") will return a pointer to the node whose key is 6.
// If the path leads to an invalid or empty child, or contains any character
// other than 'L' or 'R', return nullptr (don't crash)
tree_ptr_t node_at(tree_ptr_t tree, std::string path){
	if(path.length() == 0 || tree == nullptr){
		return tree;
	}
	char ch = path[0];
	path.erase(0,1);
	if(ch == 'L'){
		return node_at(tree->left_, path);
	}
	if(ch == 'R'){
		return node_at(tree->right_, path);
	}
	else{
		return nullptr;
	}
		

}



