#include "HoaDon.h"

HoaDon::HoaDon()
{
    soHD = "";
    ngayBan = "";
    maKH = "";
}
HoaDon::HoaDon(std::string _soHD, std::string _ngayBan, std::string _maKH)
{
    soHD = _soHD;
    ngayBan = _ngayBan;
    maKH = _maKH;
}
void HoaDon::setsoHD(const std::string& _soHD)
{
    soHD = _soHD;
};
void HoaDon::setNgayBan(const std::string& _ngayBan)
{
    ngayBan = _ngayBan;
};
void HoaDon::setMaKH(const std::string& _maKH)
{
    maKH = _maKH;
};
std::string HoaDon::getsoHD() const
{
    return soHD;
};
std::string HoaDon::getNgayBan() const
{
    return ngayBan;
};
std::string HoaDon::getMaKH() const
{
    return maKH;
};
