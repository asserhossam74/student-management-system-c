/*=========================================================================================================
 *  c_project
 *  Created on: Aug 10, 2024
 *  Author: Asser Hossam El-Hosary
 *  Description:Student Management System
 *  =======================================================================================================*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*Structure to hold student information including ID, name, age, and GPA.*/
typedef struct student
{
	int id;
	char name[50];
	int age;
	float gpa;
}student;

/* Defines a linked list node that holds a 'student' and a pointer to the next node*/
typedef struct node
{
	student data;
    struct node*next;     /* Points to the next node in the linked list*/
}node;

// Initializes the head pointer of the linked list to NULL, indicating that the list is empty.
node*head=NULL;;

void add_student(const student *const ptr);  /* function prototype to add student*/
void display_students(void);                /* function prototype to display students*/
void search_student_by_id(int id);         /* function prototype to search students */
void update_student(int id);              /* function prototype to update student data*/
void delete_student(int id);             /* function prototype to delete student*/
float calculate_average_gpa(void);      /* function prototype to calculate average GPA*/
void search_highest_gpa(void);         /* function prototype to search student with highest GPA*/


int main()
{
	setvbuf (stdout, NULL, _IONBF,0 );
	setvbuf (stderr, NULL, _IONBF,0 );

	// Defines an enumeration for menu options, mapping each choice to a unique integer value
	enum{add_a_student=1,Display_all_students,Search_student_by_ID,update_student_information
		 ,delete_a_student,Calculate_Average_gpa,Find_student_with_highest_gpa,exit};
	int input,id;
	float average_gpa;
	student s;      /* Declares a variable 's' of type 'student' to store student data*/

	printf("\n---------------------------------------------------------\n");
	printf("\t welcome to student  management system\n");

	while(1)
	{

		printf("---------------------------------------------------------\n");
		printf("1 - add student\n");
		printf("2 - display all students\n");
		printf("3 - search student by id\n");
		printf("4 - update student information\n");
		printf("5 - delete student\n");
		printf("6 - average GPA\n");
		printf("7 - student with highest GPA\n");
		printf("8 - exit\n");
		printf("enter choice number:\n");
		scanf("%d",&input);
		printf("\n---------------------------------------------------------\n");
		switch(input)
		{
		case(add_a_student):
		        printf("enter students data\n");
	         	printf("\n---------------------------------------------------------\n");
		        printf("enter students id\n");
		        scanf("%d",&s.id);
		        getchar();         /* Consume the newline character left in the input buffer by scanf */
		        printf("enter students name\n");
		        gets(s.name);
		        printf("enter students age\n");
		        scanf("%d",&s.age);
		        printf("enter students GPA\n");
		        scanf("%f",&s.gpa);
     			add_student(&s);
		        break;
		case(Display_all_students):
				display_students();
		        break;
		case(Search_student_by_ID):
				printf("Please enter the student ID you want to search for: \n");
		        scanf("%d",&id);
				search_student_by_id(id);
				break;
		case(update_student_information):
		        printf("Please enter ID: for student you want to update his information\n  ");
		        scanf("%d",&id);
				update_student(id);
				break;
		case(delete_a_student):
				printf("Please enter ID: for student you want to delete his information\n");
		        scanf("%d",&id);
		        delete_student(id);
		        break;
		case(Calculate_Average_gpa):
		        average_gpa=calculate_average_gpa();
				printf(" the average GPA of all students=%f \n",average_gpa);
				break;
		case(Find_student_with_highest_gpa):
		        search_highest_gpa();
		        break;
		case(exit):
				printf(" you are leaving student management system \n ");
		        return 0;
		default: /*if user enter input that not in the options*/
			    printf("invalid input\n");
			    break;
		}

	}
}

void add_student(const student *const ptr) /* Adds a new student node to the linked list */
{
	node*current=NULL;          /* Declares a pointer to traverse the linked list*/

	// Allocates memory for a new node and assigns its address to 'link'
	node*link=(node*)malloc(sizeof(node));

    if (link == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    link->data=*ptr;           /*Copies student data from the pointer 'ptr' to the new node*/
	link->next=NULL;          /*set next pointer to null*/

	if(head==NULL)           /* check if the list is empty*/
	{
		head=link;          /* if list is empty point head to 1st node of the list*/
		return;
	}

	current=head;
	while(current!=NULL)  /* `loop to all list to check if id is reversed or not */
	{
		if(current->data.id==link->data.id)
		{
			printf("id:%d already exist\n",link->data.id);
			printf("enter student with another id\n");
			free(link);
			return;
		}
			current=current->next;
	}

	current=head;       /* Initialize the 'current' pointer to the head of the linked list */

	/* Traverse the list until the last node (where 'next' is NULL) */
	while(current->next!=NULL)
	{
		current=current->next;  /* Move 'current' to the next node in the list */
	}
	current->next=link;        /* Set the 'next' pointer of the last node to the new node 'link' */

}

void display_students(void)      /*function to print the list*/
{
	int student_number=1;     /* variable to print the number of student in the list*/
	node*ptr=NULL;           /* Declares a pointer to traverse the linked list*/
	if(NULL==head)
	{
		printf("There are no students currently available in the system\n");
		return;
	}
	ptr=head;
	while(ptr!=NULL)      /*loop all the list to print student data*/
	{
		printf("data of student number %d \n ",student_number);
		printf("id:%d\t\t",ptr->data.id);
		printf("name:%s\t\t",ptr->data.name);
		printf("age:=%d\t\t",ptr->data.age);
		printf("GPA:%f\n",ptr->data.gpa);
		ptr=ptr->next;
		student_number++;
	}
}
void search_student_by_id(int id)  /* function to search student in the list by passing id */
{
	node*ptr=NULL;                /* Declares a pointer to traverse the linked list*/
	if(NULL==head)
	{
		printf("There are no students currently available in the system\n");
		return;
	}
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data.id==id)
		{
			printf("id:%d\t\t",ptr->data.id);
			printf("name:%s\t\t",ptr->data.name);
			printf("age:=%d\t\t",ptr->data.age);
			printf("GPA:%f\t",ptr->data.gpa);
			return;
		}
		ptr=ptr->next;
	}
	printf("No student exists with this ID\n");
}

