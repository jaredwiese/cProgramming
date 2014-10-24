#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Introducing structures; in C is similar to a row of a database table or a class in an OOP language

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// struct Person is now a compound data type
struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person)); //memory allocate to ask the OS to give us a pice of raw memory
    // ensure we have a valid piece of memory back from malloc
    assert(who != NULL);
    // initialize each field, use strdup to duplicate the string for the name
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

// If we have a create, then we always need a destroy function
void Person_destroy(struct Person *who)
{
    assert(who != NULL);
    // return the memory we got with malloc and strdup
    free(who->name);
    free(who);
}

// prints out the people
void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

// create four people
int main(int argc, char *argv[])
{
    // make four people structures
    struct Person *ironman = Person_create(
            "Ironman", 44, 74, 220);

    struct Person *hulk = Person_create(
            "The Hulk", 44, 69, 128);
            
    struct Person *cptamerica = Person_create(
            "Captain America", 96, 74, 240);

    struct Person *thor = Person_create(
            "Thor", 1000, 78, 640);

    // print them out and where they are in memory
    printf("Ironman is at memory location %p:\n", ironman);
    Person_print(ironman);

    printf("The Hulk is at memory location %p:\n", hulk);
    Person_print(hulk);
    
    printf("Captain America is at memory location %p:\n", cptamerica);
    Person_print(cptamerica);

    printf("Thor is at memory location %p:\n", thor);
    Person_print(thor);

    // make Ironman and Hulk 'transform' and update the stats
    ironman->height += 4;
    ironman->weight += 30;
    Person_print(ironman);

    hulk->height += 23;
    hulk->weight += 1000;
    Person_print(hulk);

    // destroy them all so we clean up; if we don't do this we get a 'memory leak'
    Person_destroy(ironman);
    Person_destroy(hulk);
    Person_destroy(cptamerica);
    Person_destroy(thor);

    return 0;
}
