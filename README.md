# App Quản Lí Sinh Viên
- Demo : 
# Mô tả
- Thư viện sử dụng `winbgim.h`
- Sử dụng chức năng điều khiển bằng chuột.

# Tính năng
- [x] Thêm Sinh Viên
- [x] Tìm Kiếm Sinh Viên
- [x] Xóa Sinh Viên
- [x] Thêm tính năng điều khiển bằng chuột
- [x] Đọc Danh Sách Sinh Viên Từ File
- [x] Xuất Danh Sách Ra File
- [x] Sắp Xếp
- [x] Cấp Mã Sinh Viên Và Email

# Cài đặt
Tải file graphics-lib-devC.zip tại repo này về và giải nén, tiến hành

1. Copy:

– file libbgi.a vào thư mục lib (thường là C:\Program Files\Dev-Cpp\MinGW32\lib)

– file winbgim.h và graphics.h vào thư mục include (thường là C:\Program Files\Dev-Cpp\MinGW32\include)

– 2 file 6-ConsoleAppGraphics.template và file ConsoleApp_cpp_graph.txt vào thư mục Templates (thường là C:\Program Files\Dev-Cpp\Templates)

Nếu bạn dùng win 64 bit thì hãy download bản 32 bit về cài bình thường và copy các file như trên nhưng vào thư mục từ C:Program Files (x86)Dev-Cpp…

Xem thêm tại đây: https://cachhoc.net/2013/10/03/cc-do-hoa-trong-dev-c/


2. Đi tới Menu project > project options > parameters and type "-lwinmm" in the LINKER section. Cái này để DevC có thể play audio của game.