void update_student(int id)   /* function to update student information by passing id */
{
	node*ptr=NULL;           /* Declares a pointer to traverse the linked list*/
	if(NULL==head)
	{
		printf("There are no students currently available in the system\n");
		return;
	}
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->data.id==id) /* Check if the ID of the current student matches the provided ID */
		{
			printf("enter new student data\n");  /* tacking new student data from the user*/
			printf("\n---------------------------------------------------------\n");
			printf("enter students id\n");
			scanf("%d",&ptr->data.id);
			getchar();
			printf("enter students name\n");
			gets(ptr->data.name);
			printf("enter students age\n");
			scanf("%d",&ptr->data.age);
			printf("enter students GPA\n");
			scanf("%f",&ptr->data.gpa);
			printf(" student data update successfully \n");
			return;
		}
		ptr=ptr->next;
	}
	printf("No student exists with this ID\n");
}

void delete_student(int id)     /* function to delete student node from the list by passing id */
{
	node*current=NULL;          /* Pointer to traverse the linked list */
	node*prev=NULL;            /* Pointer to keep track of the previous node */
	node*deleted_node=NULL;   /* Pointer to store the node that will be deleted */
	if(head==NULL)
	{
		printf("There are no students currently available in the system\n");
		return;
	}
	if(head->data.id==id)    /* check if the student we want to delete at first node or not */
	{
		deleted_node=head;        /* The node to be deleted is the current head */
		head=head->next;         /* Move the head pointer to the next node */
		free(deleted_node);     /* Free the memory of the deleted node */
		printf("student with ID:%d removed successfully\n",id);
		return;
	}
	current=head->next;            /* Start from the second node */
	prev=head;
	while(current!=NULL)          /* loop to all the list*/
	{
		if(current->data.id==id)
		{
			deleted_node=current;             /* Store the node to be deleted */
			prev->next=current->next;
			free(deleted_node);              /* Free the memory of the deleted node */
			printf("student with ID:%d removed successfully\n",id);
			return;
		}
		prev=current;
		current=current->next;
	}
	printf("No student exists with this ID\n");

}

float calculate_average_gpa(void)   /* function to calculate average GPA of all students in the list */
{
	float average;
	float sum=0;               /*variable to put sum of all GPA in it*/
	int counter=0;            /*variable to count how many student in the list*/
	node*ptr=NULL;           /* Declares a pointer to traverse the linked list*/
	if(NULL==head)
	{
		average=0.0;     /* if the list is empty it will return average=0.0 */
		return average;
	}
	ptr=head;
	while(ptr!=NULL)
	{
		sum+=ptr->data.gpa;
		ptr=ptr->next;
		counter++;
	}
	average=sum/counter;       /*average=(total GPA/total numbers of student)*/
	return average;
}

void search_highest_gpa(void)   /* Function to search student with highest GPA */
{
	float max;         /* Variable to store the maximum GPA found during the traversal of the linked list */
	node*ptr=NULL;    /* Declares a pointer to traverse the linked list*/
	if(NULL==head)
	{
		printf("There are no students currently available in the system\n");
		return;
	}
	ptr=head;
	max=ptr->data.gpa;
	ptr=ptr->next;
	while(ptr!=NULL)  /* loop to all list to find the max GPA for all students in the list*/
	{
		if(max<ptr->data.gpa)
		{
			max=ptr->data.gpa;
		}
		ptr=ptr->next;
	}
	ptr=head;
	while(ptr!=NULL)    /* loop to print all student with highest GPA*/
	{
		if(max==ptr->data.gpa)
		{
			printf("data of student with highest GPA\n");
			printf("id:%d\t\t",ptr->data.id);
			printf("name:%s\t\t",ptr->data.name);
			printf("age:=%d\t\t",ptr->data.age);
			printf("GPA:%f\t\t",ptr->data.gpa);
		}
		ptr=ptr->next;
	}


}
