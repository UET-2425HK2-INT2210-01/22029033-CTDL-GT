// Thuật toán 1: Tính 2^n bằng phương pháp lặp
long long calculatePowerOfTwoIterative(int n) { // Hàm nhận vào số nguyên n, trả về long long.
    if (n < 0) {                               // Kiểm tra nếu n là số âm.
        // Đối với 2^n khi n âm, kết quả là số thực (ví dụ: 2^-1 = 0.5).
        // Với yêu cầu trả về số nguyên, chúng ta có thể xử lý lỗi hoặc làm tròn.
        // Trong trường hợp này, giả định n >= 0, hoặc trả về một giá trị báo lỗi.
        // Để đơn giản, giả định n luôn không âm cho kiểu trả về long long.
        // Hoặc bạn có thể chuyển kiểu trả về thành double và tính 1.0 / calculatePowerOfTwoIterative(-n).
        return -1; // Trả về -1 để báo hiệu lỗi hoặc n không hợp lệ nếu n < 0.
    }
    if (n == 0) {                              // Trường hợp cơ sở: 2^0 bằng 1.
        return 1;                              // Trả về 1.
    }

    long long result = 1;                      // Khởi tạo kết quả ban đầu là 1.
    for (int i = 0; i < n; ++i) {              // Vòng lặp chạy n lần (từ 0 đến n-1).
        result *= 2;                           // Trong mỗi lần lặp, nhân kết quả với 2.
    }
    return result;                             // Trả về kết quả cuối cùng.
}

//--------------------------------------------------------------------------------------------------------------

// Thuật toán 2: Tính 2^n bằng phương pháp đệ quy (chia để trị)
long long calculatePowerOfTwoRecursive(int n) { // Hàm nhận vào số nguyên n, trả về long long.
    if (n < 0) {                               // Kiểm tra nếu n là số âm.
        return -1;                             // Trả về -1 để báo hiệu lỗi hoặc n không hợp lệ.
    }
    if (n == 0) {                              // Trường hợp cơ sở: 2^0 bằng 1.
        return 1;                              // Trả về 1.
    }
    if (n == 1) {                              // Trường hợp cơ sở: 2^1 bằng 2.
        return 2;                              // Trả về 2.
    }

    // Đệ quy để tính 2^(n/2).
    // Phép chia n/2 tự động làm tròn xuống đối với số nguyên (int).
    long long halfPower = calculatePowerOfTwoRecursive(n / 2); // Gọi đệ quy với n/2.

    if (n % 2 == 0) {                          // Nếu n là số chẵn.
        return halfPower * halfPower;          // Kết quả là (2^(n/2)) * (2^(n/2)).
    } else {                                   // Nếu n là số lẻ.
        return 2 * halfPower * halfPower;      // Kết quả là 2 * (2^((n-1)/2)) * (2^((n-1)/2)).
    }
}