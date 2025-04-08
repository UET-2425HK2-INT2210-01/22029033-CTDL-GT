// Hàm đệ quy để đếm số chữ số của một số nguyên dương n
int demChuSo(int n) 
{
    if (n < 10) // Trường hợp: Nếu n < 10 thì chỉ có 1 chữ số
        return 1;
    else
        return 1 + demChuSo(n / 10); // Gọi đệ quy: bỏ bớt 1 chữ số (chia 10), cộng thêm 1
}
