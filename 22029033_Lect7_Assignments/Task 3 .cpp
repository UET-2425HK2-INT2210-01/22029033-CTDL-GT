#include <iostream>     // Thư viện nhập xuất chuẩn

using namespace std;

// Hàm đệ quy tính ước chung lớn nhất (GCD) của hai số nguyên
int gcd(int x, int y)
{
    if (y == 0)
    {
        return x;       // Nếu y = 0 thì GCD là x
    }
    return gcd(y, x % y); // Gọi đệ quy với (y, x % y)
}

int main()
{
    int x, y; // Khai báo hai biến nguyên X và Y

    // Nhập hai số nguyên từ bàn phím
    cout << "Nhap X: ";
    cin >> x;
    cout << "Nhap Y: ";
    cin >> y;

    // Tìm và in ra ước chung lớn nhất
    cout << "Uoc chung lon nhat la: " << gcd(x, y) << endl;

    return 0; // Kết thúc chương trình
}
