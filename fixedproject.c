#include <stdio.h>
#include <string.h>

#define MAX_DONORS 100
#define MAX_SIZE 50
#define USER_FILE "users.txt"

struct Donor {
    char username[MAX_SIZE];
    char password[MAX_SIZE];
    char fullName[MAX_SIZE];
    char bloodType[MAX_SIZE];
    char contactNumber[MAX_SIZE];
    int donations;
    int bloodTypeRegistered; // 0 if not registered, 1 if registered
};

struct Donor donors[MAX_DONORS];
int donorCount = 0;

void registerDonor() {
    FILE *file = fopen(USER_FILE, "a"); // Open the file in append (a) mode
    if (!file) {
        printf("Error opening users file.\n");
        return;
    }

    struct Donor newDonor;
    printf("Enter username: ");
    scanf("%s", newDonor.username);
    printf("Enter password: ");
    scanf("%s", newDonor.password);
    printf("Enter full name(No Whitespace): ");
    scanf("%s", newDonor.fullName);
    printf("Enter blood type (In Capital): ");
    scanf("%s", newDonor.bloodType);
    printf("Enter contact number: ");
    scanf("%s", newDonor.contactNumber);
    newDonor.donations = 0;
    newDonor.bloodTypeRegistered = 1; // Indicates that the blood type is registered

    donors[donorCount] = newDonor;
    donorCount++;

    fprintf(file, "%s %s %s %s %s %d %d\n", newDonor.username, newDonor.password, newDonor.fullName, newDonor.bloodType, newDonor.contactNumber, newDonor.donations, newDonor.bloodTypeRegistered);
    fclose(file);
    printf("Registration successful!\n");
}

int login() {
    char username[MAX_SIZE];
    char password[MAX_SIZE];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    FILE *file = fopen(USER_FILE, "r");
    if (!file) {
        printf("Error opening users file.\n");
        return -1;
    }

    struct Donor user;
    int index = 0;
    while (fscanf(file, "%s %s %s %s %s %d %d", user.username, user.password, user.fullName, user.bloodType, user.contactNumber, &user.donations, &user.bloodTypeRegistered) != EOF) {
        if (strcmp(username, user.username) == 0 && strcmp(password, user.password) == 0) {
            printf("Welcome Mr. %s!\n", user.fullName);
            printf("Your contact number is: %s\n", user.contactNumber);
            printf("Your blood group is: %s\n", user.bloodType);
            printf("Login successful!\n");
            fclose(file);
            printf("Login Index: %d\n", index);
            return index; // Return the index of the logged-in user
        }
        index++;
    }

    fclose(file);
    printf("Login failed. Invalid credentials.\n");
    return -1; // Invalid login
}

void changePassword(int userIndex) {
    if (userIndex == -1) {
        printf("No user is currently logged in. Please log in first.\n");
        return;
    }

    if (userIndex >= 0 && userIndex < donorCount) {
        FILE *file = fopen(USER_FILE, "r+");
        if (!file) {
            printf("Error opening users file.\n");
            return;
        }

        struct Donor user;
        int index = 0;
        while (fscanf(file, "%s %s %s %s %s %d %d", user.username, user.password, user.fullName, user.bloodType, user.contactNumber, &user.donations, &user.bloodTypeRegistered) != EOF) {
            if (index == userIndex) {
                printf("Enter new password: ");
                scanf("%s", user.password);

                fseek(file, index * (MAX_SIZE + MAX_SIZE + MAX_SIZE + MAX_SIZE + MAX_SIZE + 2 + sizeof(int) + sizeof(int)), SEEK_SET);
                fprintf(file, "%s %s %s %s %s %d %d\n", user.username, user.password, user.fullName, user.bloodType, user.contactNumber, user.donations, user.bloodTypeRegistered);
                fclose(file);
                printf("Password changed successfully!\n");
                return;
            }
            index++;
        }

        fclose(file);
        printf("Invalid user index.\n");
    } else {
        printf("Invalid user index.\n");
    }
}

void changeNumber(int userIndex) {
    if (userIndex == -1) {
        printf("No user is currently logged in. Please log in first.\n");
        return;
    }

    if (userIndex >= 0 && userIndex < donorCount) {
        FILE *file = fopen(USER_FILE, "r+");
        if (!file) {
            printf("Error opening users file.\n");
            return;
        }

        struct Donor user;
        int index = 0;
        while (fscanf(file, "%s %s %s %s %s %d %d", user.username, user.password, user.fullName, user.bloodType, user.contactNumber, &user.donations, &user.bloodTypeRegistered) != EOF) {
            if (index == userIndex) {
                printf("Enter new Contact number: ");
                scanf("%s", user.contactNumber);


                fclose(file);
                file = fopen(USER_FILE, "w");
                if (!file) {
                    printf("Error opening users file.\n");
                    return;
            }
            for (int i = 0; i < donorCount; i++) {
                    fprintf(file, "%s %s %s %s %s %d %d\n", donors[i].username, donors[i].password, donors[i].fullName, donors[i].bloodType, donors[i].contactNumber, donors[i].donations, donors[i].bloodTypeRegistered);
                }

                fclose(file);
                printf("Contact number changed successfully!\n");
                return;}
            index++;
        }

        fclose(file);
        printf("Invalid user index.\n");
    } else {
        printf("Invalid user index.\n");
    }
}


int searchBloodType() {
    char bloodType[MAX_SIZE];

    printf("Enter Blood Type (In Capital): ");
    scanf("%s", bloodType);

    FILE *file = fopen(USER_FILE, "r");
    if (!file) {
        printf("Error opening users file.\n");
        return -1;
    }

    struct Donor user;
    int index = 0;
    int found = 0; // Flag to indicate if the blood group is found

    while (fscanf(file, "%s %s %s %s %s %d %d", user.username, user.password, user.fullName, user.bloodType, user.contactNumber, &user.donations, &user.bloodTypeRegistered) != EOF) {
        if (strcmp(bloodType, user.bloodType) == 0 && user.bloodTypeRegistered == 1) {
            printf("Blood Group available!\n");
            printf("Your contact number is: %s\n", user.contactNumber);
            printf("Name is: %s\n", user.fullName);
            fclose(file);
            printf("Blood Type Index: %d\n", index);
            found = 1;
            break; // Exit the loop once a valid match is found
        }
        index++;
    }

    if (!found) {
        fclose(file);
        printf("Sorry, Blood Group not available!\n");
        return -1; // Blood group not found
    }

    return index;
}

int main() {
    int choice, donorIndex = -1;

    do {
        printf("\nMenu:\n");
        printf("1. Register as Donor\n");
        printf("2. Login\n");
        printf("3. Change Contact Number\n");
        printf("4. Change Password\n");
        printf("5. Search Blood Group\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerDonor();
                break;
            case 2: {
                donorIndex = login();
                break;
            }
            case 3:
                changeNumber(donorIndex);
                break;
            case 4:
                changePassword(donorIndex);
                break;
            case 5:
                searchBloodType();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
