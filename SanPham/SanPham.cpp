#include "SanPham.h"

SanPham::SanPham()
{
    maSP = "";
    tenSP = "";
    trongLuong = "";
    QCDongGoi = "";
};
SanPham::SanPham(std::string _maSP, std::string _tenSP, std::string _trongLuong, std::string _QCDongGoi)
{
    maSP = _maSP;
    tenSP = _tenSP;
    trongLuong = _trongLuong;
    QCDongGoi = _QCDongGoi;
};
void SanPham::setMaSP(const std::string &_maSP) { maSP = _maSP; };
void SanPham::setTenSP(const std::string &_tenSP) { tenSP = _tenSP; };
void SanPham::setTrongLuong(const std::string &_trongLuong) { trongLuong = _trongLuong; };
void SanPham::setQCDongGoi(const std::string &_QCDongGoi) { QCDongGoi = _QCDongGoi; };
std::string SanPham::getMaSP() const
{
    return maSP;
};
std::string SanPham::getTenSP() const
{
    return tenSP;
};
std::string SanPham::getTrongLuong() const
{
    return trongLuong;
};
std::string SanPham::getQCDongGoi() const
{
    return QCDongGoi;
};