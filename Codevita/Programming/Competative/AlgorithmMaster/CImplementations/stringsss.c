char removeSpaces(char *str) {
	if (str == '\0')
		return '\0';
	int len = 0;
	for (len = 0; str[len]; len++);
	for (int i = 0; i < len; i++){
		if (str[i] == ' '){
			for (int j = i; j < len - 1; j++){
				str[j] = str[j + 1];
			}
			i--;
			len--;
		}
	}
	str[len] = '\0';
	return '\0';
}

void reverseIT(char *str, int l, int r){
	for (int i = l, j = r; i<j; i++, j--){
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

void str_words_in_rev(char *input, int len){
	if (input == '\0')
		return;
	reverseIT(input, 0, len - 1);
	int st = 0, ed;
	for (int i = 0; i<len; i++){
		if (input[i] == ' '){
			ed = i;
			reverseIT(input, st, ed - 1);
			st = i + 1;
		}
	}
	reverseIT(input, st, len - 1);
	return;
}
