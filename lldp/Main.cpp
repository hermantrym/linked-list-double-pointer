#include "Header.h"

int main() {
    List L;
    address P;
    infotype X;
    int i, N;

    std::cout << "============================================================================" << std::endl;
    std::cout << "     =================== LINKED LIST DOUBLE POINTER ===================" << std::endl;
    std::cout << "============================================================================\n" << std::endl;

    CreateList(&L);

    std::cout << "\n======================== Insert Elemen Di Awal List ========================" << std::endl;
    std::cout << "Banyaknya elemen yang ditambahkan : ";
    std::cin >> N;

    for (i = 1; i <= N; i++) {
        std::cout <<"  - Input elemen List : "; 
        std::cin >> X;

        InsVFirst(&L, X);
    }

    std::cout << "\n* List L : ";
    PrintInfo(L);

    std::cout << "\n\n======================== Delete Elemen Di Awal List ========================" << std::endl;
    std::cout << "Banyaknya elemen yang dihapus : ";
    std::cin >> X;

    std::cout << "Elemen yang dihapus : ";
    for (i = 1; i <= N; i++) {
        DelVFirst(&L, &X);
        std::cout << X << " ";
    }

    std::cout << "\n* List L : ";
    PrintInfo(L);

    std::cout << "\n\n======================= Insert Elemen Di Akhir List ========================" << std::endl;
    std::cout << "Banyaknya elemen yang ditambahkan : ";
    std::cin >> N;

    for (i = 1; i <= N; i++) {
        std::cout << "  - Input elemen List : ";
        std::cin >> X;

        InsVLast(&L, X);
    }

    std::cout << "\n* List L : ";
    PrintInfo(L);

    std::cout << "\n\n======================= Delete Elemen Di Akhir List ========================" << std::endl;
    std::cout << "Banyaknya elemen yang dihapus : ";
    std::cin >> N;

    std::cout << "Elemen yang dihapus : ";
    for (i = 1; i <= N; i++) {
        DelVLast(&L, &X);
        std::cout << X;
    }

    std::cout << "\n* List L : ";
    PrintInfo(L);

    std::cout << "\n\n=========================== Search Elemen List =============================" << std::endl;
    std::cout << "Masukkan elemen yang ingin dicari : ";
    std::cin >> X;

    std::cout << "Hasil pencarian : ";
    P = Search(L, X);
    if (P != Nil)
        std::cout << "Elemen ditemukan pada alamat 0x" << P;
    else
        std::cout << "Elemen tidak ditemukan";

    std::cout << "\n\n============================================================================" << std::endl;

    return 0;
}