#include "projekt_head.h"
#include "projekt_functions.h"

int main() {
    struct F1 drivers[MAX_DRIVERS];
    int numDrivers = 0;
    int option;
    do {
        printMenu();
        option = readInt();
        switch (option) {
            case 1:
                addDriver(drivers, &numDrivers);
                break;
            case 2:
                editDriver(drivers, numDrivers);
                break;
            case 3:
                deleteDriver(drivers, &numDrivers);
                break;
            case 4:
                sortDrivers(drivers, numDrivers);
                printf("\nKierowcy zostali posortowani!\n");
                break;
            case 5:
                printDrivers(drivers, numDrivers);
                break;
            case 6:
                zapiszDoPliku(drivers, numDrivers);
                break;
            case 7:
                wczytajZPliku(drivers, &numDrivers);
                break;
            case 8:
                utworzPlik();
                break;
            case 9:
                usunPlik();
                break;
            case 0:
                break;
            default:
                printf("Nieznana opcja!\n");
                break;
        }
    } while (option != 0);
    return 0;
}
