#include <iostream>      // Thư viện nhập xuất cơ bản
#include <fstream>       // Thư viện xử lý file
#include <vector>        // Dùng để lưu danh sách kề
#include <queue>         // Hàng đợi ưu tiên để thực hiện thuật toán
using namespace std;

int main() {
    ifstream fin("jobs.txt");    // Mở file đầu vào
    ofstream fout("jobs.out");   // Mở file đầu ra

    int n, m;                    // n là số công việc, m là số ràng buộc
    fin >> n >> m;              // Đọc từ file đầu vào

    vector<vector<int>> adj(n + 1);   // Danh sách kề của đồ thị
    vector<int> indegree(n + 1, 0);   // Mảng lưu bậc vào của từng đỉnh (công việc)

    // Đọc m dòng ràng buộc
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;          // Công việc u phải xong trước công việc v
        adj[u].push_back(v);    // Thêm cạnh từ u đến v
        indegree[v]++;          // Tăng bậc vào của v
    }

    queue<int> q;               // Hàng đợi chứa các công việc chưa có ràng buộc

    // Đưa các công việc không có ràng buộc nào (bậc vào = 0) vào hàng đợi
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;         // Kết quả sắp xếp topo

    // Thuật toán Kahn để sắp xếp topo
    while (!q.empty()) {
        int u = q.front();      // Lấy công việc đầu tiên trong hàng đợi
        q.pop();                // Loại khỏi hàng đợi
        result.push_back(u);    // Thêm vào kết quả

        // Giảm bậc vào của các công việc phụ thuộc vào u
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);      // Nếu công việc v không còn phụ thuộc thì thêm vào hàng đợi
            }
        }
    }

    // Ghi kết quả ra file đầu ra
    for (int i = 0; i < result.size(); ++i) {
        fout << result[i];
        if (i < result.size() - 1) fout << " "; // Thêm khoảng trắng giữa các số
    }

    // Đóng file
    fin.close();
    fout.close();

    return 0;
}
