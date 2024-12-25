#include<stdio.h>
#include <math.h>
#include <iostream>

int main() {
    int n;
    int arr[100];
    do {
        printf("----- MENU ----- \n");
        printf("1. Nhap so phan tu, gia tri cho mang\n");
        printf("2. In ra cac phan tu trong mang\n");
        printf("3. Dem so luong cac so nguyen to co trong mang\n");
        printf("4. Tim gia tri nho thu hai trong mang\n");
        printf("5. Them phan tu moi vao vi tri mong muon\n");
        printf("6. Xoa phan tu tai vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Tim kiem phan tu co trong mang\n");
        printf("9. Xoa cac phan tu trung lap trong mang\n");
        printf("10. Dao nguoc thu tu cac phan tu co trong mang\n");
        printf("11. Thoat\n");
        
        int choice;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
         system("clear");
         system("cls");
        
        switch (choice) {
            case 1:
                printf("\nNhap so luong phan tu: ");
                scanf("%d", &n);
                for(int i = 0; i < n; i++) {
                    printf("Nhap phan tu[%d]: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;
                
            case 2:
                printf("Mang hien tai la: \n");
                for(int i = 0; i < n; i++) {
                    printf("arr[%d] = %d, ", i, arr[i]);
                }
                printf("\n");
                break;
                
            case 3: {
                int dem = 0;
                printf("Cac so nguyen to co trong mang: \n");
                 for(int i = 0; i < n; i++) {
                    int num = arr[i];
                    int is_prime = 1;
                    if (num <= 1) {
                        is_prime = 0;
                    } else {
                        for (int j = 2; j <= sqrt(num); j++) {
                            if (num % j == 0) {
                                is_prime = 0;
                                break;
                            }
                        }
                    }
                    if (is_prime) {
                        printf("so nguyen to la [%d]\n", arr[i]);
                        dem++;
                    }
                }
               printf("So luong so nguyen to: (%d)\n", dem);
               break;
            }
                
            case 4: {
                if (n < 2) {
                    printf("Mang phai co tu 3 phan tu tro len!\n");
                } else {
                    int min = arr[0], min2 = arr[1];
                     if (min > min2) {
                        int temp = min;
                         min = min2;
                        min2 = temp;
                    }
                    for (int i = 2; i < n; i++) {
                        if (arr[i] < min) {
                             min2 = min;
                            min = arr[i];
                         } else if (arr[i] < min2 && arr[i] != min) {
                            min2 = arr[i];
                        }
                    }
                     printf("Gia tri nho thu hai trong mang la: %d\n", min2);
                }
                 break;
            }
                
            case 5: {
                int insert_pos, insert_value;
                 printf("Nhap vi tri muon them (1-%d): ", n + 1);
                scanf("%d", &insert_pos);
                 if (insert_pos < 1 || insert_pos > n + 1) {
                    printf("Vi tri khong hop le.\n");
                     break;
                }
                 printf("Nhap gia tri muon them: ");
                scanf("%d", &insert_value);
                 for (int i = n; i >= insert_pos; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[insert_pos - 1] = insert_value;
                 n++;                
                 break;
            }
                
            case 6: {
                int del_pos;
                 printf("Nhap vi tri muon xoa (1-%d): ", n);
                scanf("%d", &del_pos);
                if (del_pos < 1 || del_pos > n) {
                 printf("Vi tri khong hop le.\n");
                    break;
              }
                for (int i = del_pos - 1; i < n - 1; i++) {
                   arr[i] = arr[i + 1];
                }
                n--;                
               break;
            }
                
            case 7: {                            
               for(int i=1; i<n; i++){
                    int key = arr[i];
                   int j = i - 1;
                    while(j >= 0 && arr[j] > key){
                        arr[j+1] = arr[j];
                        j = j - 1;
                    }
                   arr[j+1] = key;
                }
                printf("Mang sau khi sap xep: \n");
               for(int i = 0; i < n; i++) {
                   printf("%d ", arr[i]);
               }  
                printf("\n");   
               break;
            }      
            case 8: {
               int search_value;
               printf("Nhap gia tri muon tim: ");
                scanf("%d", &search_value);
                int found = 0;
               for (int i = 0; i < n; i++) {
                   if (arr[i] == search_value) {
                       printf("Phan tu [%d] duoc tim thay tai vi tri %d.\n", search_value, i + 1);
                       found = 1;
                        break;
                    }
                }
                if (!found) {
                   printf("Phan tu [%d] khong co trong mang.\n", search_value);
                }
               break;
            }
                
            case 9: {
               for (int i = 0; i < n - 1; i++) {
                   for (int j = i + 1; j < n; j++) {
                       if (arr[i] == arr[j]) {
                            for (int k = j; k < n - 1; k++) {
                               arr[k] = arr[k + 1];
                            }
                           n--;
                           j--;
                        }
                    }
               }                                
               printf("\n");
                break;
            }
                
            case 10:
                for (int i = 0; i < n / 2; i++) {
                   int temp = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = temp;
               }
            printf("Mang sau khi dao nguoc thu tu: \n");
                for (int i = 0; i < n; i++) {
                   printf("%d ", arr[i]);
                }
               printf("\n");
                break;
               
            case 11:
             return 0;
                
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
        
    } while (1);
    
    return 0;
}
