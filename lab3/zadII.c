/*
 1. int a[8]={0, -1, 2, -3, 4, 5, 6, 7, 8},x=5,y=10,z=5;
    Ta instrukcja deklaruje i inicjalizuje tablicę a ośmiu liczb całkowitych 
    oraz trzy zmienne x, y i z o wartościach 5, 10 i 5.
 2. int *px,*py,*pz,*pa; 
    Ta instrukcja deklaruje cztery wskaźniki px, py, pz i pa typu int, 
    czyli mogące wskazywać na zmienne całkowite.
 3. double *pd; Ta instrukcja deklaruje wskaźnik pd typu double, 
    czyli mogący wskazywać na zmienną zmiennoprzecinkową.
 4. px=&x; 
    Ta instrukcja przypisuje wskaźnikowi px adres zmiennej x. 
    Operator & zwraca adres zmiennej w pamięci
 5. py=&y; 
    Ta instrukcja przypisuje wskaźnikowi py adres zmiennej y.
 6. y=*px;
    Ta instrukcja przypisuje zmiennej y wartość zmiennej wskazywanej przez px. 
    Operator * zwraca wartość zmiennej pod adresem wskaźnika. 
    W tym przypadku y otrzyma wartość 5.
 7. printf(“\n y=%d”,*px); 
    Ta instrukcja wyświetla wartość zmiennej wskazywanej przez px (czyli x) w formacie dziesiętnym.
    W tym przypadku wyświetli się y=5.
 8. x=*py;
    Ta instrukcja przypisuje zmiennej x wartość zmiennej wskazywanej przez py. 
    W tym przypadku x otrzyma wartość 10.
 9. pz=px;
    Ta instrukcja przypisuje wskaźnikowi pz adres zmiennej wskazywanej przez px. 
    W tym przypadku pz otrzyma adres zmiennej x.
 10. printf("\n pz=%p", pz);
    Ta instrukcja wyświetla adres zmiennej wskazywanej przez pz w formacie szesnastkowym.
    W tym przypadku wyświetli się pz=000000000061FE14.
 11. *px=20;
    Ta instrukcja przypisuje zmiennej wskazywanej przez px wartość 20. 
    W tym przypadku zmiennej x przypisana zostanie wartość 20.
 12. *px=*py+5;
    Ta instrukcja przypisuje zmiennej wskazywanej przez px wartość zmiennej wskazywanej przez py 
    zwiększoną o 5. W tym przypadku zmiennej x przypisana zostanie wartość 15.
 13. *px=*py;
    Ta instrukcja przypisuje zmiennej wskazywanej przez px wartość zmiennej wskazywanej przez py. 
    W tym przypadku zmiennej x przypisana zostanie wartość 10.  
 14. *px=*py;
    Ta instrukcja przypisuje zmiennej wskazywanej przez px wartość zmiennej wskazywanej przez py. 
    W tym przypadku zmiennej x przypisana zostanie wartość 10.
 15. *(pa+1)=5; 
    Ta instrukcja przypisuje wartość 5 do drugiego elementu tablicy wskazywanej przez pa. 
    W tym przypadku drugi element tablicy a otrzyma wartość 5.
 16. pa[2]=10;
    Ta instrukcja przypisuje wartość 10 do trzeciego elementu tablicy wskazywanej przez pa. 
    W tym przypadku trzeci element tablicy a otrzyma wartość 10.
 17. pa++;
    Ta instrukcja przesuwa wskaźnik pa o jeden element tablicy wskazywanej przez pa. 
    W tym przypadku wskaźnik pa wskazuje teraz na drugi element tablicy a.
 18. pa=pa-1;
    Ta instrukcja przesuwa wskaźnik pa o jeden element tablicy wskazywanej przez pa w kierunku początku tablicy. 
    W tym przypadku wskaźnik pa wskazuje teraz na pierwszy element tablicy a.
 19. *pa++=20;
    Ta instrukcja przypisuje wartość 20 do pierwszego elementu tablicy wskazywanej przez pa, 
    a następnie przesuwa wskaźnik pa o jeden element tablicy wskazywanej przez pa. 
    W tym przypadku pierwszy element tablicy a otrzyma wartość 20, a wskaźnik pa wskazuje teraz na drugi element tablicy a.
 20. *++pa=25; 
    Ta instrukcja przesuwa wskaźnik pa o jeden element tablicy wskazywanej przez pa, 
    a następnie przypisuje wartość 25 do drugiego elementu tablicy wskazywanej przez pa. 
    W tym przypadku drugi element tablicy a otrzyma wartość 25, a wskaźnik pa wskazuje teraz na trzeci element tablicy a.
   



*/