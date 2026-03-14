#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256

int device_known(char *ip) {

    FILE *file;
    char line[MAX_LINE];

    file = fopen("logs/known_devices.txt","r");

    if (file == NULL) {
        return 0;
    }

    while (fgets(line, sizeof(line), file)) {

        if (strstr(line, ip)) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void log_event(char *ip) {

    FILE *log;

    log = fopen("logs/device_log.txt","a");

    if (log != NULL) {
        fprintf(log, "New device detected: %s\n", ip);
        fclose(log);
    }
}

void trigger_arduino() {

    system("echo A > /dev/ttyACM0");

}


int main() {

    FILE *scan;
    char line[MAX_LINE];
    char ip[MAX_LINE];

    printf("Scanning network...\n");

    system("arp -a > logs/current_scan.txt");

    scan = fopen("logs/current_scan.txt","r");

    if (scan == NULL) {
        printf("Scan file error\n");
        return 1;
    }

    while (fgets(line, sizeof(line), scan)) {

sscanf(line, "%*s (%[^)])", ip);

        if (!device_known(ip)) {

            printf("Unknown device detected: %s\n", ip);

            log_event(ip);

            trigger_arduino();
        }
    }

    fclose(scan);

    printf("Scan finished\n");

    return 0;
}

