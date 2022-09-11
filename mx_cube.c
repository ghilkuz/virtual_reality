void mx_printchar(const char c);

static void print_space(int n) {
    int horizontal_line = 2 * n;
    
    for (int i = 0; i < horizontal_line; i++) {
        mx_printchar (' ');
    }
}

static void print_vertical_line(int n, int row, int move_off) {
    int vertical_line = n;

    mx_printchar('|');
    print_space(n);
    mx_printchar('|');

    for (int i = 0; i < move_off; i++)
        if (row <= vertical_line + 1)
            mx_printchar (' ');

    if (row <= vertical_line) mx_printchar('|');
    else if (row == vertical_line + 1) mx_printchar('+');
    else if (row > vertical_line + 1) {
        for (int j = 0; j < move_off - 1; j++) { 
            mx_printchar (' ');
        }
        
        mx_printchar('/');
    }
}

static void print_horizontal_line(int n, int row) {
    int horizontal_line = 2 * n;
    int slash_num = n / 2;
    
    mx_printchar('+');
    for (int i = 0; i < horizontal_line; i++) {
        mx_printchar('-');
    }
    mx_printchar('+');

    if (row == slash_num + 1) {
        for (int j = 0; j < slash_num; j++) {
            mx_printchar(' ');
        }
        
        mx_printchar('|');
    }
}

static void print_slash(int n, int move_off) {
    mx_printchar('/');
    print_space(n);
    mx_printchar('/');
    
    for (int i = 0; i < move_off; i++) {
        mx_printchar(' ');
    }
    
    mx_printchar('|');
}

void mx_cube(int n) {
    int move_off = 0; // variable to cancel row movement
    int move_on = n / 2 + 1; // variable to move row

    if (n <= 1) return;
    for (int row = 0; row < n + n / 2 + 3; row++) {
        for (int i = 0; i < move_on; i++) mx_printchar(' ');
        if (row == 0 || row == n / 2 + 1 || row == n + n / 2 + 2)
            print_horizontal_line(n, row);
        else if (row > 0 && row < n / 2 + 1) {
            print_slash(n, move_off);
            move_off++;
        }
        else if (row > n / 2 + 1 && row < n + n / 2 + 2)
            print_vertical_line(n, row, move_off);
        
        if (row > n + 1) move_off--;
        mx_printchar('\n');
        move_on--;
    }
}

