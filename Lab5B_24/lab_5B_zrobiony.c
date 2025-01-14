#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 2401
#define MESSAGE_START "|MSG_START|"
#define MESSAGE_END "|MSG_END|"


typedef struct {
    char header[BUFFER_SIZE];
    char content[BUFFER_SIZE];
} Message;

typedef struct {
    char buffer[BUFFER_SIZE]; // Buffer for incomplete data
    size_t buffer_len;
    Message* messages;
    int count;
    int capasity;
} MessageManager;

void init_message_manager(MessageManager* manager, int initial_capasity);
void print_all_messages(MessageManager* manager);
void free_message_manager(MessageManager* manager);
void append_to_buffer(MessageManager* manager, const char* data, size_t data_len);
void clear_buffer(MessageManager* manager);
void process_buffer(MessageManager* manager);
void add_message(MessageManager* manager, const char* content);
void process_all_messages(MessageManager* manager, const char* ip_address);

// ------------------------------------------------------------------ ETAP 1 (1 pkt)

void init_message_manager(MessageManager* manager, int initial_capasity) {
    // alokacja pamięci dla wiadomości
    manager->messages = (Message*)malloc(initial_capasity * sizeof(Message));

    if (manager->messages == NULL) {
        printf("Error");
        return;
    }

    // początkowa ilość wiadomości i capasity
    manager->count = 0;
    manager->capasity = initial_capasity;
    // zerujemy bufor i ustawiamy jego początkową długość na 0
    memset(manager->buffer, 0, BUFFER_SIZE * sizeof(char));
    manager->buffer_len = 0;

    return;
}

void print_all_messages(MessageManager* manager) {
    int i;

    for (i = 0; i < manager->count; i++) {
        printf("%s\n%s\n", manager->messages[i].header, manager->messages[i].content);
    }

    return;
}

void free_message_manager(MessageManager* manager) {
    free(manager->messages);

    return;
}

// ------------------------------------------------------------------ ETAP 2 (1 pkt)


void append_to_buffer(MessageManager* manager, const char* data, size_t data_len) {
    // sprawdzamy czy bufor nie jest przepełniony
    if (manager->buffer_len + data_len >= BUFFER_SIZE) {
        printf("Error, buffer size too small");
        manager->buffer_len = 0;
        return;
    }

    // dodajemy wartość do bufora, zmieniamy jego długość oraz dodajemy '\0' na koniec
    memcpy(manager->buffer + manager->buffer_len, data, data_len);
    manager->buffer_len += data_len;
    manager->buffer[manager->buffer_len] = '\0';

    return;
}


// ------------------------------------------------------------------ ETAP 3 (1 pkt)
void clear_buffer(MessageManager* manager) {
    // zerujemy bufor i ustawiamy jego długość na 0
    memset(manager->buffer, 0, BUFFER_SIZE * sizeof(char));
    manager->buffer_len = 0;

    return;
}

// ------------------------------------------------------------------ ETAP 4 (3 pkt)
void process_buffer(MessageManager* manager) {
    int i,j;
    char* new_message;
    char* start_check;
    char* end_check;
    
    start_check = (char*)malloc(strlen(MESSAGE_START) * sizeof(char));
    end_check = (char*)malloc(strlen(MESSAGE_END) * sizeof(char));

    for (i = 0; i < manager->buffer_len - strlen(MESSAGE_START) + 1; i++) {
        // szukamy startu wiadomości
        memcpy(start_check, manager->buffer+i, strlen(MESSAGE_START));
        start_check[strlen(MESSAGE_START)] = '\0';
        
        //printf("%s\n", start_check);
        
        if (strcmp(start_check, MESSAGE_START) == 0) {
           //printf("Znaleziono start-msg: %s, i: %d\n", start_check, i);

            // szukamy końca wiadomości
            for (j = 0; i + j < manager->buffer_len - strlen(MESSAGE_END) + 1; j++) {
                memcpy(end_check, manager->buffer + i + j, strlen(MESSAGE_END));
                end_check[strlen(MESSAGE_END)] = '\0';

                if (strcmp(end_check, MESSAGE_END) == 0) {
                    //printf("Znalezion end-msg: %s, j: %d\n", end_check, j);

                    new_message = (char*)malloc((j - strlen(MESSAGE_START)) * sizeof(char));

                    memcpy(new_message, manager->buffer + i + strlen(MESSAGE_START), j - strlen(MESSAGE_START));
                    new_message[j - strlen(MESSAGE_START)] = '\0';

                    //printf("MSG: %s, LEN: %d\n", new_message, j - strlen(MESSAGE_START));

                    add_message(manager, new_message);

                    break;
                }
            }
        }
    }

    return;
}

