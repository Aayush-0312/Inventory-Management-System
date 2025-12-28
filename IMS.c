#include <stdio.h>
#include <string.h>

// Define a structure for an inventory item
typedef struct
 {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;


// Function declaration
void addItem(Item inventory[], int *count);

void updateItem(Item inventory[], int count);

void deleteItem(Item inventory[], int *count);

void displayInventory(const Item inventory[], int count);

int findItemIndexById(const Item inventory[], int count, int id);



int main()
{
    Item inventory[100]; // Array to store inventory items
    int count = 0;
    int choice;

    while (1)
        {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Delete Item\n");
        printf("4. View Inventory\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                addItem(inventory, &count);
                break;
            case 2:
                updateItem(inventory, count);
                break;
            case 3:
                deleteItem(inventory, &count);
                break;
            case 4:
                displayInventory(inventory, count);
                break;
            case 5:
                printf("Exiting the program.\n Thanks for using this system. ");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}



// Function to add an item to the inventory
void addItem(Item inventory[], int *count)
{
    printf("Enter item ID: ");
    scanf("%d", &inventory[*count].id);

    printf("Enter item name: ");
    scanf(" %s", inventory[*count].name);

    printf("Enter item quantity: ");
    scanf("%d", &inventory[*count].quantity);

    printf("Enter item price: ");
    scanf("%f", &inventory[*count].price);

    (*count)++;
    printf("Item added successfully!\n");

}



// Function to update an existing item in the inventory
void updateItem(Item inventory[], int count)
 {
    int id, index;

    printf("Enter the ID of the item to update: ");
    scanf("%d", &id);

    index = findItemIndexById(inventory, count, id);

    if (index == -1)
        {
        printf("Item with ID %d not found.\n", id);
        return;
    }

    printf("Enter new name: ");
    scanf(" %[^\n]", inventory[index].name);

    printf("Enter new quantity: ");
    scanf("%d", &inventory[index].quantity);

    printf("Enter new price: ");
    scanf("%f", &inventory[index].price);

    printf("Item updated successfully!\n");
}



// Function to delete an item from the inventory
void deleteItem(Item inventory[], int *count)
 {
    int id, index;

    printf("Enter the ID of the item to delete: ");
    scanf("%d", &id);

    index = findItemIndexById(inventory, *count, id);

    if (index == -1)
        {
        printf("Item with ID %d not found.\n", id);
        return;
    }

    // Shift items to remove the target item
    for (int i = index; i < (*count) - 1; i++)
        {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;

    printf("Item deleted successfully!\n");
}



// Function to display the inventory
void displayInventory(const Item inventory[], int count)
{
    if (count == 0)
        {
        printf("Inventory is empty.\n");
        return;
        }

    printf("\nInventory List:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("-------------------------------------------\n");
    for (int i = 0; i < count; i++)
        {
        printf("%d\t%-15s\t%d\t\t%.2f\n",
               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
}

// Helper function to find the index of an item by ID
int findItemIndexById(const Item inventory[], int count, int id)
 {
    for (int i = 0; i < count; i++)
        {
        if (inventory[i].id == id)
         {
            return i;
         }
        }
    return -1; // Item not found
}
