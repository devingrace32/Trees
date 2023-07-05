# Trees
The following files contain the declaration and definition files as well as a testing file. 
I added one helper function inTree to determine if a key was in the tree. This was called in the path_to function. 
I used reccursion to call inTree and node_at for a faster runtime. 
The only function's definition worth explaining if the path_to function. To do this, I traversed the tree if the key was in the tree. 
At each node, I checked if the left existed and if it contained the key, if so traverse right. Else, traverse left. 
I built my program without using a makefile since the compile time for the three relatively small files was quite short.
To build the program simply use "g++ -o3 -Wall -Wextra -pedantic tree.hh tree.cc test_tree.cc -o tree"

Using Valgrind there are no memory leaks. 
