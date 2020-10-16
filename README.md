# 1-oji užduotis

# Hash generatoriaus kūrimas

# Hash funkcijos veikimas

Vyksta ciklas kuris nuskaito string'o simbolį ir paverčia į skaičių(value) pagal ASCII, tuomet tas skaičius padauginamas iš savęs, naujas skaičius pridedamas į sumą(sum). Toliau value padalinamas iš sum ir padauginama iš sum, gautas skaičius pridedamas prie sum. Sum pakeliamas kvadratu ir pridedamas prie sum, paskui sum skaičiaus bitai yra paslenkami į kairę trimis pozicijomis ir gautas skaičius  vėl pridedamas prie sum. Šis ciklas pakartojamas kiekvienam string'o simboliui. Po šio ciklo gauto sum skaičiaus bitai yra paslenkami dviem pozocijom į dešinę, sukuriamas naujas stringstream objektas ss į kurį yra nukopijuota sum reikšmė ir paversta į hex tipą. Gauta hex reikšmė nukopijuojama į result, tuomet, jeigu result ilgis nėra 64 simboliai, tai vėl daromi skaičiavimai, kad result ilgis būtų bent 64. Jei result ilgis yra daugiau nei 64 simboliai tai reikšmė yra sumažinama kad būtų 64 simboliai, galutiniame result yra mūsų string'o hash'as 

# Testavimų rezultatai

- Konstitucijos kiekvienos eilutės hash'avimo laikas: 0,439703 sec
- Visos konstitucijos hash'as: 2c534fbe716dbdd871a490c2bcbcb2d63bb558e8cca59f6e31bf5d46baeed9dc

- 2 skirtingi 2000 simbolių failai:
```
2000symbols1.txt- 2894592574abeac9f7ad6ef66d2a9efa2894592548b661c9cda8efc674abeac9
2000symbols2.txt- 422b8708a6af298855d3bcca8253cd66b5d39694df57a08e4bbc7a7c33cd808a
```
- 2 dideli failai su vieno simbolio skirtumu:
```
big1diffsymbol1.txt- 1ec103cb35d715d56d291cd66336867d1ec103cb2d1e74b369095c0e7766ccf6
big1diffsymbol2.txt- 18e957177b725cd91f72a9a999bdae5818e95717b992a97ae916685e7b725cd9
```
- 2 failai su vienu simboliu
```
onesymbol1.txt - 21224588ab6efe5ac144a9d6f6ec5df821224588d5dbd7cccaaf7f3827cf8698
onesymbol2.txt - 12dbf15153a7de72ddb48afe7bafc3e912dbf151351ea7ad53a7de727336caba
```

# Skirtingų string'ų ir panašių string'ų testų rezultatai

- 100000 skirtingų string'ų po 6 simbolius:
```
Collisions: 0
```
- 100000 panašių string'ų po 10 simbolių:
```
Collisions: 0
Mažiausias skirtingumas: 16,4063
Didžiausias skirtingumas: 42,5781
Vidutinis skirtingumas: 32,5772
```

