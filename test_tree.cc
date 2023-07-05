#include <iostream>
#include <assert.h>
#include "tree.hh"
void tree0(){  //tree with no nodes
        assert(node_at(nullptr, "R") == nullptr);
        assert(node_at(nullptr, "L") == nullptr);
        assert(node_at(nullptr, "") == nullptr);
        assert(node_at(nullptr, "RF") == nullptr);
        std::cout <<"Passed Tree0\n";
}
void tree1(){  //tree with one node
        tree_ptr_t myTree = create_tree(2, 1, nullptr, nullptr);
        
        assert(path_to(myTree,2)=="");
        
        assert(node_at(myTree, "R") == nullptr);
        assert(node_at(myTree, "L") == nullptr);
        assert(node_at(myTree, "") == myTree);
        assert(node_at(nullptr, "RF") == nullptr);
        
        destroy_tree(myTree);
        std::cout << "Passed Tree1\n";
        
}
void tree2(){   //tree in .hh file
    tree_ptr_t child1 = create_tree(9,0,nullptr,nullptr);
    tree_ptr_t child3= create_tree(12,0,nullptr,nullptr);
    tree_ptr_t child5= create_tree(3,0,nullptr,nullptr);
    tree_ptr_t child2 = create_tree(6,0,child1,nullptr);
    tree_ptr_t child4= create_tree(-5,0,child3,child2);
    tree_ptr_t child6= create_tree(12,0,child5,nullptr);
    tree_ptr_t myTree = create_tree(126,0,child4,child6);
    
    assert(path_to(myTree, 126) == "");
    assert(path_to(myTree, 12) == "LL");
    assert(path_to(myTree, -5) == "L");
    assert(path_to(myTree, 6) == "LR");

    assert(node_at(myTree, "") == myTree);
    assert(node_at(myTree, "L") == child4);
    assert(node_at(myTree, "R") == child6);
    assert(node_at(myTree, "LR") == child2);
    assert(node_at(myTree, "LLL") == nullptr);
    assert(node_at(myTree, "RR") == nullptr);
    
    destroy_tree(myTree);
    std::cout << "Passed Tree2\n";
    
}
void tree3(){
	tree_ptr_t child1 = create_tree(1, 1, nullptr, nullptr);
	tree_ptr_t child2 = create_tree(1, 1, nullptr, nullptr);
	tree_ptr_t child3 = create_tree(1, 1, child1, child2);
	tree_ptr_t myTree = create_tree(1, 1, child3, nullptr);
	assert(path_to(myTree, 1) == "LL");

	assert(node_at(myTree, "R") == nullptr);
	assert(node_at(myTree, "LR") == child2);
	assert(node_at(myTree, "LLL") == nullptr);

	assert(path_to(myTree, 1) == "LL");
	destroy_tree(myTree);

	std::cout << "Passed Tree3\n";
}
int main(){
        tree0();
        tree1();
        tree2();
	tree3();
}




 

