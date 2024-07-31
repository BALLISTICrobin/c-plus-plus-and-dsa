#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num 2
typedef struct employee_info
{
    char id[20];
    char name[20];
    int age;
    char designation[20];
    float salary;
} emp;

void addEmployee(emp *emp, int size)
{
    FILE *fp;
    fp = fopen("employees_record.txt", "w+");
    if (fp == NULL)
    {
        printf("error not found");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        fprintf(fp, "%s %s%d %s %f\n", emp[i].id, emp[i].name, emp[i].age, emp[i].designation, emp[i].salary);
    }
    fclose(fp);
}
void displayEmployees()
{
    FILE *fp;
    fp = fopen("employees_record.txt", "r+");
    if (fp == NULL)
    {
        printf("error not found");
        return;
    }
    while (!feof(fp))
    {
        char rid[20];
        char rname[20];
        int rage;
        char rdesignation[20];
        float rsalary;
        fscanf(fp, "%s %[^0-9] %d %s %f", rid, rname, &rage, rdesignation, &rsalary);
        printf("%s %s%d %s %f\n", rid, rname, rage, rdesignation, rsalary);
    }
    fclose(fp);
}
emp person;
emp *searchEmployee(char *empid)
{
    FILE *fp;
    fp = fopen("employees_record.txt", "r+");
    if (fp == NULL)
    {
        printf("error not found");
        return NULL;
    }
    while (!feof(fp))
    {

        fscanf(fp, "%s %[^0-9] %d %s %f", person.id, person.name, &person.age, person.designation, &person.salary);
        if (strcmp(empid, person.id) == 0)
        {
            return &person;
        }
    }
    fclose(fp);
    return NULL;
}
emp update[num];
void updateEmployee(emp *updatedemp){
    FILE *fp;
    fp = fopen("employees_record.txt", "r+");
    if (fp == NULL)
    {
        printf("error not found");
        return;
    }
    int i=0;
    while (!feof(fp))
    {
        char rid[20];
        char rname[20];
        int rage;
        char rdesignation[20];
        float rsalary;
    fscanf(fp, "%s %[^0-9] %d %s %f", rid, rname, &rage, rdesignation, &rsalary);
    if(strcmp(rid,updatedemp->id)==0){
        strcpy(update[i].id,updatedemp->id);
        strcpy(update[i].name,updatedemp->name);
        update[i].age = updatedemp->age;
        strcpy(update[i].designation,updatedemp->designation);
        update[i].salary = updatedemp->salary;
    }
    else{
        strcpy(update[i].id,rid);
        strcpy(update[i].name,rname);
        update[i].age = rage;
        strcpy(update[i].designation,rdesignation);
        update[i].salary = rsalary;
    }
    i++;
    }
    fclose(fp);
    
    fp = fopen("employees_record.txt", "w+");
    if (fp == NULL)
    {
        printf("error not found");
        return;
    }
    for(int i=0;i<num; i++){
        fprintf(fp,"%s %s%d %s %f\n",update[i].id,update[i].name,update[i].age,update[i].designation,update[i].salary);
    }
}
emp delete[num];
void deleteEmployee(char *deletedemp){
    FILE *fp;
    fp = fopen("employees_record.txt", "r+");
    if (fp == NULL)
    {
        printf("error not found");
        return;
    }
    int i=0;
    while (!feof(fp))
    {
        char rid[20];
        char rname[20];
        int rage;
        char rdesignation[20];
        float rsalary;
    fscanf(fp, "%s %[^0-9] %d %s %f", rid, rname, &rage, rdesignation, &rsalary);
    if(strcmp(rid,deletedemp)!=0){
        strcpy(delete[i].id,rid);
        strcpy(delete[i].name,rname);
        delete[i].age = rage;
        strcpy(delete[i].designation,rdesignation);
        delete[i].salary = rsalary;
        i++;
    }
   
    }
    fclose(fp);
    
    fp = fopen("employees_record.txt", "w+");
    if (fp == NULL)
    {
        printf("error not found");
        return;
    }
    for(int j=0;j<i; j++){
        fprintf(fp,"%s %s%d %s %f\n",delete[j].id,delete[j].name,delete[j].age,delete[j].designation,delete[j].salary);
    }
    fclose(fp);
}
 emp upemp,delemp;
int main(int argc, char const *argv[])
{
    
     
    emp *record = (emp*)malloc(num*sizeof(emp));
    printf("enter: ");
   for(int i=0; i<num; i++) {
        scanf("%s %[^0-9] %d %s %f",record[i].id,record[i].name,&record[i].age,record[i].designation,&record[i].salary);
    }
    
    addEmployee(record,num);
    displayEmployees();
    char sid[20];
    printf("\nenter the smployee id: ");
    scanf("%s", sid);
    emp *ptr = searchEmployee(sid);
    if (ptr == NULL)
        printf("not found");
    else
        printf("%s %s%d %s %f", ptr->id, ptr->name, ptr->age, ptr->designation, ptr->salary);

   
    printf("\nenter the updated employee record: ");
    
    scanf("%s %[^0-9] %d %s %f", upemp.id, upemp.name, &upemp.age, upemp.designation, &upemp.salary);
    updateEmployee(&upemp);

    printf("enter the employee record that u want to delete: ");
     scanf("%s", delemp.id);
     deleteEmployee(delemp.id);
    return 0;
}
