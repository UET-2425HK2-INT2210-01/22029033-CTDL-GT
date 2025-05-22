1. Preorder Traversal
Quy tắc: Duyệt theo thứ tự: Nút gốc -> Cây con bên trái -> Cây con bên phải
- 39 (Gốc)
- Đi sang trái (tới 70):
70 (Gốc)
Đi sang trái (tới 53):
53 (Gốc)
Đi sang trái (tới 24):
24 (Gốc, lá)
Đi sang phải (tới 48):
48 (Gốc, lá)
Đi sang phải (tới 61):
61 (Gốc, lá)
- Đi sang phải (tới 83):
83 (Gốc)
Đi sang trái (tới 72):
72 (Gốc, lá)
Đi sang phải (tới 16):
16 (Gốc, lá)
=> Thứ tự Preorder: 39, 70, 53, 24, 48, 61, 83, 72, 16

2. Inorder Traversal
Quy tắc: Duyệt theo thứ tự: Cây con bên trái -> Nút gốc -> Cây con bên phải
- Bắt đầu từ 39, đi sâu xuống nhánh trái nhất (tới 24).
- 24 (Lá)
- Trở về cha của 24 (53), in 53.
- Đi sang phải của 53 (tới 48).
- 48 (Lá)
- Trở về cha của 48 (53). (Đã xử lý 53)
- Trở về cha của 53 (70), in 70.
- Đi sang phải của 70 (tới 61).
- 61 (Lá)
- Trở về cha của 61 (70). (Đã xử lý 70)
- Trở về cha của 70 (39), in 39.
- Đi sang phải của 39 (tới 83).
- Đi sâu xuống nhánh trái nhất của 83 (tới 72).
- 72 (Lá)
- Trở về cha của 72 (83), in 83.
- Đi sang phải của 83 (tới 16).
- 16 (Lá)
=> Thứ tự Inorder: 24, 53, 48, 70, 61, 39, 72, 83, 16

3. Postorder Traversal
Quy tắc: Duyệt theo thứ tự: Cây con bên trái -> Cây con bên phải -> Nút gốc
- Bắt đầu từ 39, đi sâu xuống nhánh trái nhất (tới 24).
- 24 (Lá)
- Trở về cha của 24 (53), đi sang phải (tới 48).
- 48 (Lá)
- Trở về cha của 48 (53). Đã xử lý các con, in 53.
- Trở về cha của 53 (70), đi sang phải (tới 61).
- 61 (Lá)
- Trở về cha của 61 (70). Đã xử lý các con, in 70.
- Trở về cha của 70 (39), đi sang phải (tới 83).
- Đi sâu xuống nhánh trái nhất của 83 (tới 72).
- 72 (Lá)
- Trở về cha của 72 (83), đi sang phải (tới 16).
- 16 (Lá)
- Trở về cha của 16 (83). Đã xử lý các con, in 83.
- Trở về cha của 83 (39). Đã xử lý các con, in 39.
=> Thứ tự Postorder: 24, 48, 53, 61, 70, 72, 16, 83, 39