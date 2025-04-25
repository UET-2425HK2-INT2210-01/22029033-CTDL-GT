#include <iostream>
#include <vector>
using namespace std;

// Hàm phân hoạch Lomuto – chia mảng và trả về chỉ số pivot sau khi phân hoạch
int partitionLomuto(vector<double> &arr, int low, int high) {
    double pivot = arr[high]; // Chọn phần tử cuối cùng làm pivot
    int i = low - 1; // i là chỉ số của phần tử nhỏ hơn pivot

    // Duyệt từ đầu đến trước phần tử cuối
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // Nếu phần tử nhỏ hơn hoặc bằng pivot
            i++; // Tăng chỉ số i
            swap(arr[i], arr[j]); // Đưa phần tử nhỏ hơn về đầu mảng
        }
    }

    // Đặt pivot vào vị trí đúng
    swap(arr[i + 1], arr[high]);

    // Trả về chỉ số pivot
    return i + 1;
}

// Hàm QuickSort sử dụng sơ đồ phân hoạch Lomuto
void quickSortLomuto(vector<double> &arr, int low, int high) {
    if (low < high) { // Nếu mảng có nhiều hơn 1 phần tử
        int pivotIndex = partitionLomuto(arr, low, high); // Phân hoạch mảng
        quickSortLomuto(arr, low, pivotIndex - 1); // Đệ quy sắp xếp bên trái
        quickSortLomuto(arr, pivotIndex + 1, high); // Đệ quy sắp xếp bên phải
    }
}

int main() {
    int n; // Biến lưu số lượng phần tử
    cin >> n; // Nhập số lượng phần tử

    vector<double> arr(n); // Tạo vector lưu n số thực

    // Nhập từng số thực, mỗi số nằm ở một dòng
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Gọi hàm QuickSort Lomuto để sắp xếp mảng
    quickSortLomuto(arr, 0, n - 1);

    // In ra các số đã sắp xếp, cách nhau bởi dấu cách
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << " "; // Không in dấu cách sau số cuối cùng
    }

    cout << endl; // Xuống dòng sau khi in xong
    return 0;
}
