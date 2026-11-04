#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Taxon {
    char name[50];
    int lifespan;
    struct Taxon *parent_group;
} Taxon;


// Function to create a taxon
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


// Function to read taxon information
void read_taxon_info(const char *label, char *name_out, int *lifespan_out)
{
    printf("Enter name for %s: ", label);
    scanf(" %49[^\n]", name_out);

    printf("Enter average lifespan for %s: ", label);
    scanf("%d", lifespan_out);
}


// Main function
int main()
{
    Taxon *taxa[7];

    char name[50];
    int lifespan;

    const char *labels[7] = {
        "Family",
        "Genus 1",
        "Genus 2",
        "Species 1",
        "Species 2",
        "Species 3",
        "Species 4"
    };

    // Create seven taxon nodes
    for (int i = 0; i < 7; i++)
    {
        read_taxon_info(labels[i], name, &lifespan);

        taxa[i] = create_taxon(name, lifespan);
    }

    // Display all created nodes
    printf("\n===== TAXONOMY TREE NODES =====\n");

    for (int i = 0; i < 7; i++)
    {
        printf("\nName: %s", taxa[i]->name);
        printf("\nAverage Lifespan: %d years\n", taxa[i]->lifespan);
    }

    printf("\nAll 7 Taxon nodes created successfully!\n");

    // Free allocated memory
    for (int i = 0; i < 7; i++)
    {
        free(taxa[i]);
    }

    return 0;
}
