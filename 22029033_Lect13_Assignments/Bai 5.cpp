/^(\(\d{3}\)([\s\.\-])\d{3}\1\d{4}|\d{3}(?:([\s\-])\d{3}\2\d{4}|\d{7}))$/

^: Bắt đầu chuỗi.
(: Bắt đầu nhóm chụp chính (không bắt buộc phải chụp, có thể dùng (?:...)? cho toàn bộ nếu không cần chụp). Neo ^ và $ đủ để khớp toàn bộ.
\(\d{3}\): Khớp (ddd).
([\s\.\-]): Nhóm chụp 1. Chụp ký tự phân cách (, ., -) sau ).
\d{3}: Khớp 3 chữ số.
\1: Tham chiếu ngược đến Nhóm chụp 1.
\d{4}: Khớp 4 chữ số.
|: Hoặc (chuyển sang trường hợp bắt đầu bằng ddd).
\d{3}: Khớp 3 chữ số.
(?: ... ): Nhóm không chụp cho các khả năng sau 3 chữ số đầu.
([\s\-]): Nhóm chụp 2. Chụp ký tự phân cách (, -) sau 3 chữ số đầu.
\d{3}: Khớp 3 chữ số.
\2: Tham chiếu ngược đến Nhóm chụp 2.
\d{4}: Khớp 4 chữ số.
|: Hoặc (chuyển sang khả năng không có phân cách).
\d{7}: Khớp 7 chữ số liền nhau.
): Kết thúc nhóm không chụp (?:...).
): Kết thúc nhóm chụp chính (không bắt buộc).
$: Kết thúc chuỗi.