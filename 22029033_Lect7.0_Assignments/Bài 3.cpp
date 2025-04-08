// Hàm đệ quy tính số Fibonacci thứ n
int fibonacci(int n) 
{
    if (n == 0) // Trường hợp: F(0) = 0
        return 0;
    else if (n == 1) // Trường hợp: F(1) = 1
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2); // Gọi đệ quy: F(n) = F(n-1) + F(n-2)
}
