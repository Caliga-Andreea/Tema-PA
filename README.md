Tema 1
Task1 
Pentru a realiza tema am utilizat o strucutra de tip lista de liste. Lista principala era cea de echipe, iar fiecare echipa era constituita din lista de jucatori. Am alocat dinamic spatiu atat pentru nodurile
listei de echipe, cat si pentru nodurile listelor de jucatori. Pe parcurs ce citeam date din fisierul cu date de intrare, avand grija sa sar peste spatii sau sfarsitul de linie, introduceam intaii jucatorii in 
lista dedicata acestora, iar cand echipa era completa, conform nr de jucatori dat in fisierul de intrare adaugam nodul echipa la inceputul listei de echipe. Am eliberat de asemenea spatiul utilizat de 
variabilele auxiliare.Dupa care am parcurs lista de echipe si am afisat numele acestora in fisierul de iesire.
Task 2
Am determinat numarul de echipe(numar putere a lui 2) care trebuie sa ramana in campionat, iar mai apoi am eliminat pe rand echipele care aveau punctaj minim(dupa fiecare echipa eliminata, identificam un nou 
punctaj minim). Existau 2 cazuri: 1. echipa cu punctaj minim era chiar prima din lista si atunci trebuia sa schimbam head-ul listei; 2. Echipa ce trebuia sa fie eliminata era oricare alta echipa, iar pentru a o
elimina eram nevoita sa pastrez si nodul anterior. Acest proces a fost repetat pana ce am obtinut numarul de echipe identificat la inceput.La final am afisat din nou, parcurgand intreaga lista de echipe, numele
echipelor.
Task 3
Pentru a realiza meciurile, am tinut in primul rand cont de numarul rundei si de numarul de echipe ramase. m organizat meciuri cat timp am avut mai mult de o echipa. In cazul in care eraa prima runda, adaugam 
in coada de meciuri echipele din lista de echipe, iar in caz contrar adaugam in coada echipele din stiva de castigatori. Dupa ce am afisat coada cu echipele participante(doar in cazul in care era prima runda),
ma ocupam de afisarea rundelor. Am afisat cate doua echipe(respectand nr de spatii necesar pentru a trece de verificarea checkerului), iar pe parcurs comparam punctajele celor doua echipe si le adaugam in stiva
de castigatori, respectiv de pierzatori. Dupa ce intreaga coada de echipe era parcurs si runda lua sfarsit, stergeam stiva de invinsi, pentru a nu face risipa de memorie,iar apoi afisam castigatorii. Dupa care 
stergeam componentele cozii, incrementam numarul rundei si injumatateam numarul echipelor. Acest procedeu se realiza cat timp numarul de echipe era mai mare decat 1. In cazul in care nr de echipe ajungea la 8 
adaugam elementele din stiva de castigatori, intr-o lista care sa contina ultimii 8 jucatori ramasi in competitie(lista utila pentru task-urile 4 si 5).
Task4
In cadrul task-ului 4 am realizat un arbore BST utilizand lista cu ultimele 8 echipe de la task-ul 3. Am alocat memorie pt nodurile arborelui(NodeGraph), iar apoi am inserat noduri utilizand functia insterg, 
respectand conditiile (in cazul in care punctajul nodului dat era mai mare decat cel al nodului root sau in caz de egalitate daca alfabetic era primul atunci nodul era inserat in dreapta, iar in caz contrat era
inserat pe ramura stanga). Pentru a afisa echipele si punctajele in ordine descrescatoare, am realizat o functie de parcurgere in inordine(doar ca ordinea era dreapta, root, stanga).
Task5
Utilizand arborele BST obtinut la task-ul 4 am obtinut arborele AVL. Am alocat memorie pentru nodurile de tip AVL, avand in plus fata de nodurile BST componenta de inaltime. Am utilizat o functie de inserare in
ordine descrescatoare a nodurilor in AVL(la fel ca in cazul BST-ului ordinea era dreapta, root,stanga). In cadrul functiei de inserare am pastrat conditiile aplicate in cadrul BST-ului, diferenta au facut-o 
conditiile de rotatie. In cazul in care diferenta dintre inaltimea ramurei stangi si a ramurei drepte, notata cu k era mai mare decat 1 si daca punctajul echipei curente era mai mare decat punctajul echipei de
pe ramura stanga sau daca cele doua echipe aveau punctaj egal dar a doua echipa avea intaietate alfabetic, realizam o rotatie la dreapta. In cazul in care k<-1 iar echipa avea punctaj mai mare decat echipa de pe
ramura din dreapta sau punctaj egal dar prima echipa avea intaietate alfabetic, se realiza rotatia la stanga. In cazul in care k>1 si echipa are punctaj mai mic decat cea de pe ramura stanga sau punctaj egal
si prima are intaietate ca nume, se realizeaza rotatia stanga-dreapta. Iar in ultimul caz daca k<-1 iar punctajul echipei este mai mic decat cel al echipei de pe ramura stanga sau egale si a doua echipa are 
intaietate ca nume, se realizeaza rotatie dreapta-stanga. La final se afiseaza numele echipelor de pe nivelul 2 al arborelui(se verifica daca nivelul curent este egal cu 2, iar in caz contrar se creste nivelul
curent si se apeleaza functia recursiv atat pentru ramura dreapta,cat si pentru cea stanga.In momentul in care nivelul curent este 2 se afiseaza numele echipei.
Pe
