#ifndef SANPHAM_H
#define SANPHAM_H
#include <bits/stdc++.h>

class SanPham
{
private:
    std::string maSP;
    std::string tenSP;
    std::string trongLuong;
    std::string QCDongGoi;

public:
    SanPham();
    SanPham(std::string _maSP, std::string _tenSP, std::string _trongLuong, std::string _QCDongGoi);
    void setMaSP(const std::string &_maSP);
    void setTenSP(const std::string &_tenSP);
    void setTrongLuong(const std::string &_trongLuong);
    void setQCDongGoi(const std::string &_QCDongGoi);
    std::string getMaSP() const;
    std::string getTenSP() const;
    std::string getTrongLuong() const;
    std::string getQCDongGoi() const;
};
#endif