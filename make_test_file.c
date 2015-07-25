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
#define COMPONENT_NB 1
#define LIB_NB 1

#define LIB_FILE "componentLibrairy"
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
        link_tab[0].idComponent0 = 12;
        link_tab[0].pinComponent0 = 56;
        link_tab[0].idComponent1 = 56;
        link_tab[0].pinComponent1 = 78;

        component_tab[0].type = TRUE;
        component_tab[0].id = 45;
        strcat(component_tab[0].name, "yes");

        lib_tab[0].id_type = 67;
        strcat(lib_tab[0].libraryNameAndPath, "libtest.so");
        /*
         *  END OF INIT
         */

        link_file = fopen(LINK_FILE, "w+");
        compo_file = fopen(COMPONENT_FILE, "w+");
        lib_file = fopen(LIB_FILE, "w+");

        fwrite(link_tab, sizeof(struct link), LINK_NB, link_file);
        fclose(link_file);
        fwrite(compo_file, sizeof(struct component), COMPONENT_NB, compo_file);
        fclose(compo_file);
        fwrite(lib_file, sizeof(struct componentLibrary), LIB_NB, lib_file);
        fclose(lib_file);
}
