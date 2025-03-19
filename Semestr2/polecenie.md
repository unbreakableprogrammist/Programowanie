# Laboratorium 1
## Translacja

W tym zadaniu stworzysz prosty projekt w C++ skĹadajÄcy siÄ z:
- DwĂłch programĂłw
- Biblioteki statycznej z wieloma plikami.
- Biblioteki wspĂłĹdzielonej.

Sklonuj repozytorium zgodnie z instrukcjÄ z laboratorium wprowadzajÄcego.
Najpierw wykonaj pierwszy etap. WyĹlij go do repozytorium oraz zgĹoĹ to prowadzÄcemu, ktĂłry go sprawdzi. Dopiero po tym przejdĹş do kolejnego etapu.

Pobierz (plik startowy)[/cpp-1/test.cpp]

### 1. Biblioteka dynamiczna [4pkt]
UtwĂłrz dwa pliki: `hello.cpp` i `hello.hpp`.
Pierwszy powinien zawieraÄ:
- DefinicjÄ zmiennej globalnej statycznej `HELLO_COUNT` inicjowanej zerem.
- DefinicjÄ funkcji `void print(std::string name)` w przestrzeni nazw `hello`.
  Funkcja ta najpierw zwiÄksza `HELLO_COUNT` o 1, a potem wypisuje na stadardowe wyjĹcie wartoĹÄ licznika oraz powitanie dla `name`
  ```
  <HELLO_COUNT>. Hello <name>.<nowa linia>
  ```
  Czyli np. dla trzeciego wywoĹania, z argumentem `"Markusz"`, powinna wypisaÄ
  ```
  3. Hello Markusz.<nowa linia>
  ```
W pliku `hello.hpp` udostÄpnij tÄ funkcjÄ.

UtwĂłrz plik `main_program.cpp` z funkcjÄ `main()` i wywoĹaj w niej napisanÄ funkcjÄ `print` trzy razy z dowolnymi argumentami (np. `"Darius"`, `"Xerxes"`, `"Ataxerxes"`).

UtwĂłrz plik `Makefile` z celami:
- ZmiennÄ `COMPILER` z wartoĹciÄ `g++`. Nie uĹźywaj polecenia `g++` bezpoĹrednio w dalszej czÄĹci `Makefile`.
- `all` -- teraz tylko bÄdzie tam tylko `main_program`.
- `clean` -- usuwa pliki wynikowe kompilacji
- Cele potrzebne do kompilacji utworzonych plikĂłw.
  `hello.cpp` naleĹźy budowaÄ jako bibliotekÄ **wspĂłĹdzielonÄ (shared)** o nazwie `libhello.so`, oraz linkowaÄ jÄ do `main_program`.
  KompilacjÄ pliku `.cpp` dziel na dwa cele: kompilujÄcy (t.j. tworzÄcy plik `.o`) i linkujÄcy.

Dodaj w komentarzu do `main_program.cpp` polecenie bash, ktĂłrym uruchomiÄ moĹźna ten program z katalogu projektu. UwzglÄdnij ĹcieĹźkÄ szukania bibliotek wspĂłĹdzielonych.

### 2. Biblioteka wspĂłĹdzielona [6pkt]
UtwĂłrz cztery pliki: `vectors.cpp`, `vectors.hpp`, `strings.cpp` i `strings.hpp`.

W `vectors.cpp` zdefiniuj w przestrzeni nazw `vectors`:
- FunkcjÄ `std::vector<int> reverse(std::vector<int>* old)`, ktĂłra tworzy nowy `std::vector<int>` o zawartoĹci `old`, ale w odwrotnej kolejnoĹci. Upewnij siÄ, Ĺźe funkcja dziaĹa poprawnie dla pustych wektorĂłw (`->size()` zwraca zmiennÄ `unsigned`).
- FunkcjÄ `int max(std::vector<int>* vec)`, ktĂłra zwraca maksymalny element wektora.
  W `vectors.hpp` udostÄpnij te funkcje.

W `strings.cpp` zdefiniuj w przestrzeni nazw `strings`:
- ZmiennÄ globalnÄ `COMBINE_COUNT` typu `int` inicjowanÄ zerem.
- FunkcjÄ `std::string combine_strings(std::string s1, std::string s2)`, ktĂłra zwiÄksza `COMBINE_COUNT` o 1 oraz konkatenuje podane ciÄgi `s1` i `s2`. Przy argumentach `"Hello"` i `"world"` zwraca ciÄg postaci `Hello world` (konkatenacja i dodanie spacji pomiÄdzy).
  W `strings.hpp` udostÄpnij tÄ zmiennÄ i funkcjÄ.

Zaktualizuj `Makefile`:
- Zbuduj bibliotekÄ statycznÄ `liboperations.a` z plikĂłw `vectors.cpp` i `strings.cpp`. Podziel zadanie w pliku Makefile odpowiednio na cele (kompilacja kaĹźdego pliku `.cpp` i utworzenie biblioteki)
- Zbuduj program `test` i zlinkuj do niego `liboperations.a`.
- Zaktualizuj `all` dodajÄc do niego `test`.
- Zaktualizuj `clean`, by usuwaĹ nowe pliki wynikowe kompilacji.

Poprawny wynik uruchomienia programu `test` to:
```
vector: {1, 2, 3, 4, 5, 4}
reversed: reversed empty: {}
max: 5
COMBINE_COUNT: 0
Combining abc and efg: abc efg
COMBINE_COUNT: 1
```

Bon voyage.
