#include <bits/stdc++.h>
#include "SanPham/SanPham.h"
#include "SanPham/SanPhamList.h"
#include "HoaDon/HoaDon.h"
#include "HoaDon/HoaDonList.h"
#include "ChiTietHD/ChiTietHoaDon.h"
#include "ChiTietHD/ChiTietHoaDonList.h"
#include "Function/Functions.h"
int main()
{

    SanPhamList sp_list;
    HoaDonList hd_list;
    ChiTietHoaDonList cthd_list;
    sp_list.ReadProductFromFile();
    hd_list.ReadBillFromFile();
    cthd_list.ReadBillDetailFromFile();
    std::string soHD;
    double totalAmount;
    int N;
    int choice;
    do
    {
        std::cout << "------------- BAI TAP THUC HANH C++ ------------" << std::endl;
        std::cout << "1.CRUD San Pham : " << std::endl;
        std::cout << "2.CRUD Hoa Don : " << std::endl;
        std::cout << "3.CRUD Chi Tiet Hoa Don : " << std::endl;
        std::cout << "4.Tinh Tong Tien Hoa Don (Cau_3): " << std::endl;
        std::cout << "5.Thong Ke San Pham Ban Nhieu Nhat (Cau_4): " << std::endl;
        std::cout << "6.Thong Ke Khach Hang Mua Hang Nhieu Nhat (Cau_5): " << std::endl;
        std::cout << "7. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cout << "---------------------------------------" << std::endl;
        switch (choice)
        {
        case 1:
            int subchoise_1;

            do
            {
                std::cout << "------------- CRUD San Pham ------------" << std::endl;
                std::cout << "1.Hien Thi Danh Sach San Pham : " << std::endl;
                std::cout << "2.Them San Pham : " << std::endl;
                std::cout << "3.Sua San Pham  : " << std::endl;
                std::cout << "4.Xoa San Pham  : " << std::endl;
                std::cout << "5.Backup San Pham  : " << std::endl;
                std::cout << "6.Rerstore San Pham  : " << std::endl;
                std::cout << "7. Quit" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> subchoise_1;
                std::cout << "---------------------------------------" << std::endl;
                switch (subchoise_1)
                {
                case 1:
                    sp_list.read();
                    break;
                case 2:
                    sp_list.create();
                    break;
                case 3:
                    sp_list.modify();
                    break;
                case 4:
                    sp_list.Delete();
                    break;
                case 5:
                    sp_list.BackupFileProduct();
                    break;
                case 6:
                    sp_list.RestoreFileProduct();
                    break;
                default:
                    break;
                }
            } while (subchoise_1 != 7);

            break;
        case 2:
            int subchoise_2;
            do
            {
                std::cout << "------------- CRUD Hoa Don ------------" << std::endl;
                std::cout << "1.Hien Thi Danh Sach Hoa Don : " << std::endl;
                std::cout << "2.Them Hoa Don : " << std::endl;
                std::cout << "3.Sua Hoa Don  : " << std::endl;
                std::cout << "4.Xoa Hoa Don  : " << std::endl;
                std::cout << "5.Backup San Pham  : " << std::endl;
                std::cout << "6.Rerstore San Pham  : " << std::endl;
                std::cout << "7. Quit" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> subchoise_2;
                std::cout << "---------------------------------------" << std::endl;
                switch (subchoise_2)
                {
                case 1:
                    hd_list.read();
                    break;
                case 2:
                    hd_list.create();
                    break;
                case 3:
                    hd_list.modify();
                    break;
                case 4:
                    hd_list.Delete();
                    break;
                case 5:
                    hd_list.BackupFileBill();
                    break;
                case 6:
                    hd_list.RestoreFileBill();
                    break;
                default:
                    break;
                }
            } while (subchoise_2 != 7);

            break;
        case 3:
            int subchoise_3;
            do
            {
                std::cout << "------------- CRUD Chi Tiet Hoa Don ------------" << std::endl;
                std::cout << "1.Hien Thi Danh Sach Chi Tiet Hoa Don : " << std::endl;
                std::cout << "2.Them Chi Tiet Hoa Don: " << std::endl;
                std::cout << "3.Sua Chi Tiet Hoa Don  : " << std::endl;
                std::cout << "4.Xoa Chi Tiet Hoa Don  : " << std::endl;
                std::cout << "5.Backup San Pham  : " << std::endl;
                std::cout << "6.Rerstore San Pham  : " << std::endl;
                std::cout << "7. Quit" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> subchoise_3;
                std::cout << "---------------------------------------" << std::endl;
                switch (subchoise_3)
                {
                case 1:
                    cthd_list.read();
                    break;
                case 2:
                    cthd_list.create();
                    break;
                case 3:
                    cthd_list.modify();
                    break;
                case 4:
                    cthd_list.Delete();
                    break;
                case 5:
                    cthd_list.BackupFileBillDetails();
                    break;
                case 6:
                    cthd_list.RestoreFileBillDetails();
                    break;
                default:
                    break;
                }
            } while (subchoise_3 != 7);

            break;
        case 4:

            std::cout << "Enter the invoice number: ";
            std::cin >> soHD;
            totalAmount = cthd_list.calculateTotalAmount(soHD);
            std::cout << "Total amount for invoice " << soHD << ": " << totalAmount << std::endl;

            break;
        case 5:

            std::cout << "Nhap so luong san pham muon thong ke: ";
            std::cin >> N;
            cthd_list.topNSanPhamBanNhieuNhat(N);
            break;
        case 6:
            topNKhachHangMuaNhieuNhat(sp_list,hd_list,cthd_list);
            break;
        default:
            break;
        }
    } while (choice != 7);
    return 0;
}