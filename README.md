# Textová Hra

Něco na styl Wolfenstein 3D, takže nějaký výběr cesty v koridorech, kde budou různé předměty či enemy
Cílem bude dojít na správný konec bludiště a zabít hlavního enemy (nějaký středový zlobr nebo něco takového)
Zároveň medieval styl, takže meče atd., postava bude mít výstroj a výbroj a HP pool
Možná nějaké prvky ze Shakes&Fidget, jako je aréna a grind skillů a zbraní
Bude obsahovat nějaký grafický design v terminálu



Script pro spuštění run.sh
> ./run.sh

mimo složku se skriptem
>/workspaces/TextovaHra/run.sh

Je možné, že budete potřebovat změnit permise souboru
>chmod 770 run.sh

nebo

>chmod 770 /workspaces/TextovaHra/run.sh


Prosím neupravovat CMakeLists.txt.


### Struktura Repozitáře (Šablona)

```
/textova-hra-sablona/
|
|-- .devcontainer/         # Konfigurace potřebné pro spuštění v devcontaineru
|
|-- .vscode/
|   |-- tasks.json         # Konfigurace pro snadnou kompilaci ve VS Code
|
|-- assets/                # Obrazky a assety
|
|-- cmake/                 # CPM skript - správce závislostí pro CMake, který automaticky stahuje a integruje knihovny do projektu.
|
|-- data/
|   |-- world.txt          # Soubor s definicí místností (pro pokročilejší)
|   |-- items.txt          # Soubor s definicí předmětů (pro pokročilejší)
|
|-- src/
|   |-- Achievements/
|       |-- Achievement.cpp
|       |-- Achievement.hpp     
|   |-- Items/         
|       |-- Cursor.hpp
|       |-- Factory.hpp         
|       |-- Grandma.hpp         
|       |-- Item.cpp         
|       |-- Item.hpp         
|       |-- ReinforcedFinger.hpp         
|   |-- Tests/     
|       |-- ItemTests.h           
|   |-- Game.cpp         
|   |-- Game.hpp             
|   |-- Utils.cpp 
|   |-- Utils.hpp
|   |-- Window.cpp        
|   |-- Window.hpp         
|   |-- main.cpp         
|   |-- stb_image.h   
|
|-- .gitignore             # Ignoruje zkompilované soubory
|-- CMakeLists.txt         # CMakeList
|-- README.md              # Popis projektu pro studenty
|-- run.sh
|-- test.h
```

### Kompilace a spuštění

**Ve VS Code (s Dev Containerem):**
1.  Otevřete terminál (Terminal > New Terminal).
2.  Spusťte kompilaci: `make` (nebo použijte task "C/C++: g++ sestavit aktivní složku" z `tasks.json`).
3.  Spusťte hru: `./game`

**Manuálně v terminálu:**
```bash
g++ src/*.cpp -o game -std=c++17
./game
```
