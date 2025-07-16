#include <stdio.h>
#include <string.h>

// Define a structure for food items
struct FoodItem {
    int id;
    char name[50];
    float price;
};

int main() {
    // Predefined food menu
    struct FoodItem menu[] = {
        {1, "Burger", 99.0},
        {2, "Pizza", 199.0},
        {3, "Pasta", 149.0},
        {4, "Sandwich", 79.0},
        {5, "Cold Drink", 49.0}
    };

    int n = sizeof(menu) / sizeof(menu[0]);
    int choice, quantity;
    char more;
    float total = 0.0;

    printf("===== WELCOME TO FOOD BILLING SYSTEM =====\n");

    do {
        // Display food menu
        printf("\n------ Menu ------\n");
        for (int i = 0; i < n; i++) {
            printf("%d. %s - ₹%.2f\n", menu[i].id, menu[i].name, menu[i].price);
        }

        // Get user choice
        printf("\nEnter the Item ID you want to order: ");
        scanf("%d", &choice);

        // Validate item selection
        if (choice < 1 || choice > n) {
            printf("Invalid item ID. Please try again.\n");
            continue;
        }

        // Get quantity
        printf("Enter quantity for %s: ", menu[choice - 1].name);
        scanf("%d", &quantity);

        // Calculate and add to total
        float item_total = menu[choice - 1].price * quantity;
        total += item_total;

        printf("Added to Bill: %s x %d = ₹%.2f\n", menu[choice - 1].name, quantity, item_total);

        // Ask if user wants to add more items
        printf("Do you want to order more items? (y/n): ");
        scanf(" %c", &more); // space before %c to consume leftover newline

    } while (more == 'y' || more == 'Y');

    // Print final bill
    printf("\n======= BILL SUMMARY =======\n");
    printf("Total Amount: ₹%.2f\n", total);
    printf("Thank you! Visit Again!\n");

    return 0;
}
