* VẼ HEAP TREE THEO MIN HEAP
- Cây min heap:
         1
       /   \
      2      7
     / \    /  \
    6   3  10    8
   / \       
  13  20       
- Insert 14, 0, 35:
              0
          /       \
        1           7
     /    \       /  \
   6      2     10    8
  / \    / \    /
13  20  14  3  35 
- Delete 6, 13, 35:
            0
        /       \
       1         7
     /   \      /  \
    3     2   10    8
  /  \        
14   20   

* VẼ HEAP TREE THEO MAX HEAP
- Cây max heap:
          20
       /      \
      13       8
    /   \     /  \
  10     3   2    7
 /  \
1    6
- Insert 14, 0, 35:
           35
       /        \
      14         20
    /    \      /  \
  10      13   8    7
 /  \     / \
1    6   3   0
- Delete 6, 13, 35:
          20
       /      \
      14       8
    /    \    /  \
  10      3  0    7
 /  
1   