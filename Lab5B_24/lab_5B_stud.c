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

}

void print_all_messages(MessageManager* manager) {

}

void free_message_manager(MessageManager* manager) {

}

// ------------------------------------------------------------------ ETAP 2 (1 pkt)


void append_to_buffer(MessageManager* manager, const char* data, size_t data_len) {

}


// ------------------------------------------------------------------ ETAP 3 (1 pkt)
void clear_buffer(MessageManager* manager) {

}

// ------------------------------------------------------------------ ETAP 4 (3 pkt)
void process_buffer(MessageManager* manager) {

}

void add_message(MessageManager* manager, const char* content) {

}

// ------------------------------------------------------------------ ETAP 5 (1 pkt)

// Function to process all messages in the manager
void process_all_messages(MessageManager* manager, const char* ip_address) {

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
    //printf("Manager Capasity: %zu\n", manager.capasity); // Uncomment after implementation

    printf("\n// -- ETAP 2\n");
    append_to_buffer(&manager, test1, strlen(test1));
    //printf("Manager buffer: %s\n", manager.buffer); // Uncomment after implementation

    printf("\n// -- ETAP 3\n");
    clear_buffer(&manager);
    //printf("Manager buffer (should be empty): %s\n", manager.buffer); // Uncomment after implementation

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