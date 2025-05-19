#include <iostream> // Thư viện cho nhập xuất cơ bản (cin, cout, cerr)
#include <vector>   // Thư viện cho sử dụng vector (mảng động)
#include <fstream>  // Thư viện cho thao tác với file (ifstream, ofstream)
#include <algorithm> // Thư viện cho các thuật toán chung (như sort)
#include <numeric>  // Thư viện cho các phép toán số học (như iota)

// Sử dụng toàn bộ namespace std để không cần gõ std::
using namespace std;

// Cấu trúc để biểu diễn một cạnh (kết nối) trong đồ thị
struct Edge {
    int u, v, cost; // Hai máy tính u, v và chi phí kết nối cost
};

// Hàm so sánh cho việc sắp xếp cạnh theo chi phí tăng dần
bool compareEdges(const Edge& a, const Edge& b) {
    return a.cost < b.cost; // Sắp xếp theo trường 'cost' tăng dần
}

// Lớp biểu diễn cấu trúc dữ liệu Disjoint Set Union (DSU)
// Được sử dụng để kiểm tra và gộp các tập hợp đỉnh liên thông
class DSU {
private:
    vector<int> parent; // parent[i] lưu cha của phần tử i. Nếu parent[i] == i thì i là gốc
    vector<int> sz;     // sz[i] lưu kích thước (số phần tử) của tập hợp mà i là gốc

public:
    // Constructor: Khởi tạo n tập hợp rời rạc, mỗi tập hợp chứa một phần tử
    DSU(int n) {
        // Kích thước n+1 để sử dụng chỉ số từ 1 đến n
        parent.resize(n + 1);
        iota(parent.begin() + 1, parent.end(), 1); // Khởi tạo parent[i] = i cho i từ 1 đến n
        sz.assign(n + 1, 1); // Khởi tạo kích thước của mỗi tập hợp ban đầu là 1
    }

    // Hàm tìm gốc của phần tử i (với nén đường - path compression)
    int find(int i) {
        if (parent[i] == i) {
            return i; // Nếu i là gốc, trả về i
        }
        // Nén đường: Gán cha của i bằng gốc thực sự để các lần tìm sau nhanh hơn
        return parent[i] = find(parent[i]);
    }

    // Hàm gộp hai tập hợp chứa phần tử i và j (với gộp theo kích thước - union by size)
    // Trả về true nếu hai tập hợp được gộp, false nếu i và j đã cùng tập hợp
    bool unite(int i, int j) {
        int root_i = find(i); // Tìm gốc của i
        int root_j = find(j); // Tìm gốc của j

        if (root_i != root_j) { // Nếu i và j thuộc hai tập hợp khác nhau
            // Gộp tập hợp nhỏ hơn vào tập hợp lớn hơn để cây cân bằng hơn
            if (sz[root_i] < sz[root_j]) {
                swap(root_i, root_j); // Đảm bảo root_i luôn là gốc của tập hợp lớn hơn (hoặc bằng)
            }
            parent[root_j] = root_i; // Gán gốc của tập hợp nhỏ hơn làm con của gốc tập hợp lớn hơn
            sz[root_i] += sz[root_j]; // Cập nhật kích thước của tập hợp mới
            return true; // Hai tập hợp đã được gộp
        }
        return false; // i và j đã cùng tập hợp, không gộp
    }
};

int main() {
    // Tăng tốc độ nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Mở file đầu vào connection.txt để đọc
    ifstream inputFile("connection.txt");
    // Mở file đầu ra connection.out để ghi
    ofstream outputFile("connection.out");

    // Kiểm tra xem các file có mở thành công không
    if (!inputFile.is_open()) {
        cerr << "Không thể mở file connection.txt" << endl;
        return 1; // Trả về mã lỗi
    }
    if (!outputFile.is_open()) {
        cerr << "Không thể mở file connection.out" << endl;
        inputFile.close(); // Đảm bảo đóng file đầu vào
        return 1; // Trả về mã lỗi
    }

    int n, m; // n: số máy tính, m: số kết nối tiềm năng
    inputFile >> n >> m; // Đọc n và m từ dòng đầu tiên

    // Vector để lưu trữ tất cả các cạnh (kết nối) tiềm năng
    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        inputFile >> edges[i].u >> edges[i].v >> edges[i].cost; // Đọc thông tin từng cạnh
    }

    // Sắp xếp các cạnh theo chi phí tăng dần
    sort(edges.begin(), edges.end(), compareEdges);

    // Khởi tạo cấu trúc DSU cho n máy tính
    DSU dsu(n);

    long long total_cost = 0; // Tổng chi phí của cây bao trùm nhỏ nhất (sử dụng long long vì chi phí có thể lớn)
    vector<Edge> mst_edges; // Vector để lưu trữ các cạnh thuộc cây bao trùm nhỏ nhất

    // Duyệt qua các cạnh đã được sắp xếp theo chi phí
    for (const auto& edge : edges) {
        // Nếu hai đỉnh của cạnh hiện tại chưa thuộc cùng một tập hợp (chưa được kết nối)
        if (dsu.unite(edge.u, edge.v)) {
            // Gộp thành công nghĩa là thêm cạnh này không tạo chu trình và kết nối hai tập hợp riêng biệt
            total_cost += edge.cost; // Cộng chi phí của cạnh vào tổng chi phí
            mst_edges.push_back(edge); // Thêm cạnh này vào danh sách các cạnh của MST

            // Nếu đã tìm được n-1 cạnh, tức là đã có cây bao trùm (vì có n đỉnh)
            if (mst_edges.size() == n - 1) {
                break; // Dừng thuật toán vì đã tìm đủ cạnh cho MST
            }
        }
    }

    // Ghi kết quả ra file output
    outputFile << total_cost << endl; // Ghi tổng chi phí

    // Ghi danh sách các cạnh trong MST
    for (const auto& edge : mst_edges) {
        outputFile << edge.u << " " << edge.v << " " << edge.cost << endl;
    }

    // Đóng các file
    inputFile.close();
    outputFile.close();

    return 0; // Trả về 0 báo hiệu chương trình kết thúc thành công
}
