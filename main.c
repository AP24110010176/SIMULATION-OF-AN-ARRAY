#include <stdio.h>

#define MAX 100

int arr[MAX];
int n = 0;   // current size of array

void display() {
    if (n == 0) {
        printf("\nArray is empty!\n");
        return;
    }

    printf("\nArray Elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertAtPos() {
    int pos, value;

    printf("\nEnter position to insert (0 to %d): ", n);
    scanf("%d", &pos);
    printf("Enter value: ");
    scanf("%d", &value);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return;
    }

    printf("\n--- Simulation of Insertion ---\n");
    printf("Shifting elements to the right...\n");

    for (int i = n - 1; i >= pos; i--) {
        printf("Moving arr[%d] → arr[%d]\n", i, i + 1);
        arr[i + 1] = arr[i];
    }

    arr[pos] = value;
    n++;

    printf("Inserted %d at position %d.\n", value, pos);
}

void deleteAtPos() {
    int pos;

    printf("\nEnter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid position!\n");
        return;
    }

    printf("\n--- Simulation of Deletion ---\n");
    printf("Deleting element %d at index %d.\n", arr[pos], pos);
    printf("Shifting elements to the left...\n");

    for (int i = pos; i < n - 1; i++) {
        printf("Moving arr[%d] → arr[%d]\n", i + 1, i);
        arr[i] = arr[i + 1];
    }

    n--;
    printf("Deletion completed.\n");
}

void search() {
    int key, found = 0;
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    printf("\n--- Simulation of Linear Search ---\n");

    for (int i = 0; i < n; i++) {
        printf("Comparing key with arr[%d] = %d\n", i, arr[i]);
        if (arr[i] == key) {
            printf("Element found at index %d.\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found in the array.\n");
}

void update() {
    int index, value;

    printf("\nEnter index to update (0 to %d): ", n - 1);
    scanf("%d", &index);

    if (index < 0 || index >= n) {
        printf("Invalid index!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    printf("\nUpdating arr[%d] from %d → %d\n", index, arr[index], value);

    arr[index] = value;

    printf("Update successful.\n");
}

int main() {
    int choice;

    printf("Enter initial size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do {
        printf("\n========= ARRAY SIMULATION MENU =========\n");
        printf("1. Display\n");
        printf("2. Insert at Position\n");
        printf("3. Delete from Position\n");
        printf("4. Search\n");
        printf("5. Update\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: display(); break;
            case 2: insertAtPos(); break;
            case 3: deleteAtPos(); break;
            case 4: search(); break;
            case 5: update(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}
