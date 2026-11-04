#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Taxon {
    char name[50];
    int lifespan;
    struct Taxon *parent_group;
} Taxon;


// Create a taxon
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


// Read taxon information
void read_taxon_info(const char *label, char *name_out, int *lifespan_out)
{
    printf("Enter name for %s: ", label);
    scanf(" %49[^\n]", name_out);

    printf("Enter average lifespan for %s: ", label);
    scanf("%d", lifespan_out);
}


// Connect child with parent
void link_parent(Taxon *child, Taxon *parent)
{
    child->parent_group = parent;
}


// Print classification hierarchy
void print_taxonomy(Taxon *species_list[], int species_count)
{
    printf("\n=== SPECIES CLASSIFICATION HIERARCHY ===\n");

    for (int i = 0; i < species_count; i++)
    {
        Taxon *species = species_list[i];
        Taxon *genus = species->parent_group;
        Taxon *family = genus->parent_group;

        printf("\n%d. SPECIES %d: %s\n", i + 1, i + 1, species->name);

        printf("   - Average Lifespan: %d years\n",
               species->lifespan);

        printf("   - Belongs to Genus: %s (Lifespan: %d yrs)\n",
               genus->name, genus->lifespan);

        printf("   - Belongs to Family: %s (Lifespan: %d yrs)\n",
               family->name, family->lifespan);
    }
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


    // Connect genera to family
    link_parent(taxa[1], taxa[0]);
    link_parent(taxa[2], taxa[0]);

    // Connect species to genera
    link_parent(taxa[3], taxa[1]);
    link_parent(taxa[4], taxa[1]);

    link_parent(taxa[5], taxa[2]);
    link_parent(taxa[6], taxa[2]);


    // Create species list
    Taxon *species_list[4] = {
        taxa[3],
        taxa[4],
        taxa[5],
        taxa[6]
    };


    // Print classification
    print_taxonomy(species_list, 4);


    // Free allocated memory
    for (int i = 0; i < 7; i++)
    {
        free(taxa[i]);
    }

    return 0;
}
