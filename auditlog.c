#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define FILE_NAME "audit.log"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage:\n");
    printf("./auditlog --add \"message\"\n");
    printf("./auditlog --view\n");
    return 1;
  }

  if (strcmp(argv[1], "--add") == 0) {
    if (argc < 3) {
      printf("Please provide a message.\n");
      return 1;
    }

    int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd < 0) {
      printf("Unable to open log file.\n");
      return 1;
    }

    write(fd, argv[2], strlen(argv[2]));
    write(fd, "\n", 1);

    close(fd);
  }

  else if (strcmp(argv[1], "--view") == 0) {
    int fd = open(FILE_NAME, O_RDONLY);

    if (fd < 0) {
      printf("No log file found.\n");
      return 1;
    }

    char ch;
    int line = 1;
    int newLine = 1;
    char buffer[20];

    while (read(fd, &ch, 1) > 0) {
      if (newLine) {
        int len = sprintf(buffer, "%d: ", line++);
        write(1, buffer, len);
        newLine = 0;
      }

      write(1, &ch, 1);

      if (ch == '\n') {
        newLine = 1;
      }
    }

    close(fd);
  }

  else {
    printf("Invalid command.\n");
  }

  return 0;
}
