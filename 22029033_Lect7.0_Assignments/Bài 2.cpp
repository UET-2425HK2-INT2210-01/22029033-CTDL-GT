// Hàm đệ quy tính giai thừa của một số nguyên dương n
int giaithua(int n) 
{
    if (n == 1) // Điều kiện dừng: nếu n bằng 1 thì giai thừa là 1
        return 1;
    else
        return n * giaithua(n - 1); // Gọi đệ quy: n! = n * (n - 1)!
}
