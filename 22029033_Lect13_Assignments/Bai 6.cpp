/^[0-9a-zA-Z]+(?:[_\s-][0-9a-zA-Z]+)*$/

^: Khớp với điểm bắt đầu của chuỗi.
[0-9a-zA-Z]+: Khớp với một hoặc nhiều ký tự chữ số, chữ cái viết thường hoặc viết hoa. Điều này đảm bảo chuỗi bắt đầu bằng một ký tự không phải phân cách và không rỗng, đồng thời xử lý các chuỗi chỉ chứa ký tự không phải phân cách (ví dụ: "abc123").
(?: ... )*: Khớp với nhóm bên trong dấu ngoặc không hoặc nhiều lần. Nhóm không chụp (?:...) được sử dụng để nhóm các phần tử mà không tạo ra một nhóm chụp riêng.
[_\s-]: Khớp với một ký tự phân cách (gạch ngang, gạch dưới, hoặc khoảng trắng).
[0-9a-zA-Z]+: Khớp với một hoặc nhiều ký tự chữ số hoặc chữ cái.
Phần [_\s-][0-9a-zA-Z]+ đảm bảo rằng mỗi ký tự phân cách được theo sau bởi ít nhất một ký tự không phải phân cách, do đó ngăn chặn hai ký tự phân cách liên tiếp và đảm bảo chuỗi không kết thúc bằng ký tự phân cách (vì mỗi segment lặp lại kết thúc bằng [0-9a-zA-Z]+).
$: Khớp với điểm kết thúc của chuỗi.