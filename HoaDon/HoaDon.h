#ifndef HOADON_H
#define HOADON_H
#include <bits/stdc++.h>

class HoaDon
{
private:
     std::string soHD;
    std::string ngayBan;
    std::string maKH;

public:
    HoaDon();
    HoaDon( std::string _soHD, std::string _ngayBan, std::string _maKH);
    void setsoHD( const std::string& _soHD);
    void setNgayBan(const std::string& _ngayBan);
    void setMaKH(const std::string& _maKH);
    std::string getsoHD() const;
    std::string getNgayBan() const;
    std::string getMaKH() const;
};
#endif