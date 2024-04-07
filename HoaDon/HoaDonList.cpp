#include "HoaDonList.h"

HoaDonList::HoaDonList(){};
HoaDonList::HoaDonList(std::vector<HoaDon> _hoaDonList){
    hoaDonList = _hoaDonList;
};
void HoaDonList::setListHoaDon(std::vector<HoaDon> _hoaDonList){
    hoaDonList = _hoaDonList;
};
std::vector<HoaDon> HoaDonList::getListHoaDon(){
    return hoaDonList;
};
// CRUD
void HoaDonList::read(){
     std::cout << "All List Bill:" << std::endl;
    for (const auto &billList : hoaDonList)
    {
        std::cout << "Ma Hoa Don: " << billList.getsoHD() << " | ";
        std::cout << "Ngay Ban: " << billList.getNgayBan() << " | ";
        std::cout << "Ma Khach Hang: " << billList.getMaKH() << " | " << std::endl;
    }
};
void HoaDonList::create(){
 
    std::string soHD,ngayBan, maKH;
    std::cout << "Enter your information Bill: " << std::endl;
    std::cout << "Ma Hoa Don: ";
    std::cin.ignore();
    std::getline(std::cin, soHD);
    std::cout << "Ngay Ban: ";
    std::cin.ignore();
    std::getline(std::cin, ngayBan);
    std::cout << "Ma Khach Hang: ";
    std::getline(std::cin, maKH);
    HoaDon newBill(soHD, ngayBan, maKH);
    hoaDonList.push_back(newBill);
    WriteBillToFile();
    std::cout << "Add new Bill successfully." << std::endl;
};
void HoaDonList::modify(){
    std::string id;
    std::cout << "Enter the ID of the Bill you want to modify: ";
      std::cin.ignore();
    std::getline(std::cin >> std::ws, id);

    auto it = std::find_if(hoaDonList.begin(), hoaDonList.end(),
                           [&](const HoaDon &hd)
                           { return hd.getsoHD() == id; });

    if (it != hoaDonList.end())
    {
        // If the product is found, prompt the user for new details
        std::string ngayBan, maKH;
        std::cout << "Enter new information Bill:\n";
        std::cout << "Ngay Ban: ";
        std::getline(std::cin >> std::ws, ngayBan);
        std::cout << "Ma Khach Hang: ";
        std::getline(std::cin >> std::ws, maKH);

        // Modify the product's details
        it->setNgayBan(ngayBan);
        it->setMaKH(maKH);
        WriteBillToFile();
        std::cout << "Bill with ID " << id << " has been modified successfully.\n";
    }
    else
    {
        std::cout << "Bill with ID " << id << " not found. Please try again.\n";
        // modify(); // Re-prompt for ID
    }};
void HoaDonList::Delete(){
    std::string maHD;
    std::cout << "Enter your ID Bill to delete: ";
    std::cin.ignore();
    std::getline(std::cin, maHD);


    for (auto it = hoaDonList.begin(); it != hoaDonList.end(); ++it)
    {
        if (it->getsoHD() == maHD)
        {
            hoaDonList.erase(it);
            WriteBillToFile();

            std::cout << "The Bill deleted successfully." << std::endl;
            return;
        }
    }
    std::cout << "Product with ID: " << maHD << " not found." << std::endl;
};

// File IOSTREAM

void HoaDonList::WriteBillToFile(){
    std::ofstream OutputFile("HoaDon/hoadon.csv");
    if (!OutputFile.is_open())
    {
        std::cout << "Failed to open Bill file for writing.\n";
        return;
    }
    for (const HoaDon &hoadon : hoaDonList)
    {
        OutputFile << hoadon.getsoHD() << "|"
                   << hoadon.getNgayBan() << "|"
                   << hoadon.getMaKH() << "\n";
    }
    OutputFile.close();
    std::cout << "Bill file updated successfully.\n";
};
void HoaDonList::ReadBillFromFile(){
    std::ifstream inputFile("HoaDon/hoadon.csv");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open Bill file for reading.\n";
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

        if (fields.size() == 3)
        { // Số lượng trường dữ liệu phải khớp với số lượng thuộc tính của SanPham
            HoaDon hd;
            hd.setsoHD(fields[0]);
            hd.setNgayBan(fields[1]);
            hd.setMaKH(fields[2]);
            hoaDonList.push_back(hd);
        }
    }

    inputFile.close();
    std::cout << "Bill file read successfully.\n";
};
 void HoaDonList::BackupFileBill(){
    std::ofstream outputFile("BackupData/bill_backup.csv");
    if (outputFile.is_open())
    {
        for (const auto &hoadon : hoaDonList)
        {
            outputFile << hoadon.getsoHD() << "|"
                       << hoadon.getNgayBan() << "|"
                       << hoadon.getMaKH() << "\n";
        }
        outputFile.close();
        std::cout << "Data backup successful.\n";
    }
    else
    {
        std::cerr << "Error: Unable to open file for writing!\n";
    }
 };
    void HoaDonList::RestoreFileBill(){
         std::ifstream inputFile("BackupData/bill_backup.csv");
    if (inputFile.is_open())
    {
        // Clear existing data
        hoaDonList.clear();

        std::string line;
        while (std::getline(inputFile, line))
        {
            std::istringstream iss(line);
            std::string soHD, ngayBan, maKH;
            std::getline(iss, soHD, '|');
            std::getline(iss, ngayBan, '|');
            std::getline(iss, maKH, '|');
            hoaDonList.push_back(HoaDon(soHD, ngayBan, maKH));
        }
        WriteBillToFile();
        inputFile.close();
        std::cout << "Data restore successful.\n";
    }
    else
    {
        std::cerr << "Error: Unable to open file for reading!\n";
    }
    };