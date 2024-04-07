#include "ChiTietHoaDon.h"

ChiTietHoaDon::ChiTietHoaDon()
{
    soHD = "";
    maSP = "";
    soLuong = "";
    giaBan = "";
};
ChiTietHoaDon::ChiTietHoaDon(std::string _soHD, std::string _maSP, std::string _soLuong, std::string _giaBan)
{
    soHD = _soHD;
    maSP = _maSP;
    soLuong = _soLuong;
    giaBan = _giaBan;
};
void ChiTietHoaDon::setsoHD(const std::string & _soHD)
{
    soHD = _soHD;
};
void ChiTietHoaDon::setMaSP(const std::string &_maSP)
{
    maSP = _maSP;
};
void ChiTietHoaDon::setSoLuong(const std::string &_soLuong)
{
    soLuong = _soLuong;
};
void ChiTietHoaDon::setGiaBan(const std::string &_giaBan)
{
    giaBan = _giaBan;
};
std::string ChiTietHoaDon::getsoHD() const
{
    return soHD;
};
std::string ChiTietHoaDon::getMaSP() const
{
    return maSP;
};
std::string ChiTietHoaDon::getSoLuong() const
{
    return soLuong;
};
std::string ChiTietHoaDon::getGiaBan() const
{
    return giaBan;
};