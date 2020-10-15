# 1-oji užduotis

# Hash generatoriaus kūrimas

# Hash funkcijos veikimas

Vyksta ciklas kuris nuskaito string'o simbolį ir paverčia į skaičių(value) pagal ASCII, tuomet tas skaičius padauginamas iš savęs, naujas skaičius pridedamas į sumą(sum). Toliau invertuotas value padalinamas iš invertuoto sum, gautas skaičius pridedamas prie sum, paskui sum skaičiaus bitai yra paslenkami į kairę viena pozicija ir gautas skaičius  vėl pridedamas prie sum. Šis ciklas pakartojamas kiekvienam string'o simboliui. Po šio ciklo gauto sum skaičiaus bitai yra paslenkami viena pozocija į dešinę, sukuriamas naujas stringstream objektas ss į kurį yra nukopijuota sum reikšmė ir paversta į hex tipą. Gauta hex reikšmė nukopijuojama į result, tuomet, jeigu result ilgis nėra 64 simboliai, tai vėl daromi skaičiavimai, kad result ilgis būtų bent 64. Jei result ilgis yra daugiau nei 64 simboliai tai reikšmė yra sumažinama kad būtų 64 simboliai, galutiniame result yra mūsų string'o hash'as 

# Testavimų rezultatai

- Konstitucijos kiekvienos eilutės hash'avimo laikas: 0,439703 sec
- Visos konstitucijos hash'as: 535b8a51882aa833d90341ca7751e418c3c7342de194db19cc901593d7cd9319

- 2 skirtingi 2000 simbolių failai:
```
2000symbols1.txt- 71d2bceec1ab581ccf5682e3bc61f633ada8c126aef4718db24e3585c0681486
2000symbols2.txt- 7166c225b605202bdb985da89982d83fb6610becd43c7deac0500c03e059e11d
```
- 2 dideli failai su vieno simbolio skirtumu:
```
big1diffsymbol1.txt- 7ffa5160efad07b0c7b89b5cc7dd6c0ca03824f8efe963e09ff8e5b8c8033cac
big1diffsymbol2.txt- 6fb0e92ebe4c8e61bd5003bcc7c620d0bbdbd81e9a32784cc728c150eb56add5
```
- 2 failai su vienu simboliu
```
onesymbol1.txt - 9d0813f484223ce761c069ff81101b1cf19fe5ecec9fe2d1c49fdf1b9c9fdc00
onesymbol2.txt - 450d84162741005e5309ffcf21d45d049ff48fa69ff3365b9ff1d6d5741009fe
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

