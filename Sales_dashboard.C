#include <stdio.h>
#include <string.h>

struct Sale {
    char date[20];
    char product[30];
    char category[20];
    char region[20];
    int orders;
    float revenue;
};

int main() {
    struct Sale sales[5] = {
        {"2026-01-01", "Laptop", "Electronics", "North", 20, 400000},
        {"2026-01-02", "Mobile", "Electronics", "South", 30, 300000},
        {"2026-01-03", "Shoes", "Fashion", "East", 25, 250000},
        {"2026-01-04", "Watch", "Fashion", "West", 15, 350000},
        {"2026-01-05", "Headphone", "Electronics", "North", 15, 260000}
    };

    int n = 5, choice;
    float totalRev = 0;
    int totalOrders = 0;

    for(int i=0; i<n; i++){
        totalRev += sales[i].revenue;
        totalOrders += sales[i].orders;
    }

    do {
        printf("\n******* SALES DASHBOARD *******\n");
        printf("1. View Dashboard\n2. View Sales Data\n3. Revenue Trend\n4. Top Selling Product\n5. Region-wise Sales\n6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice==1){
            printf("\nTotal Revenue: Rs. %.2f\nTotal Orders: %d\nAOV: Rs. %.2f\n", totalRev, totalOrders, totalRev/totalOrders);
        }
        else if(choice==2){
            for(int i=0;i<n;i++)
                printf("%s | %s | %s | %d | %.2f\n", sales[i].date, sales[i].product, sales[i].region, sales[i].orders, sales[i].revenue);
        }
        else if(choice==3){
            for(int i=0;i<n;i++)
                printf("%s : %.2f\n", sales[i].date, sales[i].revenue);
        }
    } while(choice!=6);

    return 0;
}
