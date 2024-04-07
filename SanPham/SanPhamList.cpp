#include "SanPhamList.h"

SanPhamList::SanPhamList(){

};
SanPhamList::SanPhamList(std::vector<SanPham> _sanPhamList)
{
    sanPhamList = _sanPhamList;
};
void SanPhamList::setListSanPham(std::vector<SanPham> _sanPhamList)
{
    sanPhamList = _sanPhamList;
};
std::vector<SanPham> SanPhamList::getListSanPham()
{
    return sanPhamList;
};
void SanPhamList::read()
{
    std::cout << "All List Products:" << std::endl;
    for (const auto &SPlist : sanPhamList)
    {
        std::cout << "Ma San Pham: " << SPlist.getMaSP() << " | ";
        std::cout << "Ten San Pham: " << SPlist.getTenSP() << " | ";
        std::cout << "Trong Luong : " << SPlist.getTrongLuong() << " | ";
        std::cout << "QC Dong Goi: " << SPlist.getQCDongGoi() << " | " << std::endl;
    }
};

void SanPhamList::create()
{
    std::string maSP, tenSP, trongLuong, QCDongGoi;
    std::cout << "Enter your information Products: " << std::endl;
    std::cout << "Ma SP: ";
    std::cin.ignore();
    std::getline(std::cin, maSP);
    std::cout << "Ten SP: ";
    std::getline(std::cin, tenSP);
    std::cout << "Trong Luong: ";
    std::getline(std::cin, trongLuong);
    std::cout << "QC Dong Goi: ";
    std::getline(std::cin, QCDongGoi);
    SanPham newProduct(maSP, tenSP, trongLuong, QCDongGoi);
    sanPhamList.push_back(newProduct);
    WriteProductToFile();
    std::cout << "Add new Product successfully." << std::endl;
};
void SanPhamList::modify()
{
   
    std::string id;
    std::cout << "Enter the ID of the product you want to modify: ";
      std::cin.ignore();
    std::getline(std::cin >> std::ws, id);

    auto it = std::find_if(sanPhamList.begin(), sanPhamList.end(),
                           [&](const SanPham &sp)
                           { return sp.getMaSP() == id; });

    if (it != sanPhamList.end())
    {
        // If the product is found, prompt the user for new details
        std::string newTenSP, newTrongLuong, newQCDongGoi;
        std::cout << "Enter new product details:\n";
        std::cout << "TenSP: ";
        std::getline(std::cin >> std::ws, newTenSP);
        std::cout << "TrongLuong: ";
        std::getline(std::cin >> std::ws, newTrongLuong);
        std::cout << "QCDongGoi: ";
        std::getline(std::cin >> std::ws, newQCDongGoi);

        // Modify the product's details
        it->setTenSP(newTenSP);
        it->setTrongLuong(newTrongLuong);
        it->setQCDongGoi(newQCDongGoi);
        WriteProductToFile();
        std::cout << "Product with ID " << id << " has been modified successfully.\n";
    }
    else
    {
        std::cout << "Product with ID " << id << " not found. Please try again.\n";
        // modify(); // Re-prompt for ID
    }
};
void SanPhamList::Delete()
{
    std::string maSP;
    std::cout << "Enter your ID product to delete: ";
    std::cin.ignore();
    std::getline(std::cin, maSP);


    for (auto it = sanPhamList.begin(); it != sanPhamList.end(); ++it)
    {
        if (it->getMaSP() == maSP)
        {
            sanPhamList.erase(it);
            WriteProductToFile();

            std::cout << "The Product deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Product with ID: " << maSP << " not found." << std::endl;
};

void SanPhamList::WriteProductToFile()
{
    std::ofstream OutputFile("SanPham/product.csv");
    if (!OutputFile.is_open())
    {
        std::cout << "Failed to open contacts file for writing.\n";
        return;
    }
    for (const SanPham &sanpham : sanPhamList)
    {
        OutputFile << sanpham.getMaSP() << "|"
                   << sanpham.getTenSP() << "|"
                   << sanpham.getTrongLuong() << "|"
                   << sanpham.getQCDongGoi() << "\n";
    }
    OutputFile.close();
    std::cout << "Product file updated successfully.\n";
};
void SanPhamList::ReadProductFromFile()
{

    std::ifstream inputFile("SanPham/product.csv");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open product file for reading.\n";
        return;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> fields;

        while (std::getline(ss, field, '|'))
        {
            fields.push_back(field);
        }

        if (fields.size() == 4)
        { // Số lượng trường dữ liệu phải khớp với số lượng thuộc tính của SanPham
            SanPham sp;
            sp.setMaSP(fields[0]);
            sp.setTenSP(fields[1]);
            sp.setTrongLuong(fields[2]);
            sp.setQCDongGoi(fields[3]);
            sanPhamList.push_back(sp);
        }
    }

    inputFile.close();
    std::cout << "Product file read successfully.\n";
};
void SanPhamList::BackupFileProduct()
{
    std::ofstream outputFile("BackupData/product_backup.csv");
    if (outputFile.is_open())
    {
        for (const auto &sanPham : sanPhamList)
        {
            outputFile << sanPham.getMaSP() << "|"
                       << sanPham.getTenSP() << "|"
                       << sanPham.getTrongLuong() << "|"
                       << sanPham.getQCDongGoi() << "\n";
        }
        outputFile.close();
        std::cout << "Data backup successful.\n";
    }
    else
    {
        std::cerr << "Error: Unable to open file for writing!\n";
    }
};
void SanPhamList::RestoreFileProduct()
{
    std::ifstream inputFile("BackupData/product_backup.csv");
    if (inputFile.is_open())
    {
        // Clear existing data
        sanPhamList.clear();

        std::string line;
        while (std::getline(inputFile, line))
        {
            std::istringstream iss(line);
            std::string maSP, tenSP, trongLuong, QCDongGoi;
            std::getline(iss, maSP, '|');
            std::getline(iss, tenSP, '|');
            std::getline(iss, trongLuong, '|');
            std::getline(iss, QCDongGoi, '|');
            sanPhamList.push_back(SanPham(maSP, tenSP, trongLuong, QCDongGoi));
        }
        WriteProductToFile();
        inputFile.close();
        std::cout << "Data restore successful.\n";
    }
    else
    {
        std::cerr << "Error: Unable to open file for reading!\n";
    }
};