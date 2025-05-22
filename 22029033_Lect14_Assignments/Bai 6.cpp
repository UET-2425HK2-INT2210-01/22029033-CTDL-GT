1. ĐỀ XUẤT HÀM BĂM VÀ KÍCH THƯỚC BẢNG BĂM
- Hàm băm: h(key) = key % m ( Trong đó key là ID của sinh viên; m là kích thước của bảng băm. )
- Chọn kích thước bảng băm m:
Có 8 sinh viên. Để giảm thiểu va chạm và có hiệu suất tốt, m nên là một số nguyên tố và lớn hơn số lượng phần tử một chút.
Chúng ta có thể chọn m = 11. (Các số nguyên tố gần 8: 7, 11, 13...). Chọn 11 sẽ cung cấp đủ không gian và phân tán tốt hơn.
=> Hàm băm được đề xuất là: h(id) = id % 11
- Tính toán giá trị băm cho từng sinh viên:

(7, An): h(7) = 7 % 11 = 7
(3, Be): h(3) = 3 % 11 = 3
(11, Cu): h(11) = 11 % 11 = 0
(4, Da): h(4) = 4 % 11 = 4
(8, Gi): h(8) = 8 % 11 = 8
(16, En): h(16) = 16 % 11 = 5
(21, Ba): h(21) = 21 % 11 = 10
(5, Go): h(5) = 5 % 11 = 5 (VA CHẠM! Khóa 5 và 16 cùng băm vào vị trí 5)

2. VẼ BẢNG BĂM VỚI PHƯƠNG PHÁP LIÊN KẾT RIÊNG BIỆT
Hash Table (Size = 11)

Index 	     Danh sách liên kết
[0] 	--> 	(11, Cu)
[1] 	--> 	NULL
[2] 	--> 	NULL
[3] 	--> 	(3, Be)
[4] 	--> 	(4, Da)
[5] 	--> 	(16, En) --> (5, Go)  (đã xảy ra va chạm, 5 được thêm vào sau 16)
[6] 	--> 	NULL
[7] 	--> 	(7, An)
[8] 	--> 	(8, Gi)
[9] 	--> 	NULL
[10] 	--> 	(21, Ba)

3. VẼ BẢNG BĂM VỚI PHƯƠNG PHÁP ĐỊA CHỈ MỞ - DÒ TUYẾN TÍNH
Hash Table (Size = 11) using Linear Probing

(7, An): h(7) = 7. Slot [7] trống. Bảng: [ , , , , , , , (7,An), , , ]
(3, Be): h(3) = 3. Slot [3] trống. Bảng: [ , , , (3,Be), , , , (7,An), , , ]
(11, Cu): h(11) = 0. Slot [0] trống. Bảng: [(11,Cu), , , (3,Be), , , , (7,An), , , ]
(4, Da): h(4) = 4. Slot [4] trống. Bảng: [(11,Cu), , , (3,Be), (4,Da), , , (7,An), , , ]
(8, Gi): h(8) = 8. Slot [8] trống. Bảng: [(11,Cu), , , (3,Be), (4,Da), , , (7,An), (8,Gi), , ]
(16, En): h(16) = 5. Slot [5] trống. Bảng: [(11,Cu), , , (3,Be), (4,Da), (16,En), , (7,An), (8,Gi), , ]
(21, Ba): h(21) = 10. Slot [10] trống. Bảng: [(11,Cu), , , (3,Be), (4,Da), (16,En), , (7,An), (8,Gi), , (21,Ba)]
(5, Go): h(5) = 5. Slot [5] đã chứa (16, En). VA CHẠM!
Dò tìm tuyến tính:
Thử (5+1) % 11 = 6. Slot [6] trống.
Chèn (5, Go) vào Slot [6].
=> Bảng cuối cùng: [(11,Cu), EMPTY, EMPTY, (3,Be), (4,Da), (16,En), (5,Go), (7,An), (8,Gi), EMPTY, (21,Ba)]