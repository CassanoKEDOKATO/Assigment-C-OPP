#ifndef CHITIETHOADON_H
#define CHITIETHOADON_H
#include <bits/stdc++.h>

class ChiTietHoaDon
{
private:
    std::string soHD;
    std::string maSP;
    std::string soLuong;
    std::string giaBan;

public:
    ChiTietHoaDon();
    ChiTietHoaDon(std::string _soHD, std::string _maSP, std::string _soLuong, std::string _giaBan);
    void setsoHD(const std::string &_soHD);
    void setMaSP(const std::string &_maSP);
    void setSoLuong(const std::string &_soLuong);
    void setGiaBan(const std::string &_giaBan);
    std::string getsoHD() const;
    std::string getMaSP() const;
    std::string getSoLuong() const;
    std::string getGiaBan() const;
};
#endif