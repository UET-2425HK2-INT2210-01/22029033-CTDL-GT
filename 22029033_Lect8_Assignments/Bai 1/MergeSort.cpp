#include <iostream>
#include <vector>
using namespace std;

// Hàm trộn hai mảng con đã được sắp xếp
void merge(vector<double>& arr, int left, int mid, int right) {
    // Tạo hai mảng tạm để chứa các phần tử hai nửa
    int n1 = mid - left + 1; // Số phần tử bên trái
    int n2 = right - mid;    // Số phần tử bên phải

    // Tạo mảng tạm
    vector<double> L(n1), R(n2);

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i]; // Mảng trái từ arr[left] đến arr[mid]

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j]; // Mảng phải từ arr[mid+1] đến arr[right]

    // Gộp hai mảng con lại vào mảng chính
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        // Nếu phần tử bên trái nhỏ hơn hoặc bằng bên phải thì lấy bên trái
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Sao chép các phần tử còn lại (nếu có) của mảng trái
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép các phần tử còn lại (nếu có) của mảng phải
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm đệ quy Merge Sort
void mergeSort(vector<double>& arr, int left, int right) {
    if (left < right) {
        // Tìm chỉ số ở giữa để chia mảng ra hai nửa
        int mid = left + (right - left) / 2;

        // Gọi đệ quy để sắp xếp từng nửa
        mergeSort(arr, left, mid);       // Sắp xếp nửa trái
        mergeSort(arr, mid + 1, right);  // Sắp xếp nửa phải

        // Trộn hai nửa lại với nhau
        merge(arr, left, mid, right);
    }
}

int main() {
    int n; // Số phần tử của mảng
    cin >> n; // Nhập số lượng phần tử

    vector<double> arr(n); // Tạo mảng để chứa các số thực

    // Nhập từng số thực, mỗi dòng một số
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Gọi hàm Merge Sort để sắp xếp mảng
    mergeSort(arr, 0, n - 1);

    // In ra các phần tử đã được sắp xếp, cách nhau bởi dấu cách
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) cout << " "; // Không in dấu cách sau phần tử cuối
    }

    cout << endl; // Xuống dòng sau khi in xong
    return 0;
}
