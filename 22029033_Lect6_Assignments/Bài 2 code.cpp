#include <iostream>     
#include <vector>       
#include <algorithm>   
using namespace std;    

// Lớp Heap tổng quát 
class Heap {
private:
    vector<int> heap;       // Vector lưu các phần tử của heap
    bool isMinHeap;         // true nếu là min-heap, false nếu là max-heap

    // Hàm so sánh tùy theo loại heap
    bool compare(int a, int b) {
        return isMinHeap ? a < b : a > b; // min-heap: a < b, max-heap: a > b
    }

    // Hàm đẩy phần tử lên đúng vị trí
    void heapifyUp(int index) {
        while (index > 0) {                               // Khi chưa đến gốc
            int parent = (index - 1) / 2;                 // Lấy chỉ số cha
            if (compare(heap[index], heap[parent])) {     // Nếu vi phạm thứ tự heap
                swap(heap[index], heap[parent]);          // Đổi chỗ với cha
                index = parent;                           // Tiếp tục xét cha
            } else break;                                 // Đúng thứ tự rồi thì dừng
        }
    }

    // Hàm đẩy phần tử xuống đúng vị trí
    void heapifyDown(int index) {
        int size = heap.size();                           // Lấy kích thước heap
        while (index < size) {                            // Duyệt cho đến khi vượt quá size
            int left = 2 * index + 1;                     // Lấy chỉ số con trái
            int right = 2 * index + 2;                    // Lấy chỉ số con phải
            int chosen = index;                           // Giả định index là đúng vị trí

            if (left < size && compare(heap[left], heap[chosen]))
                chosen = left;                            // Nếu con trái đúng hơn thì chọn
            if (right < size && compare(heap[right], heap[chosen]))
                chosen = right;                           // Nếu con phải đúng hơn thì chọn

            if (chosen != index) {                        // Nếu cần đổi chỗ
                swap(heap[index], heap[chosen]);          // Đổi vị trí
                index = chosen;                           // Tiếp tục đẩy xuống
            } else break;                                 // Đúng vị trí rồi thì thoát
        }
    }

public:
    // Constructor nhận vào loại heap (true = min-heap, false = max-heap)
    Heap(bool isMin) {
        isMinHeap = isMin;                                // Gán giá trị cho biến isMinHeap
    }

    // Hàm chèn phần tử vào heap
    void insert(int value) {
        heap.push_back(value);                            // Thêm phần tử vào cuối vector
        heapifyUp(heap.size() - 1);                       // Gọi hàm đẩy lên từ cuối
    }

    // Hàm xóa phần tử cụ thể theo giá trị
    void deleteValue(int value) {
        auto it = find(heap.begin(), heap.end(), value);  // Tìm vị trí phần tử trong vector
        if (it == heap.end()) return;                     // Nếu không tìm thấy thì thoát

        int index = it - heap.begin();                    // Tính chỉ số của phần tử
        heap[index] = heap.back();                        // Gán phần tử cuối cho vị trí đó
        heap.pop_back();                                  // Xóa phần tử cuối

        heapifyUp(index);                                 // Gọi đẩy lên từ vị trí đó
        heapifyDown(index);                               // Gọi đẩy xuống từ vị trí đó
    }

    // Hàm in toàn bộ heap dạng mảng
    void printHeap(string title) {
        cout << title << ": ";                            // In tiêu đề
        for (int val : heap)                              // Duyệt từng phần tử
            cout << val << " ";                           // In giá trị
        cout << endl;                                     // Xuống dòng sau khi in
    }
};

// Hàm main: thực hiện in toàn bộ Min Heap trước, rồi Max Heap
int main() {
    // MIN HEAP
    Heap minHeap(true);                                   // Tạo Min Heap (true)

    int initial[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};        // Danh sách ban đầu
    for (int val : initial)
        minHeap.insert(val);                              // Chèn từng giá trị vào Min Heap

    minHeap.printHeap("Min Heap ban dau");                // In Min Heap ban đầu

    int addList[] = {14, 0, 35};                          // Danh sách phần tử thêm
    for (int val : addList)
        minHeap.insert(val);                              // Chèn từng giá trị vào Min Heap

    minHeap.printHeap("Min Heap sau insert");             // In Min Heap sau khi chèn

    int delList[] = {6, 13, 35};                          // Danh sách phần tử cần xóa
    for (int val : delList)
        minHeap.deleteValue(val);                         // Xóa từng giá trị khỏi Min Heap

    minHeap.printHeap("Min Heap sau delete");             // In Min Heap sau khi xóa


    // MAX HEAP
    Heap maxHeap(false);                                  // Tạo Max Heap (false)

    for (int val : initial)
        maxHeap.insert(val);                              // Chèn từng giá trị vào Max Heap

    maxHeap.printHeap("Max Heap ban dau");                // In Max Heap ban đầu

    for (int val : addList)
        maxHeap.insert(val);                              // Chèn từng giá trị vào Max Heap

    maxHeap.printHeap("Max Heap sau insert");             // In Max Heap sau khi chèn

    for (int val : delList)
        maxHeap.deleteValue(val);                         // Xóa từng giá trị khỏi Max Heap

    maxHeap.printHeap("Max Heap sau delete");             // In Max Heap sau khi xóa

    return 0;                                              // Kết thúc chương trình
}
