#include <iostream>
using namespace std;

// Định nghĩa cấu trúc Node của cây
struct Node {
    int value;            // Giá trị của nút
    Node* left;           // Con trỏ đến nút con trái
    Node* right;          // Con trỏ đến nút con phải

    // Constructor khởi tạo giá trị và gán con trỏ null
    Node(int val) {
        value = val;
        left = right = nullptr;
    }
};

// Hàm chèn một giá trị vào cây BST
Node* insert(Node* root, int value) {
    if (root == nullptr) // Nếu cây rỗng, tạo nút mới
        return new Node(value);
    if (value < root->value) // Nếu giá trị nhỏ hơn, chèn bên trái
        root->left = insert(root->left, value);
    else // Nếu lớn hơn hoặc bằng, chèn bên phải
        root->right = insert(root->right, value);
    return root;
}

// Hàm tìm nút có giá trị nhỏ nhất trong cây
Node* findMin(Node* root) {
    while (root->left != nullptr) // Duyệt về bên trái đến khi không còn
        root = root->left;
    return root;
}

// Hàm xóa một giá trị khỏi cây
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) // Nếu cây rỗng, trả về null
        return nullptr;
    if (value < root->value) // Nếu nhỏ hơn, xóa bên trái
        root->left = deleteNode(root->left, value);
    else if (value > root->value) // Nếu lớn hơn, xóa bên phải
        root->right = deleteNode(root->right, value);
    else {
        // Nếu chỉ có 1 con hoặc không có con
        if (root->left == nullptr) {
            Node* temp = root->right; // Lưu con phải
            delete root; // Xóa nút hiện tại
            return temp; // Trả về con phải
        }
        else if (root->right == nullptr) {
            Node* temp = root->left; // Lưu con trái
            delete root; // Xóa nút hiện tại
            return temp; // Trả về con trái
        }
        // Nếu có 2 con, tìm nút nhỏ nhất bên phải
        Node* temp = findMin(root->right); // Tìm giá trị nhỏ nhất bên phải
        root->value = temp->value; // Gán giá trị đó cho nút hiện tại
        root->right = deleteNode(root->right, temp->value); // Xóa giá trị trùng trong cây con phải
    }
    return root;
}

// Hàm in cây theo thứ tự giữa (in-order)
void inorder(Node* root) {
    if (root == nullptr) return; // Nếu cây rỗng thì thoát
    inorder(root->left); // Duyệt cây con trái
    cout << root->value << " "; // In giá trị nút
    inorder(root->right); // Duyệt cây con phải
}

// Hàm main để thực thi yêu cầu
int main() {
    Node* root = nullptr; // Khởi tạo cây rỗng

    // Danh sách ban đầu
    int initial[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int val : initial)
        root = insert(root, val); // Chèn từng giá trị

    cout << "BST ban dau (in-order): ";
    inorder(root); // In cây
    cout << endl;

    // Chèn thêm các giá trị mới
    int insert_vals[] = {14, 0, 35};
    for (int val : insert_vals)
        root = insert(root, val); // Chèn giá trị mới

    cout << "BST sau khi insert 14, 0, 35: ";
    inorder(root); // In cây sau chèn
    cout << endl;

    // Xóa các giá trị yêu cầu
    int delete_vals[] = {6, 13, 35};
    for (int val : delete_vals)
        root = deleteNode(root, val); // Xóa từng giá trị

    cout << "BST sau khi delete 6, 13, 35: ";
    inorder(root); // In cây sau xóa
    cout << endl;

    return 0; // Kết thúc chương trình
}
