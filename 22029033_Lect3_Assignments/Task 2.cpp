1. GIẢ MÃ: ĐỘ PHỨC TẠP O(logn) - Đệ quy

int PowerRecursive(int n) 
{
    if (n == 0)
        return 1;
    
    int halfPower = PowerRecursive(n / 2);
    
    if (n % 2 == 0)
        return halfPower * halfPower;
    else
        return 2 * halfPower * halfPower;
}

2. GIẢ MÃ: ĐỘ PHỨC TẠP O(1) - Dịch bit

int PowerConstant(int n) 
{
    return (1 << n);
}
