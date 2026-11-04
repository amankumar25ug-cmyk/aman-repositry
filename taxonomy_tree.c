

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Taxon {
    char name[50];
    int lifespan;
    struct Taxon *parent_group;
} Taxon;

Taxon* create_taxon(const char *name, int lifespan)
{
    Taxon *new_taxon = malloc(sizeof(Taxon));

    if (new_taxon == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    strcpy(new_taxon->name, name);
    new_taxon->lifespan = lifespan;
    new_taxon->parent_group = NULL;

    return new_taxon;
}
