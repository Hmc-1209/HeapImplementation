#include <stdio.h>
#include <ctype.h>


int toNum(char const* arr, int len) {
    int num = 0;
    for(int i = 0;i < len;i++) num = num * 10 + ((int)arr[i] - 48);
    return num;
}


int main() {
    // Input variables
    char c;
    char arr[10000] = {};
    int length = 0;
    // Data variables
    int nodes[10000] = {};
    int index = 0;
    // While input not end
    while(1) {
        scanf("%c", &c);
        if (c == ' ' && length != 0) {
            nodes[index] = toNum(arr, length);
            index++;
            length = 0;
        } else if (isdigit(c)) {
            arr[length] = c;
            length++;
        }
        if (c == '\n') {
            if (length != 0) {
                nodes[index] = toNum(arr, length);
                index++;
            }
            break;
        }
    }


    return 0;
}
