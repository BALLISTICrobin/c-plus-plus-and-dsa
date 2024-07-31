#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct employee
{
    char employeeID[20];
    char name[15];
    int age;
    char designation[15];
    float salary;
} employee;
employee comp;
void addEmployee(employee *epl)
{
    FILE *fp;
    fp = fopen("employee.txt", "w");
    if (fp == NULL)
    {
        printf("error");
    }
    fprintf(fp, "%s %s %d %s %f", epl->employeeID, epl->name, epl->age, epl->designation, epl->salary);
    fclose(fp);
}

void displayEmployee(){
    FILE *fp;
    fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("error");
    }
    employee person;
    while(!feof(fp)){
    fscanf(fp,"%s %s %d %s %f",person.employeeID,person.name,&person.age,person.designation,&person.salary);
    printf("%s %s %d %s %f",person.employeeID,person.name,person.age,person.designation,person.salary);
    }
    fclose(fp);
}

employee * searchEmployee(char *id){
    FILE *fp;
    fp = fopen("employee.txt", "r");
    if (fp == NULL)
    {
        printf("error");
    }
    int count =0;
    while(!feof(fp)){
        
        fscanf(fp,"%s %s %d %s %f",comp.employeeID,comp.name,&comp.age,comp.designation,&comp.salary);
        if(strcmp(comp.employeeID,id)==0){
            
            count++;
            break;
        }
        
    }
    if(count==1)
    return &comp;
    else
    return NULL;
    fclose(fp);

} 

void updateEmployee(employee *updatedEmp){
     FILE *fp;
    fp = fopen("employee.txt", "r+");
    if (fp == NULL)
    {
        printf("error");
    }
    while(!feof(fp)){
      fscanf(fp,"%s %s %d %s %f",comp.employeeID,comp.name,&comp.age,comp.designation,&comp.salary);
      
        if(strcmp(comp.employeeID,updatedEmp->employeeID)==0){
            fclose(fp);
            FILE *fpt;
           fpt = fopen("employee.txt", "w");
            fprintf(fpt, "%s %s %d %s %f", updatedEmp->employeeID, updatedEmp->name, updatedEmp->age, updatedEmp->designation, updatedEmp->salary);
            fclose(fpt);
        }  
        
    }
    
}

int main(int argc, char const *argv[])
{
    employee emp;
    /*printf("enter: ");
    scanf("%s", emp.employeeID);
    scanf("%s", emp.name);
    scanf("%d", &emp.age);
    scanf("%s", emp.designation);
    scanf("%f", &emp.salary);

    addEmployee(&emp);*/
    displayEmployee();
    char id[20];
    printf("enter the id to find a person: ");
    scanf("%s",id);
    employee* ptr = searchEmployee(id);
    if(ptr!=NULL)
    printf("%s %s %d %s %f",ptr->employeeID, ptr->name, ptr->age, ptr->designation, ptr->salary);
    else
    printf("not found");
    
    printf("enter updated info based on id: ");
    scanf("%s", emp.employeeID);
    scanf("%s", emp.name);
    scanf("%d", &emp.age);
    scanf("%s", emp.designation);
    scanf("%f", &emp.salary);
    updateEmployee(&emp);
    displayEmployee();

    return 0;
}
