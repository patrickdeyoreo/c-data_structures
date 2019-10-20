# Trash Table
## Hybrid of a Binary Search Tree and a Hash Table

This data structure combines a self-balancing binary search tree with a collision resistant hash table in an attempt to reap benefits of each.
The hash table is implemented using chaining for collisions resolution. Keys are hashed using the djb2 algo.
The BST is implemented as a red-black tree.
