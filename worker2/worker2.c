#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8888

/* Hàm tính toán */
int do_work(int *data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

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

/* Hàm worker */
int main(int argc,char **argv) {
    int sock, work[9], result = 0;
    struct sockaddr_in server_addr;

    /* Tạo socket */
    sock = socket(AF_INET, SOCK_STREAM, 0);

    /* Khởi tạo địa chỉ server */
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    /* Kết nối đến server */
    connect(sock, (struct sockaddr *)&server_addr,
            sizeof(server_addr));

    /* Nhận công việc từ master */
    for (int i = 0; i < 3; i++) {
        recv_data(sock, work, sizeof(int) * 9);
        result += do_work(work, 9);
    }

    /* Gửi kết quả về cho master */
    send_data(sock, &result, sizeof(int));

    return 0;
}
