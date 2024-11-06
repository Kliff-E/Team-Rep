#include <stdio.h>

typedef struct {

    int age;

    float height;

    char name[16];

} person_t;

person_t get_person(void);


int main()
{
    person_t person[2];

    for(int i = 0; i < 2; i++)
    {
        person[i] = get_person();
    }

for(int i = 0; i < 2; i++)
    {
    
    printf("Your form\n Age: %d\nHeight: %f\n Name: %s\n", person[i].age, person[i].height, person[i].name);

    }

    return 0;
}

    person_t get_person(void)
{
    person_t s;

    printf("Your age\n");
    scanf("%d", &s.age);
    printf("Your Height\n");
    scanf("%f", &s.height);
    printf("Your name\n");
    scanf("%s", (s.name));

    return s;


}