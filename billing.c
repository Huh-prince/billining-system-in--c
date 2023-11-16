// -------------------------- Jai Shree Ram ...... ----------------------------------------

#include <stdio.h>
#include <stdlib.h>

// ---------------- Function to display the available items ----------------------------------
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Meal - $5.00\n");
    printf("2. Drink - $1.50\n");
    printf("3. Snack - $2.00\n");
    // baki or kisi chij ka man kare to khud daal lo 
}

// ------------------- Function to calculate the total price of selected items -------------------------
float calculateTotalPrice(int* selectedItems, int numItems) {
    float totalPrice = 0.0;
    int i;
    for (i = 0; i < numItems; i++) {
        switch(selectedItems[i]) {
            case 1:
                totalPrice += 5.0;
                break;
            case 2:
                totalPrice += 1.5;
                break;
            case 3:
                totalPrice += 2.0;
                break;
            default:
                printf("Invalid item selection\n");
        }
    }
    return totalPrice;
    // itna bill kese aa sakta hai bhai mene to bas thoda sa hi khaya hai 
}

// ------------------------------ Function to apply discount -------------------------------------
float applyDiscount(float totalPrice) {
    float discount = 0.0;
    if (totalPrice > 5.0) {
        discount = 0.1 * totalPrice;
    }
    return totalPrice - discount;
    // discount to banta hai bhai 
}

// ------------------------ Function to display payment options and process payment ---------------------
void processPayment(float totalPrice) {
    int paymentOption;
    printf("Total price: $%.2f\n", totalPrice);
    printf("Select payment option:\n");
    printf("1. Cash\n");
    printf("2. Card\n");
    printf("3. UPI\n");
    printf("4. Online Payments\n");
    scanf("%d", &paymentOption);
    switch(paymentOption) {
        case 1:
            printf("Please pay $%.2f in cash\n", totalPrice);
            break;
        case 2:
            printf("Processing card payment of $%.2f...\n", totalPrice);
            break;
        case 3:
            printf("Please pay %.2f rupee on the UPI id paying@bank\n", totalPrice);
            break;
        case 4:
            printf("Processing online payment of $%.2f...\n", totalPrice);
            break;
        default:
            printf("Invalid payment option\n");
    }
    // pesa bhot hai tere bhai ke pass 
}




// ------------------------- main function (baki functions ko bulane ke liye) -------------------------------

int main() {
    int selectedItems[10];
    int numItems = 0;
    int menuItem;
    char response;
    FILE *fp;
    fp = fopen("billing.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Display menu and ask user to select items..........
    displayMenu();
    do {
        printf("Enter item number to add to order: ");
        scanf("%d", &menuItem);
        selectedItems[numItems] = menuItem;
        numItems++;
        printf("Add another item? (y/n): ");
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');
    // jaldi kar bhai kal subha panvel nikalna hai 

    // Calculate total price and apply discount if available........................
    float totalPrice = calculateTotalPrice(selectedItems, numItems);
    printf("Total price (before discount): $%.2f\n", totalPrice);
    totalPrice = applyDiscount(totalPrice);
    printf("Total price (after discount): $%.2f\n", totalPrice);
    // bahi ko discount bhi mangta hai 

    // Process payment
    processPayment(totalPrice);
    fprintf(fp, "Total Bill is $%.2f\n", totalPrice);
    fclose(fp);
    return 0;
    // kharcha ho gya aaj to 
}
