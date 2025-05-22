1. XÂY DỰNG CÂY MAX HEAP. 

Mảng hiện tại: [2, 19, 38, 29, 66, 64, 72, 3, 16, 89, 15, 37, 20, 28, 73, 5]
Quá trình Heapify-Down:
- i = 7 (Giá trị 3):
Con trái (2*7+1 = 15): 5
Con phải (2*7+2 = 16): Không có
3 < 5. Swap 3 và 5.
Array: [2, 19, 38, 29, 66, 64, 72, 5, 16, 89, 15, 37, 20, 28, 73, 3]

- i = 6 (Giá trị 72):
Con trái (13): 28
Con phải (14): 73
72 < 73. Swap 72 và 73.
Array: [2, 19, 38, 29, 66, 64, 73, 5, 16, 89, 15, 37, 20, 28, 72, 3]

- i = 5 (Giá trị 64):
Con trái (11): 37
Con phải (12): 20
64 > 37 và 64 > 20. Không swap. Max heap property giữ.
Array: [2, 19, 38, 29, 66, 64, 73, 5, 16, 89, 15, 37, 20, 28, 72, 3]

- i = 4 (Giá trị 66):
Con trái (9): 89
Con phải (10): 15
66 < 89. Swap 66 và 89.
Array: [2, 19, 38, 29, 89, 64, 73, 5, 16, 66, 15, 37, 20, 28, 72, 3]

- i = 3 (Giá trị 29):
Con trái (7): 5
Con phải (8): 16
29 > 16 và 29 > 5. Không swap.
Array: [2, 19, 38, 29, 89, 64, 73, 5, 16, 66, 15, 37, 20, 28, 72, 3]

- i = 2 (Giá trị 38):
Con trái (5): 64
Con phải (6): 73
38 < 73. Swap 38 và 73.
Array: [2, 19, 73, 29, 89, 64, 38, 5, 16, 66, 15, 37, 20, 28, 72, 3]

- i = 1 (Giá trị 19):
Con trái (3): 29
Con phải (4): 89
19 < 89. Swap 19 và 89.
Array: [2, 89, 73, 29, 19, 64, 38, 5, 16, 66, 15, 37, 20, 28, 72, 3]
Giá trị 19 (hiện ở chỉ số 4) cần tiếp tục heapify-down.
Con trái (9): 66
Con phải (10): 15
19 < 66. Swap 19 và 66.
Array: [2, 89, 73, 29, 66, 64, 38, 5, 16, 19, 15, 37, 20, 28, 72, 3]

- i = 0 (Giá trị 2):
Con trái (1): 89
Con phải (2): 73
2 < 89. Swap 2 và 89.
Array: [89, 2, 73, 29, 66, 64, 38, 5, 16, 19, 15, 37, 20, 28, 72, 3]
Giá trị 2 (hiện ở chỉ số 1) cần tiếp tục heapify-down.
Con trái (3): 29
Con phải (4): 66
2 < 66. Swap 2 và 66.
Array: [89, 66, 73, 29, 2, 64, 38, 5, 16, 19, 15, 37, 20, 28, 72, 3]
Giá trị 2 (hiện ở chỉ số 4) cần tiếp tục heapify-down.
Con trái (9): 19
Con phải (10): 15
2 < 19. Swap 2 và 19.
Array: [89, 66, 73, 29, 19, 64, 38, 5, 16, 2, 15, 37, 20, 28, 72, 3]

                                   89
                              /           \
                           66              73
                         /    \         /    \
                       29      19      64     38
                      /  \    /  \    /  \   /  \
                     5   16  2   15  37  20  28  72
                    /
                   3

2. CHÈN SỐ VÀO CÂY HEAP

Mảng hiện tại: [89, 66, 73, 29, 19, 64, 38, 5, 16, 2, 15, 37, 20, 28, 72, 3]
- Chèn 5:
Thêm 5 vào cuối: [..., 72, 3, 5] (index 16)
heapify-up 5 (từ index 16, cha là 5 ở index 7). 5 không lớn hơn 5. Dừng.
Array: [89, 66, 73, 29, 19, 64, 38, 5, 16, 2, 15, 37, 20, 28, 72, 3, 5] (size = 17)

- Chèn 13:
Thêm 13 vào cuối: [..., 3, 5, 13] (index 17)
heapify-up 13 (từ index 17, cha là 16 ở index 8). 13 không lớn hơn 16. Dừng.
Array: [89, 66, 73, 29, 19, 64, 38, 5, 16, 2, 15, 37, 20, 28, 72, 3, 5, 13] (size = 18)

- Chèn 9:
Thêm 9 vào cuối: [..., 5, 13, 9] (index 18)
heapify-up 9 (từ index 18, cha là 16 ở index 8). 9 không lớn hơn 16. Dừng.
Array: [89, 66, 73, 29, 19, 64, 38, 5, 16, 2, 15, 37, 20, 28, 72, 3, 5, 13, 9] (size = 19)

- Chèn 7:
Thêm 7 vào cuối: [..., 13, 9, 7] (index 19)
heapify-up 7 (từ index 19, cha là 2 ở index 9). 7 > 2. Swap.
Array: [89, 66, 73, 29, 19, 64, 38, 5, 16, 7, 15, 37, 20, 28, 72, 3, 5, 13, 9, 2]
Tiếp tục heapify-up 7 (từ index 9, cha là 19 ở index 4). 7 không lớn hơn 19. Dừng.
Array: [89, 66, 73, 29, 19, 64, 38, 5, 16, 7, 15, 37, 20, 28, 72, 3, 5, 13, 9, 2] (size = 20)

- Chèn 24:
Thêm 24 vào cuối: [..., 9, 2, 7, 24] (index 20)
heapify-up 24 (từ index 20, cha là 7 ở index 9). 24 > 7. Swap.
Array: [89, 66, 73, 29, 19, 64, 38, 5, 16, 24, 15, 37, 20, 28, 72, 3, 5, 13, 9, 2, 7]
Tiếp tục heapify-up 24 (từ index 9, cha là 19 ở index 4). 24 > 19. Swap.
Array: [89, 66, 73, 29, 24, 64, 38, 5, 16, 19, 15, 37, 20, 28, 72, 3, 5, 13, 9, 2, 7]
Tiếp tục heapify-up 24 (từ index 4, cha là 66 ở index 1). 24 không lớn hơn 66. Dừng.
Array: [89, 66, 73, 29, 24, 64, 38, 5, 16, 19, 15, 37, 20, 28, 72, 3, 5, 13, 9, 2, 7] (size = 21)

- Chèn 4:
Thêm 4 vào cuối: [..., 2, 7, 4] (index 21)
heapify-up 4 (từ index 21, cha là 15 ở index 10). 4 không lớn hơn 15. Dừng.
Array: [89, 66, 73, 29, 24, 64, 38, 5, 16, 19, 15, 37, 20, 28, 72, 3, 5, 13, 9, 2, 7, 4] (size = 22)

- Chèn 6:
Thêm 6 vào cuối: [..., 7, 4, 6] (index 22)
heapify-up 6 (từ index 22, cha là 15 ở index 10). 6 không lớn hơn 15. Dừng.
Array: [89, 66, 73, 29, 24, 64, 38, 5, 16, 19, 15, 37, 20, 28, 72, 3, 5, 13, 9, 2, 7, 4, 6] (size = 23)

                                       89
                              /                    \
                           66                        73
                         /    \                    /    \
                       29      24                 64     38
                      /  \    /  \              /  \   /    \
                     5   16  19   15           37   20 28    72
                    / \  / \ / \  / \         
                   3  5 13  9 2  7 4  6