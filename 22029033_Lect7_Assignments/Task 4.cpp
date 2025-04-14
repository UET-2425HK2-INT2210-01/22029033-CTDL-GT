#include <iostream>     // Thư viện nhập xuất chuẩn
#include <vector>       // Thư viện sử dụng vector
#include <cmath>        // Thư viện dùng để tính lũy thừa (pow)

using namespace std;
int main() {
    int n;  // Biến lưu độ dài của chuỗi nhị phân
    cin >> n;// Nhập số nguyên n từ bàn phím

    // Tổng số chuỗi nhị phân độ dài n là 2^n
    int total = pow(2, n);

    // Duyệt qua tất cả các số từ 0 đến 2^n - 1
    for (int i = 0; i < total; ++i)
    {
        // Duyệt từng bit của số i từ trái sang phải
        for (int j = n - 1; j >= 0; --j)
        {
            // Dịch bit sang phải j vị trí và lấy phần dư cho 2
            cout << ((i >> j) & 1);
        }
        cout << endl; // Xuống dòng sau mỗi chuỗi nhị phân
    }

    return 0; // Kết thúc chương trình
}
