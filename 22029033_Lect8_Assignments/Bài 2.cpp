#include <iostream>     // Thư viện cho nhập xuất
#include <vector>       // Thư viện sử dụng vector
using namespace std;

// Hàm đệ quy để kiểm tra xem có tổ hợp nào có tổng bằng X không
bool subsetSum(vector<int>& A, int n, int X) {
    // Nếu tổng cần tìm là 0, ta đã tìm được tổ hợp thoả mãn
    if (X == 0) return true;

    // Nếu không còn phần tử nào hoặc tổng bị âm, thì không tìm được tổ hợp
    if (n == 0 || X < 0) return false;

    // Gọi đệ quy kiểm tra 2 trường hợp:
    // 1. Bỏ qua phần tử cuối cùng
    // 2. Sử dụng phần tử cuối cùng (trừ đi giá trị đó từ X)
    return subsetSum(A, n - 1, X) || subsetSum(A, n - 1, X - A[n - 1]);
}

int main() {
    int n, X; // Khai báo biến n (số lượng sinh viên) và X (tổng cần tìm)

    // Đọc giá trị n và X từ dòng đầu tiên
    cin >> n >> X;

    vector<int> A(n); // Khai báo vector A có n phần tử để lưu độ tuổi

    // Đọc danh sách tuổi từ dòng thứ hai
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Gọi hàm kiểm tra tổ hợp có tổng bằng X không
    if (subsetSum(A, n, X)) {
        cout << "YES" << endl; // Nếu có, in YES
    } else {
        cout << "NO" << endl;  // Nếu không, in NO
    }

    return 0; // Kết thúc chương trình
}
