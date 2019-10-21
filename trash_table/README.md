# Trash Table
## Hybrid of a Binary Tree and a Hash Table

This data structure combines a self-balancing binary search tree with a collision resistant hash table in an attempt to reap benefits of both.

The hash table is implemented using chaining to resolve collisions. Keys are hashed using the djb2 algo.

The tree is implemented as a red-black tree.
