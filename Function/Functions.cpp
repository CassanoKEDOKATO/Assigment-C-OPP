#include "../SanPham/SanPham.h"
#include "../SanPham/SanPham.h"
#include "../SanPham/SanPhamList.h"
#include "../HoaDon/HoaDon.h"
#include "../HoaDon/HoaDonList.h"
#include "../ChiTietHD/ChiTietHoaDon.h"
#include "../ChiTietHD/ChiTietHoaDonList.h"
#include "Functions.h"
void topNKhachHangMuaNhieuNhat(SanPhamList &splist, HoaDonList &hdlist, ChiTietHoaDonList &cthdlist){
    int N;
    std::cout << "Nhap so luong khach hang muon thong ke: ";
    std::cin >> N;

    // Lấy danh sách khách hàng từ hóa đơn
    std::vector<HoaDon> hoaDonList = hdlist.getListHoaDon();

    // Lấy danh sách chi tiết hóa đơn
    std::vector<ChiTietHoaDon> chiTietHoaDonList = cthdlist.getListHoaDonChiTiet();

    // Khởi tạo một unordered_map để lưu tổng tiền mua hàng của từng khách hàng
    std::unordered_map<std::string, double> tongTienMuaHang;

    // Duyệt qua danh sách hóa đơn để tính tổng tiền mua hàng của từng khách hàng
    for (const auto& hoaDon : hoaDonList) {
        double tongTien = 0;
        for (const auto& chiTiet : chiTietHoaDonList) {
            if (chiTiet.getsoHD() == hoaDon.getsoHD()) {
                // Tính tổng tiền mua hàng bằng cách nhân số lượng với giá bán và cộng dồn vào tổng tiền
                tongTien += std::stod(chiTiet.getSoLuong()) * std::stod(chiTiet.getGiaBan());
            }
        }
        tongTienMuaHang[hoaDon.getMaKH()] += tongTien;
    }

    // Chuyển dữ liệu từ unordered_map sang vector để dễ sắp xếp
    std::vector<std::pair<std::string, double>> sortedKhachHang;
    for (const auto& pair : tongTienMuaHang) {
        sortedKhachHang.push_back(pair);
    }

    // Sắp xếp các khách hàng theo tổng tiền mua hàng giảm dần
    std::sort(sortedKhachHang.begin(), sortedKhachHang.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Hiển thị tên của N khách hàng đã mua hàng với tổng tiền nhiều nhất
    std::cout << "Top " << N << " khach hang da mua hang voi tong tien nhieu nhat:" << std::endl;
    for (int i = 0; i < N && i < sortedKhachHang.size(); ++i) {
        std::cout << "Ma khach hang: " << sortedKhachHang[i].first << ", Tong tien: " << sortedKhachHang[i].second << std::endl;
    }
}


// Given a class of car as follows 
// Class car( string Id, string *BrandName, double Price)
// Write program to manage class including the following task
// -define class
// -2 constructor
// -destructor
// -main function


// Given infomation of a product as follow (productID, productName, quantity)
// Write a program to manage a list products using array the program has the following functionalitics:
// -2 constructor
// -input/output methods
// -public interfaces(setter/getter)