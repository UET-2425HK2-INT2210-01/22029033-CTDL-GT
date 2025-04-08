// Hàm đệ quy phụ để đảo ngược số, revNum lưu kết quả tạm
int daoNguocSo(int n, int revNum = 0) 
{
    if (n == 0) // Điều kiện dừng: nếu n = 0 thì trả về số đã đảo
        return revNum;
    else
        return daoNguocSo(n / 10, revNum * 10 + n % 10); 
        // Gọi đệ quy: thêm chữ số cuối của n vào revNum, rồi tiếp tục với n bỏ đi chữ số cuối
}
