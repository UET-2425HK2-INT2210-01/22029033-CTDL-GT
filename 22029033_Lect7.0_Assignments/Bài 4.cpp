// Hàm đệ quy tính lũy thừa x^n với x và n là các số nguyên dương
int luythua(int x, int n) 
{
    if (n == 0) // Trường hợp: x^0 = 1
        return 1;
    else
        return x * luythua(x, n - 1); // Gọi đệ quy: x^n = x * x^(n-1)
}
