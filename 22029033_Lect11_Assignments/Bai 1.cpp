#include <iostream> 
#include <vector>   
#include <queue>   
#include <fstream>  
#include <limits>   
#include <algorithm>

using namespace std;

// Dinh nghia gia tri vo cung (INF) cho khoang cach
// Su dung long long vi tong muc do ban tren duong di co the lon hoac am nhieu
const long long INF = numeric_limits<long long>::max() / 2; // Chia 2 de tranh tran so khi cong them trong luong canh am

// Cau truc de luu thong tin canh: nut dich va trong luong (muc do ban)
struct Edge {
    int to;     // Nut dich cua canh
    int weight; // Trong luong (muc do ban) cua canh
};

int main() {
    // Mo file dau vao
    ifstream infile("dirty.txt");
    // Mo file dau ra
    ofstream outfile("dirty.out");

    // Kiem tra xem cac file co mo thanh cong khong
    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Khong the mo file dirty.txt hoac dirty.out" << endl;
        return 1; // Tra ve ma loi neu khong mo duoc file
    }

    int n, m, s, e; // So luong nut, so luong canh, nut bat dau, nut ket thuc

    // Doc n, m, s, e tu file dau vao
    infile >> n >> m >> s >> e;

    // Khai bao danh sach ke de luu tru do thi co huong voi trong luong
    // adj[i] se la mot vector chua danh sach cac Edge bat dau tu nut i
    // Kich thuoc n + 1 de su dung chi so tu 1 den n
    vector<vector<Edge>> adj(n + 1);

    // Doc m canh va xay dung danh sach ke
    for (int i = 0; i < m; ++i) {
        int u, v, d; // Canh tu u den v voi trong luong d
        // Doc canh va trong luong tu file dau vao
        infile >> u >> v >> d;
        // Them canh (u, v) voi trong luong d vao danh sach ke cua u
        adj[u].push_back({v, d});
    }

    // -------------- Phan a: Tim duong di ngan nhat tu s den e (muc do ban nho nhat) --------------

    // Su dung thuat toan SPFA (Shortest Path Faster Algorithm) vi co trong luong am
    // Mang dist luu khoang cach ngan nhat tu s den moi nut
    // Khoi tao tat ca la INF, tru nut bat dau s co khoang cach la 0
    vector<long long> dist(n + 1, INF);
    dist[s] = 0;

    // Mang pred luu nut tien boi tren duong di ngan nhat tu s
    // Dung de tai tao lai duong di
    vector<int> pred(n + 1, -1); // Khoi tao tat ca la -1 (chua co tien boi)

    // Mang danh dau cac nut dang co trong hang doi
    vector<bool> in_queue(n + 1, false);

    // Hang doi cho SPFA
    queue<int> q;

    // Them nut bat dau vao hang doi va danh dau la dang trong hang doi
    q.push(s);
    in_queue[s] = true;

    // Bien dem so lan mot nut duoc dua ra khoi hang doi
    // Dung de phat hien chu trinh am. Neu mot nut duoc dua ra > n lan, co chu trinh am.
    // Tuy nhien, bai toan khong yeu cau xu ly cu the truong hop chu trinh am lam cho khoang cach la -INF vo cuc.
    // Chung ta se chay SPFA va lay ket qua, mac dinh rang neu co chu trinh am, bai toan van co loi giai hop le tu s den e.
    // vector<int> visit_count(n + 1, 0); // Khong can thiet neu khong xu ly chu trinh am cu the

    // Chay thuat toan SPFA
    while (!q.empty()) {
        // Lay nut u ra khoi dau hang doi
        int u = q.front();
        q.pop();
        // Danh dau u khong con trong hang doi
        in_queue[u] = false;

        // tang so lan nut u duoc tham (neu can phat hien chu trinh am)
        // visit_count[u]++;
        // if (visit_count[u] > n) {
        //     // Phat hien chu trinh am, co the can bao loi hoac xu ly khac
        //     // Voi bai toan nay, chung ta tiep tuc chay, gia dinh duong di s-e khong bi anh huong boi chu trinh am lam -INF
        // }

        // Duyet qua tat ca cac canh (u, v) bat dau tu u
        for (const auto& edge : adj[u]) {
            int v = edge.to;      // Nut dich
            int weight = edge.weight; // Trong luong canh

            // Relaxation: Neu co the tim duoc duong di ngan hon den v qua u
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                // Cap nhat khoang cach ngan nhat den v
                dist[v] = dist[u] + weight;
                // Ghi nhan u la nut tien boi cua v tren duong di ngan nhat nay
                pred[v] = u;

                // Neu v chua co trong hang doi, them v vao hang doi de xu ly
                if (!in_queue[v]) {
                    q.push(v);
                    in_queue[v] = true;
                }
            }
        }
    }

    // Ghi ket qua phan a ra file dau ra

    // Ghi tong muc do ban cua duong di ngan nhat tu s den e
    if (dist[e] == INF) {
        outfile << "INF" << endl; // Khong co duong di tu s den e
    } else {
        outfile << dist[e] << endl; // Muc do ban nho nhat
    }

    // Tai tao va ghi duong di tu s den e
    vector<int> path; // Vector luu cac nut tren duong di
    int curr = e;     // Bat dau tu nut ket thuc e

    // Neu dist[e] la INF hoac pred[e] van la -1 nhung e != s, tuc la khong co duong di
    if (dist[e] == INF || (pred[e] == -1 && s != e)) {
        // Khong co duong di, khong in gi hoac in mot dong trong tuy dinh dang
        // Theo vi du, chi in khoang cach INF, khong in dong duong di
    } else {
        // Co duong di, tai tao tu e ve s bang mang pred
        while (curr != -1) {
            path.push_back(curr); // Them nut hien tai vao duong di
            curr = pred[curr];    // Quay lui ve nut tien boi
        }
        reverse(path.begin(), path.end()); // Dao nguoc duong di de co thu tu tu s den e

        // Ghi duong di ra file dau ra
        for (size_t i = 0; i < path.size(); ++i) {
            outfile << path[i] << (i == path.size() - 1 ? "" : " "); // In nut, cach nhau boi khoang trang
        }
        outfile << endl; // Xuong dong sau khi in duong di
    }


    // -------------- Phan b: Tim duong di ngan nhat giua moi cap nut --------------

    // Su dung thuat toan Floyd-Warshall vi can tim duong di ngan nhat cho moi cap nut
    // Khoi tao ma tran khoang cach D[i][j]
    // Kich thuoc (n+1)x(n+1) de su dung chi so tu 1 den n
    vector<vector<long long>> dist_matrix(n + 1, vector<long long>(n + 1, INF));

    // Khoi tao duong cheo chinh D[i][i] = 0
    for (int i = 1; i <= n; ++i) {
        dist_matrix[i][i] = 0;
    }

    // Dien cac trong luong canh truc tiep vao ma tran ban dau
    // Doc lai canh tu file, hoac neu danh sach ke van co the dung lai
    // Doc lai canh tu danh sach ke da tao o phan a
    for (int u = 1; u <= n; ++u) {
        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int weight = edge.weight;
            // Neu co nhieu canh giua u va v, giu lai canh co trong luong nho nhat
            dist_matrix[u][v] = min(dist_matrix[u][v], (long long)weight);
        }
    }

    // Thuat toan Floyd-Warshall
    // Lap qua tat ca cac nut co the lam nut trung gian (k)
    for (int k = 1; k <= n; ++k) {
        // Lap qua tat ca cac nut nguon (i)
        for (int i = 1; i <= n; ++i) {
            // Lap qua tat ca cac nut dich (j)
            for (int j = 1; j <= n; ++j) {
                // Neu co duong di tu i den k VÀ tu k den j
                if (dist_matrix[i][k] != INF && dist_matrix[k][j] != INF) {
                    // Cap nhat khoang cach tu i den j neu di qua k ngan hon
                    dist_matrix[i][j] = min(dist_matrix[i][j], dist_matrix[i][k] + dist_matrix[k][j]);
                }
            }
        }
    }

    // Ghi ma tran khoang cach ngan nhat ra file dau ra
    // Bat dau tu dong tiep theo sau ket qua phan a
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Ghi khoang cach, neu la INF thi in chu "INF"
            if (dist_matrix[i][j] == INF) {
                outfile << "INF" << (j == n ? "" : " "); // In INF, cach nhau boi khoang trang tru cot cuoi
            } else {
                 // Kiem tra chu trinh am: Neu dist_matrix[i][j] khac INF va dist_matrix[j][j] am
                 // Tức là có đường đi từ i đến một chu trình âm qua j
                 // Theo lý thuyết, khoảng cách ngắn nhất là -INF vô cùng.
                 // Tuy nhiên, đề bài không yêu cầu xử lý trường hợp này cụ thể.
                 // Chúng ta sẽ in ra giá trị tính được bởi Floyd-Warshall.
                 // Một cách xử lý khác là sau khi chạy FW, nếu dist[i][k] != INF và dist[k][i] < 0 cho bất kỳ k,
                 // thì mọi dist[i][j] có thể đạt được từ i và có đường đi tới chu trình âm sẽ là -INF.
                 // Với bài toán đơn giản này, chỉ in giá trị ma trận sau FW là đủ.
                 outfile << dist_matrix[i][j] << (j == n ? "" : " "); // In khoang cach, cach nhau boi khoang trang
            }
        }
        outfile << endl; // Xuong dong sau moi hang cua ma tran
    }

    // Dong file dau vao va dau ra
    infile.close();
    outfile.close();

    return 0; // Ket thuc chuong trinh thanh cong
}
