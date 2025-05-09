#include <iostream>     // Thư viện cho nhập xuất
#include <vector>       // Thư viện sử dụng vector
#include <algorithm>    // Thư viện dùng cho hàm max
using namespace std;

int main() {
    int n, X; // n là số lượng vật, X là trọng lượng tối đa cho phép

    cin >> n >> X; // Nhập n và X từ dòng đầu tiên

    vector<int> weight(n); // vector lưu trọng lượng từng vật
    vector<int> value(n);  // vector lưu giá trị từng vật

    // Nhập trọng lượng và giá trị của từng vật
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i]; // Mỗi dòng gồm 1 cặp weight và value
    }

    // Khởi tạo bảng dp với kích thước (X+1), mỗi phần tử là 0
    // dp[j] sẽ lưu tổng giá trị lớn nhất có thể đạt được với trọng lượng j
    vector<int> dp(X + 1, 0);

    // Duyệt qua từng vật
    for (int i = 0; i < n; ++i) {
        // Duyệt ngược từ X về weight[i] để tránh ghi đè lên kết quả cũ
        for (int j = X; j >= weight[i]; --j) {
            // So sánh giữa không chọn vật i và chọn vật i (cộng giá trị và trừ trọng lượng)
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    // Sau khi xử lý xong, dp[X] là tổng giá trị lớn nhất có thể đạt được
    cout << dp[X] << endl;

    return 0; // Kết thúc chương trình
}
