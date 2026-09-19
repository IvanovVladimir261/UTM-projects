# tabelul cu literele mari (alfabetul romanesc extins, 31 litere)
alphabet_upper = "AĂÂBCDEFGHIÎJKLMNOPQRSȘTȚUVWXYZ"
# tabelul cu literele mici
alphabet_lower = "aăâbcdefghiîjklmnopqrsștțuvwxyz"

# afisam optiunile si citirea de la tastatura
print("1 - Criptarea")
print("2 - Decriptarea")
alege = int(input("Alege optiunea: "))

# verificam daca optiunea nu e 1 sau 2
if alege != 1 and alege != 2:
    print("Optiune gresita!")
    exit(1)

# cerem cheia 1 si citirea de la tastatura
k = int(input("Introduceti cheia 1: "))

# verificam daca cheia 1 e in afara intervalului 1-25
if k < 1 or k > 25:
    print("Cheia 1 trebuie sa fie intre 1 si 25!")
    exit(1)

# cerem cheia 2
cheie2 = input("Introduceti cheia 2: ")
# calculam lungimea cheii 2 citite
lungime_cheie2 = len(cheie2)

# verificam daca cheia 2 are cel putin 7 caractere
if lungime_cheie2 < 7:
    print("Cheia 2 trebuie sa aiba cel putin 7 caractere!")
    exit(1)

# parcurgem fiecare caracter din cheia 2 ca sa verificam daca sunt doar litere
cheie2_final = ""
for i in range(lungime_cheie2):
    # verificam daca nu e litera
    if not cheie2[i].isalpha():
        print("Cheia 2 trebuie sa contina doar litere ale alfabetului romanesc!")
        exit(1)
    # copiem litera convertita in majuscula in cheie2_final
    cheie2_final += cheie2[i].upper()

# cerem textul
text = input("Introduceti textul: ")
# calculam lungimea textului citit
lungime = len(text)

# parcurgem fiecare caracter din text si verificam daca in text este ceva inafara de litere
for i in range(lungime):
    # verificam daca nu e nici spatiu, nici litera
    if text[i] != ' ' and not text[i].isalpha():
        print("Text invalid! Sunt acceptate doar literele alfabetului romanesc si spatiile.")
        exit(1)

# initializam sirul text_final (textul dupa eliminarea spatiilor si conversia in majuscule)
text_final = ""
# parcurgem textul ca sa eliminam spatiile si sa convertim in majuscule
for i in range(lungime):
    # daca e spatiu, il sarim
    if text[i] == ' ':
        continue
    # copiem litera convertita in majuscula
    text_final += text[i].upper()

# actualizam lungimea, dupa eliminarea spatiilor
lungime = len(text_final)

# rezultatul final: textul criptat sau decriptat
rezultat = ""
# parcurgem fiecare litera din text_final pentru criptare sau decriptare
for i in range(lungime):
    # aflam valoarea numerica a literei cautand-o in alphabet_upper
    valoare = alphabet_upper.index(text_final[i])
    # aflam valoarea numerica a literei corespunzatoare din cheia 2
    # folosim restul impartirii la lungime_cheie2 ca sa reluam cheia ciclic
    valoare_cheie2 = alphabet_upper.index(cheie2_final[i % lungime_cheie2])

    # criptarea
    if alege == 1:
        # deplasam litera atat cu cheia 1, cat si cu litera corespunzatoare din cheia 2
        noua_valoare = (valoare + k + valoare_cheie2) % 31
    # decriptarea
    else:
        # adaugam 31*2 ca sa evitam rezultat negativ
        noua_valoare = (valoare - k - valoare_cheie2 + 31 * 2) % 31

    # punem litera corespunzatoare noii valori in rezultat
    rezultat += alphabet_upper[noua_valoare]

# criptarea
if alege == 1:
    print(f"\nMesajul criptat este: {rezultat}")
# decriptarea
else:
    print(f"\nMesajul decriptat este: {rezultat}")
