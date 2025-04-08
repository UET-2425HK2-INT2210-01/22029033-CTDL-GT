// Hàm đệ quy tính tổng các chữ số của một số nguyên dương n
int tongChuSo(int n) 
{
    if (n < 10) // Trường hợp: nếu n chỉ còn 1 chữ số thì trả về chính nó
        return n;
    else
        return (n % 10) + tongChuSo(n / 10); 
        // Gọi đệ quy: cộng chữ số cuối với tổng chữ số còn lại
}
