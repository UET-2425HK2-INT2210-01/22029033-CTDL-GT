#include <iostream> // Thu vien nhap xuat co ban
#include <vector>   // Thu vien cho vector, su dung de luu danh sach ke va mang khoang cach
#include <queue>    // Thu vien cho hang doi, su dung trong thuat toan BFS

using namespace std; // Su dung khong gian ten std de khong phai go std:: truoc moi ham/doi tuong

int main() {
    // Tang toc do nhap xuat
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // So luong nut
    int m; // So luong canh
    int start_node; // Nut bat dau (X)
    int end_node;   // Nut ket thuc (Y)

    // Doc so luong nut, so luong canh, nut bat dau va nut ket thuc tu dau vao
    cin >> n >> m >> start_node >> end_node;

    // Khai bao danh sach ke de luu tru do thi co huong
    // adj[i] se la mot vector chua danh sach cac nut ma co canh tu i den do
    // Kich thuoc n + 1 de su dung chi so tu 1 den n
    vector<vector<int>> adj(n + 1);

    // Doc m canh va xay dung danh sach ke
    // Do thi co huong, nen chi them chieu di
    for (int i = 0; i < m; ++i) {
        int u, v; // Canh tu u den v (u -> v)
        // Doc hai nut cua canh tu dau vao
        cin >> u >> v;
        // Them nut v vao danh sach ke cua u (co canh tu u den v)
        adj[u].push_back(v);
    }

    // Mang de luu tru khoang cach ngan nhat tu nut bat dau (start_node) den moi nut
    // Khoang cach duoc tinh bang so luong canh it nhat
    // Kich thuoc n + 1, khoi tao tat ca la -1 (bieu thi chua duoc tham hoac khong the toi tu start_node)
    vector<int> dist(n + 1, -1);

    // Hang doi cho thuat toan BFS
    // BFS giup tim duong di ngan nhat tren do thi khong trong so (hay trong so bang 1)
    queue<int> q;

    // Khoi tao BFS
    // Nut bat dau co khoang cach den chinh no la 0
    dist[start_node] = 0;
    // Them nut bat dau vao hang doi de bat dau duyet
    q.push(start_node);

    // Thuc hien BFS
    while (!q.empty()) {
        // Lay nut o dau hang doi ra de xu ly
        int u = q.front();
        q.pop();

        // Neu nut hien tai la nut ket thuc, chung ta da tim thay duong di ngan nhat
        // Co the dung lai som o day
        if (u == end_node) {
            break;
        }

        // Duyet qua tat ca cac nut lan can (ma co canh di tu u den v)
        for (int v : adj[u]) {
            // Neu nut lan can v chua duoc tham (khoang cach van la -1)
            if (dist[v] == -1) {
                // Cap nhat khoang cach den v
                // Khoang cach den v bang khoang cach den u cong them 1 canh
                dist[v] = dist[u] + 1;
                // Them nut v vao hang doi de duyet tiep cac nut ke tu v
                q.push(v);
            }
        }
    }

    // Ket qua la khoang cach ngan nhat den nut ket thuc (end_node)
    // Neu dist[end_node] van la -1, tuc la khong co duong di tu start_node den end_node
    cout << dist[end_node] << endl;

    return 0; // Ket thuc chuong trinh thanh cong
}
