# 1-oji užduotis

# Hash generatoriaus kūrimas

# Hash funkcijos veikimas

Vyksta ciklas kuris nuskaito string'o simbolį ir paverčia į skaičių(value) pagal ASCII, tuomet tas skaičius padauginamas iš savęs, naujas skaičius pridedamas į sumą(sum). Toliau value padalinamas iš sum ir padauginama iš sum, gautas skaičius pridedamas prie sum. Sum pakeliamas kvadratu ir pridedamas prie sum, paskui sum skaičiaus bitai yra paslenkami į kairę trimis pozicijomis ir gautas skaičius  vėl pridedamas prie sum. Šis ciklas pakartojamas kiekvienam string'o simboliui. Po šio ciklo gauto sum skaičiaus bitai yra paslenkami dviem pozocijom į dešinę, sukuriamas naujas stringstream objektas ss į kurį yra nukopijuota sum reikšmė ir paversta į hex tipą. Gauta hex reikšmė nukopijuojama į result, tuomet, jeigu result ilgis nėra 64 simboliai, tai vėl daromi skaičiavimai, kad result ilgis būtų bent 64. Jei result ilgis yra daugiau nei 64 simboliai tai reikšmė yra sumažinama kad būtų 64 simboliai, galutiniame result yra mūsų string'o hash'as 

# Testavimų rezultatai

- Konstitucijos kiekvienos eilutės hash'avimo laikas: 0,439703 sec
- Visos konstitucijos hash'as: 535b8a51882aa833d90341ca7751e418c3c7342de194db19cc901593d7cd9319

- 2 skirtingi 2000 simbolių failai:
```
2000symbols1.txt- 2975c4996721a375144a30196aa46f00233d7bf1bd2d3955144a3015144a3016
2000symbols2.txt- 34f476d2cbf82593f2a56e623cff43030e29ba17fd9d54f636d780e4bb6bc072
```
- 2 dideli failai su vieno simbolio skirtumu:
```
big1diffsymbol1.txt- 3a455ea320b1941629884a5e235ad9201235ad9251cef3aef2d7a9aa656c4522
big1diffsymbol2.txt- 3a455ea320b1941617529ccc91ad6c901235ad9251cef3aef2d7a9aa656c4522
```
- 2 failai su vienu simboliu
```
onesymbol1.txt - 24a9c728fcdcc7d1d102b78d0a3ac1b0ae44816536260efffcdcc7d119b1d3cf
onesymbol2.txt - 3f0386d52c4834d2675b83398ec614cb08ebdb77e675b8339312e356153aa691
```

# Skirtingų string'ų ir panašių string'ų testų rezultatai

- 100000 skirtingų string'ų po 6 simbolius:
```
Collisions: 0
```
- 100000 panašių string'ų po 10 simbolių:
```
Collisions: 0
Mažiausias skirtingumas: 15,0391
Didžiausias skirtingumas: 42,5781
Vidutinis skirtingumas: 32,3203
```

