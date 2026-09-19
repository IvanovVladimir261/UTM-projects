# https://onlinegdb.com/JZM3c0WUq

# tabelul cu literele mari
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

# cerem cheia si citirea de la tastatura
k = int(input("Introduceti cheia: "))

# verificam daca cheia e in afara intervalului
if k < 1 or k > 25:
    print("Cheia trebuie sa fie intre 1 si 25!")
    exit(1)

# cerem textul
text = input("Introduceti textul: ")
# calculam lungimea textului citit
lungime = len(text)

# parcurgem fiecare caracter din text si verificam daca in text este ceva inafara de litere
for i in range(lungime):
    # verificam daca nu e nici spatiu, nici litera
    if text[i] != " " and not text[i].isalpha():
        print(
            "Text invalid! Sunt acceptate doar literele alfabetului romanesc si spatiile."
        )
        exit(1)

# initializam sirul text_final (textul dupa eliminarea spatiilor si conversia in majuscule)
text_final = ""
# parcurgem textul ca sa eliminam spatiile si sa convertim in majuscule
for i in range(lungime):
    # daca e spatiu, il sarim
    if text[i] == " ":
        continue
    # transformam litera convertita in majuscula
    text_final += text[i].upper()

# actualizam lungimea, dupa eliminarea spatiilor
lungime = len(text_final)

# rezultatul final
rezultat = ""
# parcurgem fiecare litera din text_final pentru criptare sau decriptare
for i in range(lungime):
    # aflam valoarea numerica a literei cautand-o in alphabet_upper
    valoare = alphabet_upper.index(text_final[i])
    # aici va fi pusa valoarea rezultata dupa deplasare
    noua_valoare = None

    # criptarea
    if alege == 1:
        noua_valoare = (valoare + k) % 31
    # decriptarea
    else:
        # adaugam 31 ca sa evitam rezultat negativ
        noua_valoare = (valoare - k + 31) % 31

    # punem litera corespunzatoare noii valori in rezultat
    rezultat += alphabet_upper[noua_valoare]

# criptarea
if alege == 1:
    print(f"\nMesajul criptat este: {rezultat}")
# decriptarea
else:
    print(f"\nMesajul decriptat este: {rezultat}")