void add_message(MessageManager* manager, const char* content) {
    Message new_message;

    strncpy_s(new_message.content, BUFFER_SIZE, content, strlen(content));
    //new_message.content[strlen(content) + 1] = '\0';

    manager->messages[manager->count] = new_message;
    manager->count++;

    printf("New message added %s \n", new_message.content);

    return;
}

// ------------------------------------------------------------------ ETAP 5 (1 pkt)

// Function to process all messages in the manager
void process_all_messages(MessageManager* manager, const char* ip_address) {
    int i;

    char* header;
    
    header = (char*)malloc((strlen("Receiver: ") + strlen(ip_address) + 1) * sizeof(char));

    if (header == NULL) {
        printf("ERROR");
        return;
    }

    snprintf(header, strlen("Receiver: ") + strlen(ip_address) + 1,"Receiver: %s", ip_address);

    header[strlen("Receiver: ") + strlen(ip_address) + 1] = '\0';

    for (i = 0; i < manager->count; i++) {
        strncpy_s(manager->messages[i].header, BUFFER_SIZE, header, strlen(header));
        //printf("%d - %s\n", i, manager->messages[i].header);
    }

    return;
}


int main() {
    char test1[] = "|MSG_START|Hello World of Strings!|MSG_END|";
    char test2[] = "|MSG_START|Normal Message|MSG_END|";
    char test2_part1[] = "|MSG_START| Split";
    char test2_part2[] = " Message|MSG_END|";
    char test3[] = "NOISE|MSG_START|With Noise|MSG_END|";
    char test4[] = "|MSG_START|Incomplete";
    const char* ip_address = "112.166.5.5";  // Example of ip address

    printf("\n// -- ETAP 1\n");
    MessageManager manager;
    init_message_manager(&manager, 100);
    printf("Manager Capasity: %zu\n", manager.capasity); // Uncomment after implementation

    printf("\n// -- ETAP 2\n");
    append_to_buffer(&manager, test1, strlen(test1));
    printf("Manager buffer: %s\n", manager.buffer); // Uncomment after implementation

    printf("\n// -- ETAP 3\n");
    clear_buffer(&manager);
    printf("Manager buffer (should be empty): %s\n", manager.buffer); // Uncomment after implementation

    printf("\n// -- ETAP 4 - Test 1\n");
    append_to_buffer(&manager, test2, strlen(test2));
    process_buffer(&manager);
    clear_buffer(&manager);

    printf("\n// -- ETAP 4 - Test 2\n");
    append_to_buffer(&manager, test2_part1, strlen(test2_part1));
    append_to_buffer(&manager, test2_part2, strlen(test2_part2));
    process_buffer(&manager);
    clear_buffer(&manager);

    printf("\n// -- ETAP 4 - Test 3\n");
    append_to_buffer(&manager, test3, strlen(test3));
    process_buffer(&manager);
    clear_buffer(&manager);

    printf("\n// -- ETAP 4 - Test 4\n");
    append_to_buffer(&manager, test4, strlen(test4));
    process_buffer(&manager);
    clear_buffer(&manager);
    printf("(Should be empty since it is incomplite)\n");

    printf("\n// -- ETAP 5\n");
    process_all_messages(&manager, ip_address);
    print_all_messages(&manager);

    free_message_manager(&manager);
}