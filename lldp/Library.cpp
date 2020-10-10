#include "Header.h"

boolean ListEmpty(List L) { return (First(L) == Nil && Last(L) == Nil); }

void CreateList(List* L) {
    address P;

    P = (address)malloc(sizeof(ElmtList));

    if (P != Nil) {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
}

address Alokasi(infotype X) {
    address P;

    P = (address)malloc(sizeof(ElmtList));

    if (P != Nil) {
        Info(P) = X;
        Prev(P) = Nil;
        Next(P) = Nil;
    }

    return P;
}

void Dealokasi(address* P) { free(*P); }

boolean FSearch(List L, address P) {
    address Pp = First(L);
    boolean Found = false;

    do {
        if (Pp == P) {
            Found = true;
            break;
        } else
            Pp = Next(Pp);
    } while (Pp != Nil);

    return Found;
}

address Search(List L, infotype X) {
    address P;

    if (ListEmpty(L))
        P = Nil;
    else {
        P = First(L);

        do {
            if (Info(P) == X)
                break;
            else
                P = Next(P);
        } while (P != Nil);
    }

    return P;
}
    
void InsVFirst(List* L, infotype X) {
    address P;

    P = Alokasi(X);

    if (P != Nil)
        InsertFirst(&(*L), P);
}

void InsVLast(List* L, infotype X) {
    address P;

    P = Alokasi(X);

    if (P != Nil)
        InsertLast(&(*L), P);
}

void DelVFirst(List* L, infotype* X) {
    address P;

    DelFirst(&(*L), &P);
    (*X) = Info(P);
    Dealokasi(&P);
}

void DelVLast(List* L, infotype* X) {
    address P;

    if (First(*L) == Last(*L))
        DelVFirst(&(*L), &(*X));
    else {
        DelLast(&(*L), &P);
        (*X) = Info(P);
        Dealokasi(&P);
    }
}

void InsertFirst(List* L, address P) {
    if (ListEmpty(*L))
        Last(*L) = P;
    else {
        Last(*L) = First(*L);

        while (Next(Last(*L)) != Nil)
            Last(*L) = Next(Last(*L));

        Next(P) = First(*L);
        Prev(First(*L)) = P;
    }
    First(*L) = P;
}

void InsertAfter(List* L, address P, address Prec) {
    Prev(P) = Prec;
    Next(P) = Next(Prec);
    Prev(Next(Prec)) = P;
    Next(Prec) = P;
}

void InsertLast(List* L, address P) {
    if (ListEmpty(*L))
        InsertFirst(&(*L), P);
    else {
        Last(*L) = First(*L);

        while (Next(Last(*L)) != Nil)
            Last(*L) = Next(Last(*L));

        Prev(P) = Last(*L);
        Next(Last(*L)) = P;
        Last(*L) = P;
    }
}

void DelFirst(List* L, address* P) {
    (*P) = First(*L);

    if (First(*L) == Last(*L)) {
        First(*L) = Nil;
        Last(*L) = Nil;
    } else {
        Prev(Next(First(*L))) = Nil;
        First(*L) = Next(First(*L));
    }

    Prev(*P) = Nil;
    Next(*P) = Nil;
}

void DelAfter(List* L, address* Pdel, address Prec) {
    (*Pdel) = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Prev(Next(Prec)) = Prec;
    Prev(*Pdel) = Nil;
    Next(*Pdel) = Nil;
}

void DelLast(List* L, address* P) {
    if (First(*L) == Last(*L))
        DelFirst(&(*L), &(*P));
    else {
        (*P) = Last(*L);
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
        Prev(*P) = Nil;
    }
}

void PrintInfo(List L) {
    address P;

    if (ListEmpty(L))
        printf("List kosong.");
    else {
        P = First(L);
        do {
            printf("|%d| ", Info(P));
            P = Next(P);
        } while (P != Nil);
    }
}