#ifndef LISTHD_H
#define LISTHD_H

#include <bits/stdc++.h>
#include "HoaDon.h"
#include <vector>
class HoaDonList
{
private:
    std::vector<HoaDon> hoaDonList;

public:
    HoaDonList();
    HoaDonList(std::vector<HoaDon> _hoaDonList);
    void setListHoaDon(std::vector<HoaDon> _hoaDonList);
    std::vector<HoaDon> getListHoaDon();
    // CRUD
    void read();
    void create();
    void modify();
    void Delete();

    // File IOSTREAM

    void WriteBillToFile();
    void ReadBillFromFile();
     void BackupFileBill();
    void RestoreFileBill();
};
#endif