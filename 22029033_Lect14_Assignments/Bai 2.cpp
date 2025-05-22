// HÀM TÌM SỐ LẺ NHỎ NHẤT TRONG DANH SÁCH LIÊN KẾT HEAD.
// Trả về giá trị số lẻ nhỏ nhất, hoặc INT_MAX nếu không có số lẻ nào.
int findSmallestOdd(Node* head) { // head được truyền bằng giá trị vì không thay đổi danh sách.
    // Khởi tạo smallestOdd với giá trị lớn nhất có thể của kiểu int.
    int smallestOdd = numeric_limits<int>::max(); // Đảm bảo mọi số lẻ sẽ nhỏ hơn giá trị này.
    bool foundOdd = false;                        // Cờ để kiểm tra xem có tìm thấy số lẻ nào không.

    Node* current = head;         // Bắt đầu duyệt từ node đầu tiên.
    while (current != nullptr) {  // Lặp cho đến khi duyệt hết danh sách.
        // Kiểm tra nếu data của node hiện tại là số lẻ (không chia hết cho 2).
        if (current->data % 2 != 0) {
            foundOdd = true;      // Đánh dấu rằng đã tìm thấy ít nhất một số lẻ.
            // Nếu số lẻ hiện tại nhỏ hơn smallestOdd đã tìm thấy trước đó.
            if (current->data < smallestOdd) {
                smallestOdd = current->data; // Cập nhật smallestOdd.
            }
        }
        current = current->next;  // Di chuyển đến node kế tiếp.
    }

    // Nếu không tìm thấy số lẻ nào, trả về giá trị max đã khởi tạo.
    if (!foundOdd) {
        return numeric_limits<int>::max(); // Trả về giá trị ban đầu nếu không có số lẻ.
    }
    return smallestOdd;               // Trả về số lẻ nhỏ nhất đã tìm thấy.
}

//-------------------------------------------------------------------------------------------------------------

// HÀM XÓA TẤT CẢ SỐ LẺ KHỎI DANH SÁCH LIÊN KẾT HEAD.
void removeAllOdd(Node*& head) { // head được truyền bằng tham chiếu để có thể thay đổi node đầu.
    // Tạo một node giả (dummy node) để đơn giản hóa việc xử lý các trường hợp xóa ở đầu danh sách.
    Node dummy(0);                // Node giả, giá trị data không quan trọng.
    dummy.next = head;             // Node giả trỏ tới đầu danh sách thực sự.

    Node* previous = &dummy;       // Con trỏ previous bắt đầu từ node giả.
    Node* current = head;          // Con trỏ current bắt đầu từ node đầu tiên của danh sách gốc.

    while (current != nullptr) {   // Lặp cho đến khi duyệt hết danh sách.
        // Nếu dữ liệu của node hiện tại là số lẻ.
        if (current->data % 2 != 0) {
            // Bỏ qua node hiện tại bằng cách nối previous với node sau current.
            previous->next = current->next;
            Node* nodeToDelete = current; // Lưu con trỏ của node cần xóa.
            current = current->next;      // Di chuyển current tới node tiếp theo.
            delete nodeToDelete;          // Giải phóng bộ nhớ của node số lẻ.
        } else { // Nếu dữ liệu của node hiện tại là số chẵn.
            previous = current;           // Di chuyển previous tới node hiện tại.
            current = current->next;      // Di chuyển current tới node tiếp theo.
        }
    }

    // Cập nhật con trỏ head của danh sách gốc với head mới từ node giả.
    head = dummy.next; // Head mới có thể là NULL nếu tất cả các node đều bị xóa.
}