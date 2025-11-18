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



## Cíl projektu

Vaším úkolem je rozšířit tuto šablonu a vytvořit plnohodnotnou textovou hru. Můžete se zaměřit na:
* **Příběh:** Vytvořte zajímavý svět a zápletku.
* **Hádanky:** Navrhněte puzzly, které hráč musí vyřešit.
* **Předměty:** Přidejte předměty, které může hráč sbírat, kombinovat a používat.
* **Postavy (NPC):** Přidejte postavy, se kterými může hráč interagovat.
* **Rozhraní:** Vylepšete způsob, jakým hra komunikuje s hráčem.

## Jak začít

Struktura projektu je rozdělena do hlavičkových souborů (`.h`) a implementačních souborů (`.cpp`).

* `main.cpp`: Obsahuje hlavní funkci `main()`, která spouští hru.
* `Game`: Hlavní třída, která řídí herní smyčku a stav hry.
* `Player`: Třída reprezentující hráče (obsahuje inventář, aktuální lokaci).
* `Location`: Třída reprezentující jednu místnost nebo lokaci ve hře.
* `Item`: Třída reprezentující předmět, který lze najít nebo sebrat.

### Struktura Repozitáře (Šablona)

```
/textova-hra-sablona/
|
|-- .devcontainer/         # Konfigurace potřebné pro spuštění v devcontaineru
|
|-- .vscode/
|   |-- tasks.json         # Konfigurace pro snadnou kompilaci ve VS Code
|
|-- data/
|   |-- world.txt          # Soubor s definicí místností (pro pokročilejší)
|   |-- items.txt          # Soubor s definicí předmětů (pro pokročilejší)
|
|-- src/
|   |-- Item.h             # Hlavičkový soubor pro předměty (může být zpočátku prázdný)
|   |-- Item.cpp           # Implementace třídy Item
|   |-- Location.h         # Hlavičkový soubor pro místnosti
|   |-- Location.cpp       # Implementace třídy Location
|   |-- Player.h           # Hlavičkový soubor pro hráče
|   |-- Player.cpp         # Implementace třídy Player
|   |-- Game.h             # Hlavní třída hry (herní smyčka, stav)
|   |-- Game.cpp           # Implementace herní logiky
|   |-- main.cpp           # Vstupní bod programu
|
|-- .gitignore             # Ignoruje zkompilované soubory
|-- README.md              # Popis projektu pro studenty
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

## Pravidla soutěže

  * Týmy jsou stanoveny y výuky.
  * Každý člen týmu musí mít v Gitu viditelné commity.
  * Hra musí být hratelná a mít jasný cíl/konec.
  * Hodnotit se budete navzájem každý student bude mít dva hlasy, které může dát libovolnému projektu. Není možné použít oba hlasy na stejný projekt.
