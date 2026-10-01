#include <stdio.h>
#include <string.h>

#define MAX_PHIEU 50

int main() {
    char maPhieu[MAX_PHIEU][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[MAX_PHIEU] = {0, 3, 5};
    int soLuong = 3;
    
    int luaChon;

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luaChon);

        while (getchar() != '\n');

        switch (luaChon) {
            case 1: {
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    int tienPhat = ngayQuaHan[i] * 5000;
                    printf("%-3d | %-8s | %d ngay          | %d VND\n", 
                           i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
                }

                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;
            }

            case 2: {
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                } else {
                    printf("\nNhap Ma phieu muon moi: ");
                    scanf("%s", maPhieu[soLuong]);

                    ngayQuaHan[soLuong] = 0;
                    soLuong++;

                    printf("Them phieu muon thanh cong!\n");
                }
                break;
            }

            case 3: {
                char maTimKiem[20];
                int timThay = -1;

                printf("\nNhap ma phieu muon can cap nhat: ");
                scanf("%s", maTimKiem);

                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTimKiem) == 0) {
                        timThay = i;
                        break;
                    }
                }

                if (timThay != -1) {
                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maTimKiem, timThay);
                    
                    int ngayMoi;
                    printf("Nhap so ngay qua han moi: ");
                    scanf("%d", &ngayMoi);

                    if (ngayMoi < 0) {
                        printf("Loi: So ngay qua han khong duoc la so am!\n");
                    } else {
                        ngayQuaHan[timThay] = ngayMoi;
                        printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", maTimKiem, ngayMoi);
                    }
                } else {
                    printf("Loi: Khong tim thay ma phieu muon '%s' trong he thong!\n", maTimKiem);
                }
                break;
            }

            case 0: {
                printf("\nCam on ban da su dung phan mem. Tam biet!\n");
                break;
            }

            default:
                printf("\nLua chon khong hop le! Vui long chon tu 0 den 3.\n");
                break;
        }

    } while (luaChon != 0);

    return 0;
}
