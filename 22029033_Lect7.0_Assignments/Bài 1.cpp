// Hàm đệ quy tính tổng các số nguyên từ 1 đến n
int tong(int n) 
{
    if (n == 1) // Điều kiện dừng: nếu n là 1 thì trả về 1
        return 1;
    else
        return n + tong(n - 1); // Gọi đệ quy: tổng = n + tổng từ 1 đến (n - 1)
}
