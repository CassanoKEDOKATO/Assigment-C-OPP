#ifndef LISTSP_H
#define LISTSP_H
#include <bits/stdc++.h>
#include "SanPham.h"
#include <vector>
class SanPhamList
{
private:
    std::vector<SanPham> sanPhamList;

public:
    SanPhamList();
    SanPhamList(std::vector<SanPham> _sanPhamList);
    void setListSanPham(std::vector<SanPham> _sanPhamList);
    std::vector<SanPham> getListSanPham();
    // CRUD
    void read();
    void create();
    void modify();
    void Delete();

    // File IOSTREAM

    void WriteProductToFile();
    void ReadProductFromFile();
    void BackupFileProduct();
    void RestoreFileProduct();
};
#endif