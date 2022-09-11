void mx_printchar(char c);

// puts char in line
// return next empty cell index
static int put_char(char *line, int index, char c){
    line[index] = c;
    return index + 1;
}

//fill line with chars except front spaces
static void fill_chars(char *line, int line_num, int start, int n){
    int index = put_char(line, start, '/');
    int s1_count = line_num == 0 ? 0 : 1 + (line_num - 1) * 2;

    for(int i = 0; i < s1_count; i++)
        index = put_char(line, index, line_num == n - 1 ? '_' : ' ');
    index = put_char(line, index, '\\');
    
    if(line_num != 0){
        if(line_num + 1 <= n / 2){
            for(int i = 0; i < line_num; i++)
                index = put_char(line, index, ' ');
            index = put_char(line, index, '\\');
        }else{
            while(index !=  n * 2 - 1)
                index  = put_char(line, index, ' ');
            index = put_char(line, index, '|');
        }
    }
    put_char(line, index, '\0');
}

//this function fill array with all required front spaces
//and return index of next empty cell of the array

static int fill_spaces(char *line, int line_number, int n){
    for(int i = 0; i < n - line_number - 1; i++){
        line[i] = ' ';
    }
    return n - line_number - 1;
}

void mx_pyramid(int n){
    if(n <= 1 || n % 2 != 0)
        return;

    char line [n * 2 + 1];

    for(int line_n = 0; line_n < n; line_n++){
       int next =  fill_spaces(line, line_n, n);
       
       fill_chars(line, line_n, next, n);
        
       for(int i = 0; line[i] != '\0'; i++)
           mx_printchar(line[i]);

        mx_printchar('\n');
    }
}

