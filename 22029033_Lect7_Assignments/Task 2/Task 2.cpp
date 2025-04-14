#include <iostream>     // Thư viện nhập xuất chuẩn
#include <fstream>      // Thư viện xử lý file
#include <vector>       // Thư viện dùng vector
#include <climits>      // Thư viện dùng hằng số INT_MIN

using namespace std;

// Hàm tìm đoạn con có tổng lớn nhất (Kadane 1D), trả về chỉ số đầu, cuối và tổng
int kadane(const vector<int>& arr, int& start, int& end) {
    int maxSum = INT_MIN;     // Tổng lớn nhất khởi đầu là rất nhỏ (âm vô cùng)
    int currentSum = 0;       // Tổng hiện tại
    int localStart = 0;       // Vị trí bắt đầu tạm thời

    start = end = -1;         // Khởi tạo chỉ số bắt đầu/kết thúc là chưa xác định

    // Duyệt qua từng phần tử trong mảng arr
    for (int i = 0; i < arr.size(); ++i) {
        currentSum += arr[i];  // Cộng dồn phần tử vào tổng hiện tại

        if (currentSum < arr[i]) {           // Nếu tổng hiện tại nhỏ hơn chính phần tử đó
            currentSum = arr[i];             // Bắt đầu chuỗi mới từ vị trí i
            localStart = i;                  // Ghi nhớ vị trí bắt đầu mới
        }

        if (currentSum > maxSum) {           // Nếu tổng hiện tại lớn hơn tổng max
            maxSum = currentSum;             // Cập nhật tổng lớn nhất
            start = localStart;              // Cập nhật vị trí bắt đầu
            end = i;                         // Cập nhật vị trí kết thúc
        }
    }

    return maxSum;  // Trả về tổng lớn nhất tìm được
}

int main() {
    ifstream fin("matrix.txt");   // Mở file input để đọc dữ liệu ma trận
    ofstream fout("matrix.out");  // Mở file output để ghi kết quả

    int m, n;                     // m là số hàng, n là số cột
    fin >> m >> n;                // Đọc m và n từ dòng đầu tiên trong file

    // Tạo ma trận m hàng n cột khởi tạo giá trị rỗng
    vector<vector<int>> matrix(m, vector<int>(n));

    // Đọc từng phần tử của ma trận từ file
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            fin >> matrix[i][j];  // Đọc giá trị phần tử tại hàng i, cột j
        }
    }

    // Biến lưu thông tin kết quả lớn nhất
    int maxSum = INT_MIN;         // Tổng lớn nhất ban đầu rất nhỏ
    int finalLeft, finalRight;    // Vị trí cột trái và cột phải của submatrix
    int finalTop, finalBottom;    // Vị trí hàng trên và hàng dưới của submatrix

    // Duyệt qua tất cả các cặp cột (từ trái sang phải)
    for (int left = 0; left < n; ++left) {
        vector<int> temp(m, 0);   // Mảng tạm để lưu tổng từng hàng

        for (int right = left; right < n; ++right) {
            for (int i = 0; i < m; ++i) {
                temp[i] += matrix[i][right];  // Cộng thêm giá trị cột right vào mảng temp
            }

            // Tìm đoạn con có tổng lớn nhất trong temp (ứng với các hàng)
            int startRow, endRow;
            int sum = kadane(temp, startRow, endRow);  // Gọi hàm kadane

            // Nếu tìm được tổng lớn hơn maxSum thì cập nhật kết quả
            if (sum > maxSum) {
                maxSum = sum;              // Cập nhật tổng lớn nhất
                finalTop = startRow;       // Lưu hàng bắt đầu
                finalBottom = endRow;      // Lưu hàng kết thúc
                finalLeft = left;          // Lưu cột trái
                finalRight = right;        // Lưu cột phải
            }
        }
    }

    // Ghi kết quả ra file (đổi chỉ số từ 0 sang 1 để đúng đề bài)
    fout << finalTop + 1 << " "
         << finalLeft + 1 << " "
         << finalBottom + 1 << " "
         << finalRight + 1 << " "
         << maxSum << endl;

    // Đóng file input và output
    fin.close();
    fout.close();

    return 0;  // Kết thúc chương trình
}
