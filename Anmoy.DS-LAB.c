#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
struct Node {
    int roll;
    char name[50];
    int present;
    struct Node* next;
};

struct Node* head = NULL;

void addstudent() {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode==NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    printf("Enter Roll: ");
    scanf("%d", &newNode->roll);
    printf("Enter Name: ");
    scanf(" %s", newNode->name);
    newNode->present = 0;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    }
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Student added successfully!\n");
}

struct Node* searchstudent(int roll) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->roll == roll)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void markattendance() {
    if (head == NULL) {
        printf("No students found!\n");
        return;
    }
    int roll;
    printf("Enter roll to mark attendance: ");
    scanf("%d", &roll);
    struct Node* student = searchstudent(roll);
    if (student == NULL) {
        printf("Student not found!\n");
    }
    else {
        printf("Mark Present (1) or Absent (0): ");
        scanf("%d", &student->present);
        printf("Attendance updated successfully!\n");
    }
}

int countstudents() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void displaysorted() {
    if (head == NULL) {
        printf("No students to sort!\n");
        return;
    }

    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    struct Node* arr[count];
    temp = head;
    int i = 0;
    while (temp != NULL) {
        i++;
        arr[i] = temp;
        temp = temp->next;
    }

    for (int a = 0; a < count - 1; a++) {
        for (int b = 0; b < count - a - 1; b++) {
            if (arr[b]->roll > arr[b+1]->roll) {
                struct Node* t = arr[b];
                arr[b] = arr[b+1];
                arr[b+1] = t;
            }
        }
    }

    printf("\nSorted Students (by Roll):\n");
    for (int k = 0; k <= count; k++) {
        if (arr[k]->present == 1) {
            printf("%d %s Present\n", arr[k]->roll, arr[k]->name);
        }
        else {
            printf("%d %s Absent\n", arr[k]->roll, arr[k]->name);
        }
    }
}


void displayall() {
    if (head == NULL) {
        printf("No students to display!\n");
        return;
    }

    struct Node* temp = head;
    printf("\nAll Students:\n");
    while (temp != NULL) {
        if (temp->present == 1) {
            printf("%d %s Present\n", temp->roll, temp->name);
        } else {
            printf("%d %s Absent\n", temp->roll, temp->name);
        }
        temp = temp->next;
    }
}

int main() {
    int choice;
    while (1) {
            clearScreen();
        printf("\n===== Attendance Management System =====\n");
        printf("1. Add New Student\n");
        printf("2. Mark Attendance\n");
        printf("3. Search Student by Roll\n");
        printf("4. Display All Students (Unsorted)\n");
        printf("5. Display All Students (Sorted by Roll)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            clearScreen();
            addstudent();
            break;
        case 2:
            clearScreen();
            markattendance();
            break;
        case 3: {
            clearScreen();
            int roll;
            printf("Enter roll to search: ");
            scanf("%d", &roll);

            struct Node* s = searchstudent(roll);
            if (s == NULL) {
           printf("Student not found!\n");
           }
           else {
           if (s->present == 1) {
           printf("Roll: %d, Name: %s, Attendance: Present\n", s->roll, s->name);
           }
           else {
           printf("Roll: %d, Name: %s, Attendance: Absent\n", s->roll, s->name);
            }
           }
            break;
        }
        case 4:
            clearScreen();
            displayall();
            break;
        case 5:
            clearScreen();
            displaysorted();
            break;
        case 6:
            clearScreen();
            printf("Exiting program...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
        printf("\nPress Enter to continue...");
        while(getchar()!='\n');
        getchar();
    }
    return 0;
}
