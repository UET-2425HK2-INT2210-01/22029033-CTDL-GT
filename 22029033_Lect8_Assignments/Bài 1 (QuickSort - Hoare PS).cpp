#include <iostream>
#include <vector>
using namespace std;

// Hàm thực hiện thuật toán QuickSort (sử dụng sơ đồ phân hoạch Hoare)
void quickSort(vector<double> &arr, int left, int right) {
    // Nếu mảng có nhiều hơn 1 phần tử thì mới sắp xếp
    if (left >= right) return;

    // Chọn phần tử pivot là phần tử giữa
    double pivot = arr[(left + right) / 2];

    // i đi từ trái qua, j đi từ phải lại
    int i = left, j = right;

    while (true) {
        // Tìm phần tử bên trái lớn hơn hoặc bằng pivot
        while (arr[i] < pivot) i++;
        // Tìm phần tử bên phải nhỏ hơn hoặc bằng pivot
        while (arr[j] > pivot) j--;

        // Nếu đã vượt qua nhau thì dừng
        if (i >= j) break;

        // Hoán đổi 2 phần tử sai vị trí
        swap(arr[i], arr[j]);
        i++; j--;
    }

    // Gọi đệ quy cho 2 nửa bên trái và bên phải
    quickSort(arr, left, j);  // j là phần tử bên trái cuối cùng <= pivot
    quickSort(arr, j + 1, right);  // j+1 là bắt đầu phần bên phải
}

int main() {
    int n; // Số lượng phần tử
    cin >> n;

    vector<double> arr(n); // Khai báo mảng lưu các số thực

    // Đọc n dòng, mỗi dòng là 1 số thực
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Gọi hàm QuickSort để sắp xếp mảng tăng dần
    quickSort(arr, 0, n - 1);

    // In mảng đã sắp xếp, mỗi số cách nhau bởi 1 dấu cách
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << " "; // Không in dấu cách sau phần tử cuối
    }

    cout << endl; // Xuống dòng sau khi in xong
    return 0;
}
