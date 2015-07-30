#include <unistd.h>
#include <string.h>
#include <stdio.h>

enum    ecomponent
{
        TRUE = 3,
        FALSE,
        OR,
        AND,
        XOR,
        NOR,
        NAND,
        NXOR,
        COUNTER,
        DECODER,
        RAM,
        ADDER
};

struct  link
{
        int idComponent0;
        int pinComponent0;
        int idComponent1;
        int pinComponent1;
};

struct              component
{
        enum ecomponent  type;
        int             id;
        char            name[8];
};

struct componentLibrary
{
        int id_type;
        char libraryNameAndPath [28];
};

#define LINK_NB 1
#define COMPONENT_NB 7
#define LIB_NB 3

#define LIB_FILE "componentLibrary"
#define COMPONENT_FILE "componentsFile"
#define LINK_FILE "linksFile"

int   main()
{
        struct link link_tab[LINK_NB];
        struct component component_tab[COMPONENT_NB];
        struct componentLibrary lib_tab[LIB_NB];
        FILE *link_file, *compo_file, *lib_file;

        /*
         *  INIT STRUCTURES
         */
        lib_tab[0].id_type = OR;
        strcpy(lib_tab[0].libraryNameAndPath, "dynamic_lib/libor.so");
        lib_tab[1].id_type = NAND;
        strcpy(lib_tab[1].libraryNameAndPath, "dynamic_lib/libnand.so");
        lib_tab[2].id_type = NXOR;
        strcpy(lib_tab[2].libraryNameAndPath, "dynamic_lib/libxnor.so");
        /*
         *  END OF INIT
         */

        link_file = fopen(LINK_FILE, "w+");
        compo_file = fopen(COMPONENT_FILE, "w+");
        lib_file = fopen(LIB_FILE, "w+");

        fwrite(link_tab, sizeof(struct link), LINK_NB, link_file);
        fclose(link_file);
        fwrite(component_tab, sizeof(struct component), COMPONENT_NB, compo_file);
        fclose(compo_file);
        fwrite(lib_tab, sizeof(struct componentLibrary), LIB_NB, lib_file);
        fclose(lib_file);
}
