#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

int main(int argc, char *argv[])
{
  int fd = -1;
  long int key = 0;
  uint8_t keys[KEY_MAX/8 + 1];  

  /* parse arguments */
  if (argc < 2) {
    printf("Usage: %s <input_device> [key]\n", argv[0]);
    printf("       returns: 0 is key is pressed, 1 otherwise\n");
    printf("                if no key is passed, returns 0 if any key is pressed\n");
    return 1;
  }
  if (argc == 3) {
    key = strtol(argv[2], NULL, 0);
  }
  
  /* open input device */
  fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("Error opening input device");
    return 1;
  }

  /* read current status */
  memset(keys, 0, sizeof(keys));
  ioctl(fd, EVIOCGKEY(sizeof(keys)), keys);
  /* close input device */
  close(fd);

  /* check if the given key was pressed */
  int key_pressed = 0;
  if (key>0) {
    key_pressed = !!(keys[key/8] & (1<<(key % 8)));
  }
  else {
    for (int i = 0; i < sizeof(keys) && !key_pressed; i++) {
        key_pressed |= (keys[i] != 0);
    }
  }
  
  return (key_pressed ? 0 : 1);
}