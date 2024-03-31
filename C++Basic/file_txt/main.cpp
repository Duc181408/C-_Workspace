#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct sinhvien {
    string hoten;
    string masv;
    string namsinh;
    float Diem_TBHK;
};

typedef struct sinhvien SINHVIEN;

struct danhsach {
    SINHVIEN* arr; // con trỏ quản lý mảng động sinh viên
    int n;         // số lượng sinh viên hiện có trong danh sách
};

typedef struct danhsach DANHSACH;

void Doc_File_Thong_Tin_Sinh_Vien(ifstream& filein, SINHVIEN& sv) {
    getline(filein, sv.hoten, ',');
    filein.seekg(1, ios::cur); // Dịch con trỏ 1 byte, bỏ qua dấu phẩy
    getline(filein, sv.masv, ',');
    filein.seekg(1, ios::cur); // Dịch con trỏ 1 byte, bỏ qua dấu phẩy
    getline(filein, sv.namsinh, ',');
    filein >> sv.Diem_TBHK;
    filein.ignore(); // Đọc bỏ ký tự xuống dòng
}

void Doc_Danh_Sach_Sinh_Vien(ifstream& filein, DANHSACH& ds) {
    ds.arr = new SINHVIEN[ds.n];
    for (int i = 0; i < ds.n; i++) {
        Doc_File_Thong_Tin_Sinh_Vien(filein, ds.arr[i]);
    }
}

void Xuat_Thong_Tin(SINHVIEN x) {
    cout << "\nHo ten: " << x.hoten;
    cout << "\nMa so: " << x.masv;
    cout << "\nNgay thang nam sinh: " << x.namsinh;
    cout << "\nDiem trung binh hoc ki: " << x.Diem_TBHK;
}

void Xuat_Danh_Sach(DANHSACH ds) {
    for (int i = 0; i < ds.n; i++) {
        cout << "\n\nSINH VIEN THU " << i + 1;
        Xuat_Thong_Tin(ds.arr[i]);
    }
}

int main() {
    ifstream filein;
    filein.open("D:\\C++Worksapce\\file_txt\\SINHVIEN.TXT", ios_base::in);

    if (!filein.is_open()) {
        cout << "Khong mo duoc file!" << endl;
        return 1;
    }

    DANHSACH ds;
    int dem = 0;
    string line;
    while (getline(filein, line)) {
        dem++;
    }

    ds.n = dem;
    ds.arr = new SINHVIEN[ds.n];
    filein.clear();
    filein.seekg(0, ios::beg);

    Doc_Danh_Sach_Sinh_Vien(filein, ds);

    Xuat_Danh_Sach(ds);
    filein.close();
    delete[] ds.arr; // giải phóng bộ nhớ cho con trỏ
    return 0;
}
