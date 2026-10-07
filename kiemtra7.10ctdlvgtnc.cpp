#include <iostream>
#include <string>
using namespace std;

struct KhachHang {
    int maKH;
    string tenKH;
    string soDienThoai;
    float tongTien;
};

void nhap(KhachHang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap khach hang thu " << i + 1 << ":" << endl;

        cout << "Ma khach hang: ";
        cin >> a[i].maKH;
        cin.ignore();

        cout << "Ten khach hang: ";
        getline(cin, a[i].tenKH);

        cout << "So dien thoai: ";
        getline(cin, a[i].soDienThoai);

        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongTien;
    }
}

void xuat(KhachHang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nKhach hang thu " << i + 1 << endl;
        cout << "Ma KH: " << a[i].maKH << endl;
        cout << "Ten KH: " << a[i].tenKH << endl;
        cout << "So dien thoai: " << a[i].soDienThoai << endl;
        cout << "Tong tien: " << a[i].tongTien << endl;
    }
}

void insertionSort(KhachHang a[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang x = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].tongTien > x.tongTien) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

int timKiem(KhachHang a[], int n, float x) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid].tongTien == x)
            return mid;

        if (a[mid].tongTien < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    KhachHang a[100];
    int n;
    float x;
    int viTri;

    cout << "Nhap so luong khach hang: ";
    cin >> n;

    nhap(a, n);

    cout << "\n===== DANH SACH VUA NHAP =====" << endl;
    xuat(a, n);

    insertionSort(a, n);

    cout << "\n===== DANH SACH SAU KHI SAP XEP =====" << endl;
    xuat(a, n);

    cout << "\nNhap tong tien X can tim: ";
    cin >> x;

    viTri = timKiem(a, n, x);

    if (viTri == -1) {
        cout << "Khong tim thay khach hang!" << endl;
    }
    else {
        cout << "\nKhach hang tim thay:" << endl;
        cout << "Ma KH: " << a[viTri].maKH << endl;
        cout << "Ten KH: " << a[viTri].tenKH << endl;
        cout << "So dien thoai: " << a[viTri].soDienThoai << endl;
        cout << "Tong tien: " << a[viTri].tongTien << endl;
    }

    return 0;
}