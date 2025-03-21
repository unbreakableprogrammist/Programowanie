#include <iostream>
#include <iomanip>
#include <cstddef> // bytes
#include <string.h>

static int STATYCZNA = 10;

void zadanie1() {
    int* ptr = new int;
    *ptr = 5;
    std::cout<<"Adres pamieci: "<<ptr<<" Zawartosc: "<<(*ptr)<<std::endl;
    delete ptr;
    std::cout<<"Adres pamieci: "<<ptr<<" Zawartosc: "<<(*ptr)<<std::endl;

    double* ptrs = new double[10];
    for (int i = 0; i < 10; i++)
        ptrs[i] = 10-i + 0.31*i;

    std::cout<<"Adres pamieci: "<<ptrs<<std::endl;

    for (int i = 0; i < 10; i++)
        std::cout<<ptrs[i]<<", ";

    std::cout<<std::endl;

    //delete ptrs;

    std::cout<<"Adres pamieci: "<<ptrs<<std::endl;

    for (int i = 0; i < 10; i++)
        std::cout<<ptrs[i]<<", ";

    std::cout<<std::endl;

    delete[] ptrs;
}

int* zalozmy_x() {
    int* ptr = new int;
    int k = 5;
    ptr = &k;
    std::cout<<k<<std::endl;
    std::cout<<&k<<std::endl;
    return ptr;
}

void zadanie2(int a, int* b, int* ptr, int* automatic, int* sratic) {
    a = 43;
    *b = 44;
    *ptr = 45;
    *sratic = 100;
    std::cout<<"automatic:"<<automatic<<std::endl;
    std::cout<<"static:"<<&sratic<<std::endl;
};

// zadanie 3

enum class Tage { Montag, Dienstag, Mittwoch, Donnerstag, Freitag, Samstag, Sonntag };
enum class Colours { Red, Green, Blue };

void zadanie3(Tage day, Colours colour) {
    switch (day) {
        case Tage::Montag : std::cout<<"Poniedzialek"<<std::endl;
            break;
        case Tage::Freitag: std::cout<<"Weekend!"<<std::endl;
            break;
    }
    switch (colour) {
        case Colours::Green : std::cout<<"Grun"<<std::endl;
            break;
        case Colours::Red: std::cout<<"Rot"<<std::endl;
            break;
    }
};

void zadanie4() {
    //reinterpret_cast<T> potrafi zmienić typ wskazywany
    //wskaźnika/referencji na dowolny inny.

    //int x = 12345; // Jakiś obiekt
    //unsigned char* bytes = reinterpret_cast<unsigned char*>(&x); <--- TYLKO TU SIE R O Z N I !
    //for (std::size_t i = 0; i < sizeof(x); ++i) {
    //    std::cout << "Byte " << i << ": "
    //              << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(bytes[i]) << "\n";
    //}

    int x = 12345;  // Jakiś obiekt
    std::byte* bytes = reinterpret_cast<std::byte*>(&x);

    for (std::size_t i = 0; i < sizeof(x); ++i) {
        std::cout << "Byte " << i << ": "
                  << "0x" << std::hex << std::setw(2) << std::setfill('0')
                  << static_cast<int>(bytes[i]) << "\n";
    }
}

// zadanie 5
// Kopiowanie danych bez nakładania się
void copy_without_overlap() {
    char src[] = "Hello, World!";
    char dest[20];

    memcpy(dest, src, sizeof(src)); // Kopiowanie danych bez nakładania się

    printf("copy_without_overlap: %s\n", dest);
}

// Kopiowanie danych z nakładającymi się obszarami
void copy_with_overlap() {
    char buffer[] = "1234567890";

    // memcpy - niebezpieczne przy nakładaniu się danych
    memcpy(buffer + 2, buffer, 5);
    printf("memcpy result: %s\n", buffer);

    // Resetujemy buffer
    strcpy(buffer, "1234567890");

    // memmove - poprawne działanie przy nakładaniu się danych
    memmove(buffer + 2, buffer, 5);
    printf("memmove result: %s\n", buffer);
}

void zadanie6() {
    // 1. Konwersja między różnymi typami liczbowymi

    int intValue = 42;
    float floatValue = static_cast<float>(intValue); // int → float
    std::cout<<std::dec << "Konwersja int -> float: " << intValue << " -> " << floatValue << std::endl;

    double doubleValue = 3.14;
    int intFromDouble = static_cast<int>(doubleValue); // double → int
    std::cout << "Konwersja double -> int: " << doubleValue << " -> " << intFromDouble << std::endl;

    // 2. Konwersja między typem enum class a liczbami
    enum class Colors { Red = 1, Green = 2, Blue = 3 };
    Colors color = Colors::Green;
    int colorValue = static_cast<int>(color); // enum class → int
    std::cout << "Konwersja enum class (Colors::Green) -> int: " << colorValue << " " << std::endl;

    int number = 3;
    Colors colorFromNumber = static_cast<Colors>(number); // int → enum class
    std::cout << "Konwersja int -> enum class: " << number << " -> " << static_cast<int>(colorFromNumber) << " (Blue)" << std::endl;
}

int main() {
    std::cout<<"//////Zadanie 1///////"<<std::endl;
    zadanie1();
    std::cout<<"///////Zadanie 2///////"<<std::endl;
    // Tak sie nie da: (podpunkt 2.3)
    //const int n = 5;
    //int* ptr2n = new int;
    //ptr2n = &n;
    //

    int* ptr2 = new int;
    *ptr2 = 56;
    int n2 = 57;
    std::cout<<"a: "<<58<<"|b: "<<n2<<"|*ptr2: "<<*ptr2<<"|Statyczna: "<<STATYCZNA<<std::endl;
    zadanie2(58, &n2, ptr2, zalozmy_x(), &STATYCZNA);
    std::cout<<"a: "<<58<<"|b: "<<n2<<"|*ptr2: "<<*ptr2<<"|Statyczna: "<<STATYCZNA<<std::endl;

    std::cout<<"///////Zadanie 3///////"<<std::endl;
    Colours c1 = Colours::Red;
    Tage d1 = Tage::Montag;
    zadanie3(d1, c1);

    std::cout<<"///////Zadanie 4///////"<<std::endl;
    // const niemodyfikowalne, static caly czas istnieje
    zadanie4();

    std::cout<<"///////Zadanie 5///////"<<std::endl;
    /*Obie funkcje służą do kopiowania bloków pamięci, ale mają różne zastosowania:

    memcpy(dest, src, n)
    Kopiuje n bajtów z src do dest.
    Jest szybka, ale nie radzi sobie z nakładającymi się obszarami pamięci.
    Używana, gdy dane są w oddzielnych miejscach w pamięci.
    Przykład: kopiowanie danych między tablicami.
    memmove(dest, src, n)
    Także kopiuje n bajtów z src do dest.
    Działa poprawnie nawet gdy obszary pamięci się nakładają, bo kopiuje w sposób bezpieczny.
    Przykład: przesuwanie danych w tej samej tablicy (np. przesuwanie tekstu w buforze).
    Podsumowanie:

    Użyj memcpy, jeśli masz pewność, że pamięć się nie nakłada.
    Użyj memmove, jeśli istnieje ryzyko nakładania się pamięci.*/
    copy_without_overlap();
    copy_with_overlap();

    std::cout<<"///////Zadanie 6///////"<<std::endl;
    zadanie6();
    std::cout<<"///////Zadanie 7///////"<<std::endl;
    std::cout<<"///////Zadanie 8///////"<<std::endl;


}