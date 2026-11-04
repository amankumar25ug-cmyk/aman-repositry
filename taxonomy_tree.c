#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Taxon
typedef struct Taxon {
    char name[50];
    int lifespan;
    struct Taxon *parent_group;
} Taxon;

// Function declarations
Taxon* create_taxon(const char *name, int lifespan);
void read_taxon_info(Taxon *taxon, const char *type);
void link_parent(Taxon *child, Taxon *parent);
void print_taxonomy(Taxon *species_list[], int species_count);
void free_tree(Taxon *all_taxa[], int total_count);

// Create a new taxon
Taxon* create_taxon(const char *name, int lifespan)
{
    Taxon *new_taxon = malloc(sizeof(Taxon));

    if (new_taxon == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    snprintf(new_taxon->name, sizeof(new_taxon->name), "%s", name);
    new_taxon->lifespan = lifespan;
    new_taxon->parent_group = NULL;

    return new_taxon;
}

// Read information about a taxon
void read_taxon_info(Taxon *taxon, const char *type)
{
    printf("\nEnter name for %s: ", type);
    scanf(" %49[^\n]", taxon->name);

    printf("Enter lifespan: ");
    scanf("%d", &taxon->lifespan);
}

// Connect a child to its parent
void link_parent(Taxon *child, Taxon *parent)
{
    child->parent_group = parent;
}

// Print the classification
void print_taxonomy(Taxon *species_list[], int species_count)
{
    printf("\n========== TAXONOMY CLASSIFICATION ==========\n");

    for (int i = 0; i < species_count; i++) {

        Taxon *species = species_list[i];
        Taxon *genus = species->parent_group;
        Taxon *family = genus->parent_group;

        printf("\nSpecies: %s\n", species->name);
        printf("Genus: %s\n", genus->name);
        printf("Family: %s\n", family->name);
    }

    printf("\n============================================\n");
}

// Free all allocated memory
void free_tree(Taxon *all_taxa[], int total_count)
{
    for (int i = 0; i < total_count; i++) {
        free(all_taxa[i]);
    }
}

// Main function
int main()
{
    Taxon *taxa[7];

    // Create family
    taxa[0] = create_taxon("", 0);
    read_taxon_info(taxa[0], "Family");

    // Create two genera
    taxa[1] = create_taxon("", 0);
    read_taxon_info(taxa[1], "Genus 1");

    taxa[2] = create_taxon("", 0);
    read_taxon_info(taxa[2], "Genus 2");

    // Create four species
    taxa[3] = create_taxon("", 0);
    read_taxon_info(taxa[3], "Species 1");

    taxa[4] = create_taxon("", 0);
    read_taxon_info(taxa[4], "Species 2");

    taxa[5] = create_taxon("", 0);
    read_taxon_info(taxa[5], "Species 3");

    taxa[6] = create_taxon("", 0);
    read_taxon_info(taxa[6], "Species 4");

    // Link genera to family
    link_parent(taxa[1], taxa[0]);
    link_parent(taxa[2], taxa[0]);

    // Link species to genera
    link_parent(taxa[3], taxa[1]);
    link_parent(taxa[4], taxa[1]);

    link_parent(taxa[5], taxa[2]);
    link_parent(taxa[6], taxa[2]);

    // Store species in an array
    Taxon *species_list[4] = {
        taxa[3], taxa[4], taxa[5], taxa[6]
    };

    // Print classification
    print_taxonomy(species_list, 4);

    // Free allocated memory
    free_tree(taxa, 7);

    return 0;
}
