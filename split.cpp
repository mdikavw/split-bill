#include <iostream>
#include <string>

struct Pesanan {
    std::string nama;
    int harga;
    struct Pesanan *next;
};

struct Pelanggan {
    std::string nama;
    struct Pesanan *nextPesanan;
    struct Pelanggan *nextPelanggan;
};

class Makanan {
    public:
        std::string nama;
        int harga;
        Makanan(std::string namaMakanan, int hargaMakanan){
            nama = namaMakanan;
            harga = hargaMakanan;
        };
};

class Transaksi {
    public:
        int id;
        struct Pelanggan *head;
        int total;
};

int main(){
    Makanan menu[] = {
        Makanan("Rendang", 15),
        Makanan("Soto", 17),
        Makanan("Bakso", 12),
        Makanan("Ayam Goreng", 20)
    };
    
    for(int i = 0; i < 4; i++){
        std::cout << menu[i].nama << " " << menu[i].harga << "\n";
    }

    return 0;
}