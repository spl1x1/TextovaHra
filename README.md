# 🍪 Cookie Clicker Clone

Moderní implementace populární hry Cookie Clicker v C++ s interaktivním textovým uživatelským rozhraním.

## 📋 Přehled

Toto je klonování hry Cookie Clicker napsané v C++. Hra běží v terminálu s grafickým rozhraním postaveným na knihovně FTXUI, která umožňuje tvorbu pokročilých textových uživatelských rozhraní.

![Game Screenshot](./assets/screenshot.png)

## ✨ Funkcionalita

- *🖱️ Klikání na cookies* - Získávej cookies klikáním myší na hlavní cookie
- *🏢 Nákup budov* - Automatizuj produkci cookies nákupem různých budov (Babička, Farma, Továrna...)
- *⬆️ Upgrades* - Vylepšuj budovy a zvyšuj jejich efektivitu a výnos
-*🖼️ PNG grafika** - Podpora PNG obrázků pro vizuální prvky hry
-*📊 Statistiky** - Sleduj svůj pokrok a výnosy

## 🛠️ Požadavky

- C++17 nebo vyšší
- CMake 3.16+
- FTXUI knihovna
- STB Image (včleněna v projektu)

## 🚀 Kompilace

```bash
mkdir -p build 
cd build
cmake build -S .. -B .
make