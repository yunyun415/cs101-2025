#include <stdio.h>

int main() {
    FILE *fp;  
    int a[3] = {0, 1, 2};
    
    char b[3] = {'A', 'B', 'C'};
 
    float c[3] = {1.1, 1.2, 1.3};

 
    fp = fopen("a.bin", "wb");
   
    fwrite(a, sizeof(int), 3, fp);
    fwrite(b, sizeof(char), 3, fp);
    fwrite(c, sizeof(float), 3, fp);
    
    fclose(fp);

    fp = fopen("a.bin", "rb");
    int read_a[3];
    char read_b[3];
    float read_c[3];

    fread(read_a, sizeof(int), 3, fp);
    fread(read_b, sizeof(char), 3, fp);
    fread(read_c, sizeof(float), 3, fp);

    for (int i = 0; i < 3; i++) {
        printf("%d ", read_a[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("%c ", read_b[i]);
    }
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf("%.6f ", read_c[i]);
    }

    fclose(fp);
    return 0;
}
