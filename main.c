#include <stdio.h>
#include <string.h>

#define MAX 100

struct Produkt {
    int id;
    char name[50];
    int bestand;
};

struct Produkt lager[MAX];
int anzahl = 0;

// Produkt hinzufügen
void produktHinzufuegen() {
    printf("Produkt ID: ");
    scanf("%d", &lager[anzahl].id);

    printf("Produktname: ");
    scanf("%s", lager[anzahl].name);

    printf("Bestand: ");
    scanf("%d", &lager[anzahl].bestand);

    anzahl++;
    printf("Produkt erfolgreich hinzugefuegt!\n");  
}

// Produkte anzeigen
void produkteAnzeigen() {
    int i;

    if (anzahl == 0) {
        printf("Keine Produkte vorhanden.\n");
        return;
    }

    for (i = 0; i < anzahl; i++) {
        printf("ID: %d | Name: %s | Bestand: %d\n",
               lager[i].id,
               lager[i].name,
               lager[i].bestand);
    }
}

// Bestand ändern
void bestandAendern() {
    int id, i, neu;

    printf("Produkt ID eingeben: ");
    scanf("%d", &id);

    for (i = 0; i < anzahl; i++) {
        if (lager[i].id == id) {
            printf("Neuer Bestand: ");
            scanf("%d", &neu);
            lager[i].bestand = neu;
            printf("Bestand aktualisiert!\n");
            return;
        }
    }

    printf("Produkt nicht gefunden.\n");
}

// Produkt suchen
void produktSuchen() {
    int id, i;

    printf("Produkt ID suchen: ");
    scanf("%d", &id);

    for (i = 0; i < anzahl; i++) {
        if (lager[i].id == id) {
            printf("Gefunden: %s | Bestand: %d\n",
                   lager[i].name,
                   lager[i].bestand);
            return;
        }
    }

    printf("Produkt nicht gefunden.\n");
}

// Niedrigen Bestand anzeigen
void niedrigerBestand() {
    int i;

    for (i = 0; i < anzahl; i++) {
        if (lager[i].bestand < 5) {
            printf("%s hat niedrigen Bestand: %d\n",
                   lager[i].name,
                   lager[i].bestand);
        }
    }
}

int main() {
    int wahl;

    do {
        printf("\n--- Lagerverwaltung ---\n");
        printf("1. Produkt hinzufuegen\n");
        printf("2. Produkte anzeigen\n");
        printf("3. Bestand aendern\n");
        printf("4. Produkt suchen\n");
        printf("5. Niedrigen Bestand anzeigen\n");
        printf("6. Beenden\n");
        printf("Auswahl: ");
        scanf("%d", &wahl);

        switch (wahl) {
            case 1: produktHinzufuegen(); break;
            case 2: produkteAnzeigen(); break;
            case 3: bestandAendern(); break;
            case 4: produktSuchen(); break;
            case 5: niedrigerBestand(); break;
            case 6: printf("Programm beendet.\n"); break;
            default: printf("Ungueltige Auswahl.\n");
        }

    } while (wahl != 6);

    return 0;
}