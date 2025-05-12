#include <iostream> // Thu vien nhap xuat co ban
#include <vector>   // Thu vien cho vector, su dung de luu danh sach ke va mang danh dau da tham

using namespace std; // Su dung khong gian ten std de khong phai go std:: truoc moi ham/doi tuong

// Ham DFS (Depth-First Search) de tham het mot thanh phan lien thong
// Bat dau tu mot nut va danh dau tat ca cac nut cung thanh phan da duoc tham
void dfs(int node,             // Nut hien tai dang xet
         const vector<vector<int>>& adj, // Danh sach ke cua do thi (tham chieu hang)
         vector<bool>& visited)  // Mang danh dau cac nut da tham (tham chieu de cap nhat)
{
    visited[node] = true; // Danh dau nut hien tai la da tham

    // Duyet qua tat ca cac nut lan can cua nut hien tai
    for (int neighbor : adj[node]) {
        // Neu nut lan can chua duoc tham
        if (!visited[neighbor]) {
            // Goi de quy ham DFS cho nut lan can do
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    // Tang toc do nhap xuat
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // So luong nut
    int m; // So luong canh

    // Doc so luong nut va so luong canh tu dau vao
    cin >> n >> m;

    // Khai bao danh sach ke de luu tru do thi
    // adj[i] se la mot vector chua danh sach cac nut ma nut i co canh noi toi
    // Kich thuoc n + 1 de su dung chi so tu 1 den n
    vector<vector<int>> adj(n + 1);

    // Doc m canh va xay dung danh sach ke
    for (int i = 0; i < m; ++i) {
        int u, v; // Hai nut tao nen canh
        // Doc hai nut cua canh tu dau vao
        cin >> u >> v;
        // Vi do thi la vo huong, nen them v vao danh sach ke cua u
        adj[u].push_back(v);
        // Va them u vao danh sach ke cua v
        adj[v].push_back(u);
    }

    // Mang danh dau cac nut da tham trong qua trinh duyet do thi
    // Kich thuoc n + 1, khoi tao tat ca la false (chua tham)
    vector<bool> visited(n + 1, false);

    int component_count = 0; // Bien dem so thanh phan lien thong

    // Duyet qua tat ca cac nut tu 1 den n
    for (int i = 1; i <= n; ++i) {
        // Neu nut hien tai (i) chua duoc tham
        if (!visited[i]) {
            // Chung ta tim thay mot nut khoi dau cua mot thanh phan lien thong moi
            component_count++; // Tang so luong thanh phan lien thong
            // Bat dau duyet DFS tu nut i de tham het thanh phan lien thong nay
            dfs(i, adj, visited);
        }
    }

    // In ket qua la so luong thanh phan lien thong tim duoc
    cout << component_count << endl;

    return 0; // Ket thuc chuong trinh thanh cong
}
