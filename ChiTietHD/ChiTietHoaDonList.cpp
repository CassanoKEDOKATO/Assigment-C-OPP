#include "ChiTietHoaDonList.h"

ChiTietHoaDonList::ChiTietHoaDonList(){};
ChiTietHoaDonList::ChiTietHoaDonList(std::vector<ChiTietHoaDon> _chiTietHoaDonList)
{
    chiTietHoaDonList = _chiTietHoaDonList;
};
void ChiTietHoaDonList::setListHoaDonChiTiet(std::vector<ChiTietHoaDon> _chiTietHoaDonList)
{
    chiTietHoaDonList = _chiTietHoaDonList;
};
std::vector<ChiTietHoaDon> ChiTietHoaDonList::getListHoaDonChiTiet()
{
    return chiTietHoaDonList;
};
// CRUD
void ChiTietHoaDonList::read()
{
    std::cout << "All List Bill Details:" << std::endl;
    for (const auto &billDetailList : chiTietHoaDonList)
    {
        std::cout << "Ma HD: " << billDetailList.getsoHD() << " | ";
        std::cout << "Ma SP: " << billDetailList.getMaSP() << " | ";
        std::cout << "So Luong: " << billDetailList.getSoLuong() << " | ";
        std::cout << "Gia Ban(VND): " << billDetailList.getGiaBan() << " | " << std::endl;
    }
};
double ChiTietHoaDonList::calculateTotalAmount(const std::string& soHD) const {
     double totalAmount = 0;
    for (const auto& chiTiet : chiTietHoaDonList) {
        std::cout << chiTiet.getsoHD() << ":" << soHD << '\n';
        if (chiTiet.getsoHD() == soHD) { 
            totalAmount += std::stod(chiTiet.getSoLuong()) * std::stod(chiTiet.getGiaBan());
        }
        else{
              std::cout << "ID Not Matching!!! " <<std::endl;
        }
    }
    return totalAmount;
    
}
 void ChiTietHoaDonList::topNSanPhamBanNhieuNhat(int N){
    std::unordered_map<std::string, int> soLuongBan; // Sử dụng unordered_map để lưu trữ số lượng bán của mỗi sản phẩm
    for (const auto& chiTiet : chiTietHoaDonList) {
        soLuongBan[chiTiet.getMaSP()] += std::stoi(chiTiet.getSoLuong()); // Tính tổng số lượng bán của mỗi sản phẩm
    }

    // Chuyển dữ liệu từ unordered_map sang vector để dễ sắp xếp
    std::vector<std::pair<std::string, int>> sortedSanPham;
    for (const auto& pair : soLuongBan) {
        sortedSanPham.push_back(pair);
    }

    // Sắp xếp các sản phẩm theo số lượng bán giảm dần
    std::sort(sortedSanPham.begin(), sortedSanPham.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // Hiển thị tên của N sản phẩm có số lượng bán nhiều nhất
    std::cout << "Top " << N << " san pham co so luong ban nhieu nhat:" << std::endl;
    for (int i = 0; i < N && i < sortedSanPham.size(); ++i) {
        std::cout << sortedSanPham[i].first << std::endl;
    }
 };
 
void ChiTietHoaDonList::create()
{
    std::string soHD, maSP, soLuong, giaBan;
    std::cout << "Enter your information Details Bill: " << std::endl;
    std::cout << "Ma Hoa Don: ";
    std::cin.ignore();
    std::getline(std::cin, soHD);
    std::cout << "Ma SP: ";
    std::cin.ignore();
    std::getline(std::cin, maSP);
    std::cout << "So Luong: ";
    std::getline(std::cin, soLuong);
    std::cout << "Gia Ban: ";
    std::getline(std::cin, giaBan);
    ChiTietHoaDon newBillDetails(soHD, maSP, soLuong, giaBan);
    chiTietHoaDonList.push_back(newBillDetails);
    WriteBillDetailToFile();
    std::cout << "Add new Details Bill successfully." << std::endl;
};
void ChiTietHoaDonList::modify()
{
    std::string id;
    std::cout << "Enter the ID of the Bill you want to modify: ";
    std::cin.ignore();
    std::getline(std::cin >> std::ws, id);

    auto it = std::find_if(chiTietHoaDonList.begin(), chiTietHoaDonList.end(),
                           [&](const ChiTietHoaDon &cthd)
                           { return cthd.getsoHD() == id; });

    if (it != chiTietHoaDonList.end())
    {
        // If the product is found, prompt the user for new details
        std::string maSP, soLuong, giaBan;
        std::cout << "Enter new information Bill Details:\n";
        std::cout << "Ma San Pham: ";
        std::getline(std::cin >> std::ws, maSP);
        std::cout << "So Luong: ";
        std::getline(std::cin >> std::ws, soLuong);
        std::cout << "Gia Ban: ";
        std::getline(std::cin >> std::ws, giaBan);

        // Modify the product's details
        it->setMaSP(maSP);
        it->setSoLuong(soLuong);
        it->setGiaBan(giaBan);
        WriteBillDetailToFile();
        std::cout << "Bill Details with ID " << id << " has been modified successfully.\n";
    }
    else
    {
        std::cout << "Bill Details with ID " << id << " not found. Please try again.\n";
        // modify(); // Re-prompt for ID
    }
};
void ChiTietHoaDonList::Delete()
{
    std::string maHD;
    std::cout << "Enter your ID Bill Details to delete: ";
    std::cin.ignore();
    std::getline(std::cin, maHD);

    for (auto it = chiTietHoaDonList.begin(); it != chiTietHoaDonList.end(); ++it)
    {
        if (it->getsoHD() == maHD)
        {
            chiTietHoaDonList.erase(it);
            WriteBillDetailToFile();

            std::cout << "The Bill Details deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Bill Details with ID: " << maHD << " not found." << std::endl;
};

// File IOSTREAM

void ChiTietHoaDonList::WriteBillDetailToFile()
{
    std::ofstream OutputFile("ChiTietHD/chitiethoadon.csv");
    if (!OutputFile.is_open())
    {
        std::cout << "Failed to open Bill file for writing.\n";
        return;
    }
    for (const ChiTietHoaDon &chitiethoadon : chiTietHoaDonList)
    {
        OutputFile << chitiethoadon.getsoHD() << "|"
                   << chitiethoadon.getMaSP() << "|"
                   << chitiethoadon.getSoLuong() << "|"
                   << chitiethoadon.getGiaBan() << "\n";
    }
    OutputFile.close();
    std::cout << "Bill Details file updated successfully.\n";
};
void ChiTietHoaDonList::ReadBillDetailFromFile()
{
    std::ifstream inputFile("ChiTietHD/chitiethoadon.csv");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open Bill Details file for reading.\n";
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
            ChiTietHoaDon cthd;
            cthd.setsoHD(fields[0]);
            cthd.setMaSP(fields[1]);
            cthd.setSoLuong(fields[2]);
            cthd.setGiaBan(fields[3]);
            chiTietHoaDonList.push_back(cthd);
        }
    }

    inputFile.close();
    std::cout << "Bill Details file read successfully.\n";
};
void ChiTietHoaDonList::BackupFileBillDetails()
{
    std::ofstream outputFile("BackupData/bill_details_backup.csv");
    if (outputFile.is_open())
    {
        for (const auto &billDetails : chiTietHoaDonList)
        {
            outputFile << billDetails.getsoHD() << "|"
                       << billDetails.getMaSP() << "|"
                       << billDetails.getSoLuong() << "|"
                       << billDetails.getGiaBan() << "\n";
        }
        outputFile.close();
        std::cout << "Data backup successful.\n";
    }
    else
    {
        std::cerr << "Error: Unable to open file for writing!\n";
    }
};
void ChiTietHoaDonList::RestoreFileBillDetails()
{
    std::ifstream inputFile("BackupData/bill_details_backup.csv");
    if (inputFile.is_open())
    {
        // Clear existing data
        chiTietHoaDonList.clear();

        std::string line;
        while (std::getline(inputFile, line))
        {
            std::istringstream iss(line);
            std::string soHD, maSP, soLuong, giaBan;
            std::getline(iss, soHD, '|');
            std::getline(iss, maSP, '|');
            std::getline(iss, soLuong, '|');
            std::getline(iss, giaBan, '|');
            chiTietHoaDonList.push_back(ChiTietHoaDon(soHD, maSP, soLuong, giaBan));
        }
         WriteBillDetailToFile();
        inputFile.close();
        std::cout << "Data restore successful.\n";
    }
    else
    {
        std::cerr << "Error: Unable to open file for reading!\n";
    }
};