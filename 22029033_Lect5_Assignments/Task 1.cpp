#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Tree {
private:
    unordered_map<int, vector<int>> tree; // Danh sách kề lưu cấu trúc cây
    unordered_map<int, int> parent; // Bản đồ lưu cha của mỗi nút
    int root; // Gốc của cây
    int n; // Số lượng nút

public:
    Tree(int nodes) : n(nodes), root(-1) {} // Khởi tạo cây với số nút và gán gốc là -1
    void addEdge(int u, int v)
    {
        // Kiểm tra nếu nút v đã có cha, cây không hợp lệ
        if (parent.find(v) != parent.end())
        {
            exit(0);
        }
        tree[u].push_back(v); // Thêm v vào danh sách con của u
        parent[v] = u; // Đánh dấu u là cha của v
    }
    void findRoot()
    {
        unordered_set<int> possible_roots;
        // Ban đầu, tất cả các nút đều có thể là gốc
        for (int i = 1; i <= n; i++) possible_roots.insert(i);
        // Loại bỏ các nút có cha khỏi danh sách gốc
        for (auto &p : parent) possible_roots.erase(p.first);
        // Nếu có nhiều hơn một gốc, cây không hợp lệ
        if (possible_roots.size() > 1) {
            exit(0);
        }
        // Nếu còn lại một gốc, gán giá trị cho root
        if (!possible_roots.empty()) root = *possible_roots.begin();
    }
    int treeHeight(int node)
    {
        // Nếu nút không có con, chiều cao là 0
        if (tree.find(node) == tree.end()) return 0;
        int maxHeight = 0;
        // Duyệt tất cả con của nút để tìm chiều cao lớn nhất
        for (int child : tree[node])
        {
            maxHeight = max(maxHeight, treeHeight(child));
        }
        return 1 + maxHeight; // Chiều cao của cây = 1 + max chiều cao các nhánh con
    }
    void preorder(int node, vector<int> &result)
    {
        result.push_back(node); // Thêm nút hiện tại vào kết quả
        for (int child : tree[node])
        {
            preorder(child, result); // Duyệt đệ quy các con trước
        }
    }
    void postorder(int node, vector<int> &result)
    {
        for (int child : tree[node])
        {
            postorder(child, result); // Duyệt đệ quy các con trước
        }
        result.push_back(node); // Thêm nút hiện tại vào kết quả sau khi duyệt con
    }
    bool isBinaryTree()
    {
        // Kiểm tra nếu có nút nào có hơn 2 con thì không phải cây nhị phân
        for (auto &entry : tree)
        {
            if (entry.second.size() > 2) return false;
        }
        return true;
    }
    void inorder(int node, vector<int> &result)
    {
        auto &children = tree[node];
        // Nếu nút có hơn 2 con, không thể duyệt trung thứ tự
        if (children.size() > 2)
        {
            exit(0);
        }
        if (!children.empty()) inorder(children[0], result); // Duyệt nhánh trái
        result.push_back(node); // Thêm nút hiện tại vào kết quả
        if (children.size() > 1) inorder(children[1], result); // Duyệt nhánh phải
    }
    void processTree()
    {
        findRoot(); // Tìm gốc của cây
        if (root == -1) return;
        cout << treeHeight(root) << endl; // In chiều cao của cây
        vector<int> pre, post, in;
        preorder(root, pre); // Duyệt tiền thứ tự
        postorder(root, post); // Duyệt hậu thứ tự
        for (int v : pre) cout << v << " "; // In kết quả duyệt tiền thứ tự
        cout << endl;
        for (int v : post) cout << v << " "; // In kết quả duyệt hậu thứ tự
        cout << endl;
        if (isBinaryTree())
        {
            inorder(root, in); // Duyệt trung thứ tự nếu là cây nhị phân
            for (int v : in) cout << v << " "; // In kết quả duyệt trung thứ tự
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    // Kiểm tra số cạnh có hợp lệ không (cây hợp lệ có đúng n-1 cạnh)
    if (m != n - 1)
    {
        return 0;
    }

    Tree tree(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        tree.addEdge(u, v); // Thêm cạnh vào cây
    }

    tree.processTree(); // Xử lý cây và in kết quả
    return 0;
}
