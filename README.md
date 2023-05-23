# Tema LAN Party
## *Proiectarea algoritmilor, anul I, semestrul II*
---
### Ideea principala

In ansamblu, programul implementeaza o solutie pentru automatizarea evenimentului LAN Party. Prin intermediul structurilor de date am retinut date despre fiecare jucator, despre fiecare echipa, dar si despre stivele, cozile si arborii folositi. Pe scurt, scopul programului este de a retine cat mai multe echipe cu punctaj mare, de a forma meciuri cu acestea, care bineinteles se vor imparti in castigatori si invinsi. Castigatorii vor continua sa joace pana la aflarea echipei castigatoare. 

### Algoritmul aplicat

Prima cerinta a temei a fost de a retine echipele intr-o lista. Pentru rezolvarea acesteia am citit datele echipelor din fisierul d.in si am folosit functia *void createLIST(TEAM **head, FILE *input)* pentru crearea listei si salvarea lor. 
A doua cerinta am rezolvat-o calculand, pentru inceput, n maxim in cadrul buclei *while (n * 2 <= nr_teams)*, dar si puntajele fiecarei echipe (media aritmetica dintre puntajele jucatorilor unei echipe). Am parcurs lista initiala si am calculat minimul de fiecare data, eliminand echipa cu acest punctaj, pana cand au ramas n echipe.
Echipele ramase le-am folosit in rezolvarea cerintei 3. Am creat o coada cu acestea si am comparat echipele doua cate doua, creand meciuri intre ele. Echipa cu puntajul mai mic am adaugat-o intr-o stiva pentru invinsi, iar pentru cea cu puntajul mai mare, l-am incrementat pe acesta si am adaugat-o intr-o stiva pentru castigatori. Atunci cand am ajuns la antepenultima runda, adica au mai ramas 8 echipe in stiva de castigatori, le-am retinut intr-un arbore binar de cautare, ajutandu-ma de proprietatile acestuia (echipele cu punctaj mai mic au fost puse in stanga, iar cele cu punctaj mai mare in dreapta).
Pentru a rezolva cerinta 4, am afisat arborele binar de cautare, creat in cadrul cerintei 3, in ordine descrescatoare, parcurgandu-l in inordine (dreapta, radacina, stanga), cu ajutorul functiei: *displayDRS(nodeTree, r);*, adica am afisat echipele de pe primele 8 locuri in ordine descrescatoare. M-am asigurat ca atunci cand afisez atat meciurile, cat si stiva cu echipele castigatoare si punctajele lor, sa fie aliniate corespunzator. 
Rezolvarea cerintei 5 este incompleta, din pacate. Am salvat datele echipelor intr-un arbore de tip AVL, insa nu am mai apucat sa-l echilibrez, prin rotire la dreapta, acesta fiind ordonat.

---
### *Dificultati intalnite*

Am avut cateva probleme in legatura cu Checker-ul pentru ca in fisierele din date, si anume d.in-urile, existau cateva spatii la finalul anumitor cuvinte care la salvarea in lista, ramaneau automat. Insa, in fisierele din rezultate nu mai erau aceste spatii. 
### *Lucruri interesante*

Ma bucur ca am reusit sa duc aceasta tema aproape pana la final, fiind prima mea lucrare de genul acesta, cu o complexitate destul de mare. Am invatat foarte multe lucruri legate de checkere, de VisualStudio Code, de README, dar si de programare in special. Consider ca aceasta tema m-a ajutat sa mi fixez mult mai bine cunostintele legate de structuri de date, stive, cozi, liste, arbori, care sunt foarte utile pe viitor. 

---
*Stanciu Minola-Cristina, Grupa 313AA*
