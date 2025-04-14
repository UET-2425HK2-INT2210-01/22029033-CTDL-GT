#include <iostream>     // Thư viện nhập xuất chuẩn
#include <vector>       // Thư viện sử dụng vector
#include <algorithm>    // Thư viện chứa hàm next_permutation

using namespace std;
int main()
{
    int n;  // Biến lưu độ dài hoán vị
    cin >> n;   // Nhập số nguyên n từ bàn phím

    // Tạo một vector chứa các số từ 1 đến n
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = i + 1; // Gán giá trị từ 1 đến n vào vector
    }

    // Sắp xếp vector theo thứ tự tăng dần (bắt đầu hoán vị từ nhỏ nhất)
    sort(a.begin(), a.end());

    // Duyệt qua tất cả các hoán vị của vector a
    do
    {
        // In ra một hoán vị trên một dòng
        for (int i = 0; i < n; ++i)
        {
            cout << a[i];  // In phần tử thứ i
        }
        cout << endl;  // Xuống dòng sau mỗi hoán vị
    } while (next_permutation(a.begin(), a.end())); // Sinh hoán vị kế tiếp

    return 0; // Kết thúc chương trình
}
