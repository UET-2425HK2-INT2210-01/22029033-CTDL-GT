#include <iostream>     // Thư viện nhập xuất chuẩn
#include <fstream>      // Thư viện làm việc với file
#include <vector>       // Thư viện dùng vector để lưu danh sách số
#include <algorithm>    // Thư viện dùng hàm sort

using namespace std;

int main() {
    ifstream fin("numbers.txt");        // Mở file đầu vào 'numbers.txt'
    ofstream fout("numbers.sorted");    // Mở file đầu ra 'numbers.sorted'

    vector<double> numbers;             // Khai báo danh sách các số thực

    double num;                         // Biến tạm để đọc từng số
    while (fin >> num) {                // Đọc từng số từ file đến hết
        numbers.push_back(num);         // Thêm số vừa đọc vào vector
    }

    sort(numbers.begin(), numbers.end());  // Sắp xếp các số theo thứ tự tăng dần

    // Ghi kết quả ra file output, mỗi số cách nhau bằng 1 khoảng trắng
    for (int i = 0; i < numbers.size(); ++i) {
        fout << numbers[i];             // Ghi số vào file
        if (i != numbers.size() - 1)    // Nếu không phải số cuối thì ghi thêm khoảng trắng
            fout << " ";
    }

    // Đóng file sau khi xử lý xong
    fin.close();
    fout.close();

    return 0;   // Kết thúc chương trình
}
