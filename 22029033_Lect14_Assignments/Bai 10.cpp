bool TreeSearchRecursive(int k, Node* T) {
    // Trường hợp cơ sở 1: Nếu cây (hoặc cây con) rỗng, khóa không tồn tại trên đường đi này.
    if (T == nullptr) {
        return false; // Trả về false, không tìm thấy khóa.
    }

    // Trường hợp cơ sở 2: Nếu khóa của nút hiện tại bằng k, tìm thấy.
    if (T->key == k) {
        return true;  // Trả về true, khóa đã được tìm thấy.
    }

    // Bước đệ quy: Quyết định tìm kiếm ở cây con nào.
    if (k < T->key) {
        // Nếu k nhỏ hơn khóa của nút hiện tại, tìm kiếm trong cây con bên trái.
        return TreeSearchRecursive(k, T->left);
    } else { // k > T->key
        // Nếu k lớn hơn khóa của nút hiện tại, tìm kiếm trong cây con bên phải.
        return TreeSearchRecursive(k, T->right);
    }
}