# Graph Theory Algorithms in C++ 🚀

**Bộ thư viện và giải thuật Lý thuyết đồ thị (Graph Theory)** được triển
khai bằng C++ theo hướng đối tượng (OOP). Dự án này tập trung vào việc
xây dựng clean code, tái sử dụng cao và tối ưu hiệu năng.

![C++](https://img.shields.io/badge/Language-C++17-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-lightgrey.svg)
![License](https://img.shields.io/badge/License-MIT-green.svg)

## 📂 Cấu trúc dự án (Project Structure)

``` text
Graph-Theory-CPP/
├── include/              # Header files (.h) - Chứa khai báo lớp và cấu trúc dữ liệu
│   ├── Graph.h           
│   └── DSU.h             
├── src/                  # Source files (.cpp) - Triển khai thuật toán
│   └── Graph.cpp         
├── exercises/            # Các bài tập thực hành áp dụng thư viện
│   ├── Bai37_QuanDaoChim.cpp
│   ├── Bai41_SuaDuong.cpp
│   ├── Bai49_Neverland.cpp
│   ├── Bai52_XayThuVien.cpp
│   └── Bai53_SaoHoa.cpp
├── .gitignore            # Quy tắc loại bỏ file không cần commit
└── README.md  

```

## 🛠 Tính năng & Thuật toán (Features)

Class **Graph** hỗ trợ cả đồ thị có hướng và vô hướng, bao gồm:

### 🔹 Tìm đường đi ngắn nhất

-   **Dijkstra** -- tối ưu cho đồ thị trọng số không âm
-   **Bellman-Ford** -- phát hiện chu trình âm

### 🔹 Cây khung nhỏ nhất (MST)

-   **Kruskal** -- sử dụng DSU

### 🔹 Tính liên thông & cấu trúc đồ thị

-   **Tarjan** -- tìm articulation points
-   **BFS/DFS** -- duyệt đồ thị, đếm thành phần liên thông

## 📚 Danh sách bài tập (Case Studies)

| File Code | Tên Bài Toán | Thuật toán chủ đạo | Mô tả ngắn |
|-----------|--------------|--------------------|------------|
| `Bai41_SuaDuong.cpp` | **Sửa Đường** | MST (Kruskal) | Tìm chi phí tối thiểu để kết nối tất cả các thành phố. |
| `Bai49_Neverland.cpp` | **Neverland** | Dijkstra (Layered) | Tìm đường đi ngắn nhất trên đồ thị phân tầng (kỹ thuật nhân bản đỉnh). |
| `Bai37_QuanDaoChim.cpp` | **Quần Đảo Chìm** | Tarjan | Xác định các điểm yếu (đỉnh trụ) trong mạng lưới giao thông. |
| `Bai52_XayThuVien.cpp` | **Xây Thư Viện** | Components (BFS) | Bài toán tối ưu chi phí dựa trên số lượng thành phần liên thông. |
| `Bai53_SaoHoa.cpp` | **Đường Lên Sao Hỏa** | Combinatorics | Ứng dụng thành phần liên thông để tính toán tổ hợp cặp đôi. |

## 🚀 Hướng dẫn cài đặt & Chạy (Getting Started)

### Yêu cầu

-   Visual Studio 2019/2022
-   Hoặc GCC hỗ trợ C++11 trở lên

------------------------------------------------------------------------

## ▶️ Cách chạy với Visual Studio (Khuyến nghị)

Do dự án chứa nhiều file bài tập, **mỗi file đều có hàm `main()`**, cần
cấu hình để **chỉ chạy một file tại mỗi thời điểm**.

### **Bước 1:** Mở project

Mở file `.sln` hoặc mở folder dự án bằng Visual Studio.

### **Bước 2:** Chọn bài muốn chạy

Trong **Solution Explorer**:
➡ Chuột phải file (VD: `Bai41_SuaDuong.cpp`) → **Properties**

### **Bước 3:** Tắt build những file bài tập khác

Lặp lại cho từng file khác:

1.  Chuột phải file → **Properties**
2.  Vào **Configuration Properties → General**
3.  Đặt **Exclude From Build = Yes** (cả Debug và Release)

👉 Cách này tránh lỗi `LNK2005: main already defined`.

### **Bước 4:** Build & Run

-   Nhấn **Ctrl + F5** để chạy
-   Hoặc **F5** để debug

------------------------------------------------------------------------

## 💻 Chạy bằng Terminal (G++)

    g++ -I./include src/Graph.cpp exercises/Bai41_SuaDuong.cpp -o solution
    ./solution

------------------------------------------------------------------------

## 🤝 Đóng góp (Contributing)

Hoan nghênh mọi đóng góp hoặc PR để cải thiện thuật toán và cấu trúc dự
án.

## 👤 Tác giả

Developed by **Cuong512**



