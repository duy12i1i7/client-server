#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_WORKERS 3
#define PORT 8888

/* Hàm gửi dữ liệu qua socket */
void send_data(int sock, void *data, size_t size) {
    size_t sent = 0;
    while (sent < size) {
        sent += send(sock, data + sent, size - sent, 0);
    }
}

/* Hàm nhận dữ liệu qua socket */
void recv_data(int sock, void *data, size_t size) {
    size_t received = 0;
    while (received < size) {
        received += recv(sock, data + received, size - received, 0);
    }
}

/* Hàm master */
int main(int argc,char **argv) {
    int server_sock, client_sock[NUM_WORKERS], matrix[9][9], result;
    struct sockaddr_in server_addr;
    int total_sum = 0;

    /* Đọc ma trận từ file */
    FILE *file = fopen("matrix.txt", "r");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }
    fclose(file);

    /* Tạo socket */
    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    /* Khởi tạo địa chỉ server */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    /* Gán địa chỉ cho socket */
    bind(server_sock, (struct sockaddr *)&server_addr,
         sizeof(server_addr));

    /* Lắng nghe kết nối từ client */
    printf("Listening client machine ...\n");
    listen(server_sock, NUM_WORKERS);

    /* Chấp nhận kết nối từ client */
    for (int i = 0; i < NUM_WORKERS; i++) {
        client_sock[i] = accept(server_sock, NULL, NULL);
        printf("Client %d connected\n", i+1);
    }

    /* Gửi công việc cho các worker */
    for (int i = 0; i < NUM_WORKERS; i++) {
        send_data(client_sock[i], matrix[i * 3], sizeof(int) * 9 * 3);
        printf("Sent work to client %d\n", i+1);
    }

    /* Nhận kết quả từ các worker */
    for (int i = 0; i < NUM_WORKERS; i++) {
        recv_data(client_sock[i], &result, sizeof(int));
        printf("Received result from client %d is: %d\n", i+1, result);
        total_sum += result;
        close(client_sock[i]);
    }

    /* In ra kết quả cuối cùng */
    printf("Total sum: %d\n", total_sum);

    return 0;
}
