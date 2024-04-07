#ifndef CHITIETHOADONLIST_H
#define CHITIETHOADONLIST_H
#include <bits/stdc++.h>
#include "ChiTietHoaDon.h"
#include <vector>
#include <numeric>

class ChiTietHoaDonList
{
private:
    std::vector<ChiTietHoaDon> chiTietHoaDonList;

public:
    ChiTietHoaDonList();
    ChiTietHoaDonList(std::vector<ChiTietHoaDon> _chiTietHoaDonList);
    void setListHoaDonChiTiet(std::vector<ChiTietHoaDon> _chiTietHoaDonList);
    std::vector<ChiTietHoaDon> getListHoaDonChiTiet();
    // CRUD
    void read();
    double calculateTotalAmount(const std::string &soHD) const;
    void create();
    void modify();
    void Delete();
    void topNSanPhamBanNhieuNhat(int N);
    void topNKhachHangMuaNhieuNhat(int N);
    // File IOSTREAM

    void WriteBillDetailToFile();
    void ReadBillDetailFromFile();
    void BackupFileBillDetails();
    void RestoreFileBillDetails();
};
#endif